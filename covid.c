#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct people
{
char name[50];
char area[50];
char symptoms[10];
int  dd[10],mm[10],yy[10];
float temp;
float hbpm;
float spo2lvl;
float coughrate;
int scount;
};
int choice1(struct people* ,int,FILE *,int); //Function to determine number of people ill on a given day
void choice2(struct people* ,int,FILE *,int); //Function to determine number of people ill in an area within a range of dates and to predict severity
void choice3(struct people* ,int,FILE *,int); //Function to determine probability of a person having COVID-19 based on sensor readings
void choice4(); //Variable Reference Guide
void choice5(struct people* ,int,FILE *,int);// Function to get the details of all users

int main() //Main function  
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############     COVID-19 MANAGEMENT USING WEARABLE SENSORS    ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\n");
    printf("\n\t\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t\t=                 WELCOME                   =");
    printf("\n\t\t\t\t\t=                   TO                      =");
    printf("\n\t\t\t\t\t=                 COVID-19                  =");
    printf("\n\t\t\t\t\t=               SURVEILLANCE                =");
    printf("\n\t\t\t\t\t=                 SYSTEM                    =");
    printf("\n\t\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    
    int nofpersons,i,choice,a;
    int date1,temp;
    char enter[5];
    int j,j1,flag,flag1,flag2=0;
    int size;
    FILE *fp; //Declaring file pointer
    fp=fopen("New","a+"); //Opening file for reading and appending
    if(fp==NULL)
    {
        printf("File can't open\n");
    }
    fseek(fp,0,SEEK_END); //Sets file position of the stream to a given offset
    size=ftell(fp); //Returns current position of file pointer in a stream
    do{
        temp=0;
        printf("\n\nPlease enter the number of people whose data has to be retrieved from the device:\n"); //Input number of device-users
        scanf("%d",&nofpersons);
        if(nofpersons<=0)
        {
          printf("INVALID VALUE FOR NUMBER OF PERSONS!PLEASE ENTER AGAIN\n");
          temp =1;
        }

}while( temp==1);

    struct people p1[nofpersons]; //Creating struct variable for array of structures
    int scount[nofpersons];
    for(i=0;i<nofpersons;i++)
    {  
    do{
            j=0;
            flag=0;
            printf("\n");
            printf("Please enter the name of person %d :\n",i+1); //Input user name
            scanf(" %[^\n]",p1[i].name);
            while(p1[i].name[j]!='\0')
            {
                if(isalpha(p1[i].name[j])==0 && p1[i].name[j]!=32)
                {
                printf("INVALID NAME(ONLY ALPHABETS ALLOWED!)PLEASE ENTER AGAIN\n");
                    flag=1;
                    break;
                }
                j++;
            }
          }while(flag==1);
       
        do{
            j1=0;
            flag1=0;
            printf("Please enter the area of person %d :\n",i+1); //Input user geographical area
            scanf(" %[^\n]",p1[i].area);
            while(p1[i].area[j1]!='\0')
           {
            if(isalpha(p1[i].area[j1])==0 && p1[i].area[j1]!=32)
                {
                    printf("INVALID AREA(ONLY ALPHABETS ALLOWED!),PLEASE ENTER AGAIN\n");
                    flag1=1;
                    break;
                }
                j1++;
           }
        }while(flag1==1);
       
        do{
           flag2=0;
        printf("Please enter date (DD/MM/YYYY format):\n"); //Input date
        scanf("%d/%d/%d",&*p1[i].dd,&*p1[i].mm,&*p1[i].yy);
    if(*p1[i].yy>=1900 && *p1[i].yy<=9999)
    {
        if(*p1[i].mm>=1 && *p1[i].mm<=12)
        {
            if((*p1[i].dd>=1 && *p1[i].dd<=31) && (*p1[i].mm==1 || *p1[i].mm==3 || *p1[i].mm==5 || *p1[i].mm==7 || *p1[i].mm==8 || *p1[i].mm==10 || *p1[i].mm==12))
                printf("Date is valid.\n");
            else if((*p1[i].dd>=1 && *p1[i].dd<=30) && (*p1[i].mm==4 || *p1[i].mm==6 || *p1[i].mm==9 || *p1[i].mm==11))
                printf("Date is valid.\n");
            else if((*p1[i].dd>=1 && *p1[i].dd<=28) && (*p1[i].mm==2))
                printf("Date is valid.\n");
            else if(*p1[i].dd==29 && *p1[i].mm==2 && (*p1[i].yy %400==0 ||(*p1[i].yy %4==0 && *p1[i].yy %100!=0)))
                printf("Date is valid. Continue.\n");
            else
            {
            printf("INVALID DATE,PLEASE ENTER AGAIN\n");
            flag2=1;
            }  
        }
        else
        {
        printf("INVALID MONTH,PLEASE ENTER AGAIN\n");
            flag2=1;
        }
    }
    else
    {
    printf("INVALID YEAR,PLEASE ENTER AGAIN\n");
        flag2=1;
    }
}while(flag2==1);
    do{
        printf("Please enter the temperature(in °C) of person %d :(Ideal body temperature: 37°C)\n",i+1); 
        scanf("%f",&p1[i].temp); //Input user temperature
        if(p1[i].temp<0)
        {
          printf("INVALID VALUE FOR TEMPERATURE(ENTER POSITIVE VALUES)!PLEASE ENTER AGAIN\n");
        }
        }while(p1[i].temp<0);  
        do
        {
        printf("Please enter the oxygen/SpO2 level for person %d : (Ideal spO2lvl: > 90)\n",i+1); 
        scanf("%f",&p1[i].spo2lvl); //Input user oxygen level
        if(p1[i].spo2lvl<0)
        {
        printf("INVALID VALUE FOR OXYGEN LEVEL(ENTER POSITIVE VALUES)!PLEASE ENTER AGAIN\n");
        }
        }while(p1[i].spo2lvl<0);
    do{
        printf("Please enter the heart beats per minute(hbpm) of person %d : (Ideal hbpm: 72)\n",i+1); 
        scanf("%f",&p1[i].hbpm); //Input user hbpm
        if(p1[i].hbpm<0)
        {
        printf("INVALID VALUE FOR HEART BEATS PER MINUTE(ENTER POSITIVE VALUES)!PLEASE ENTER AGAIN\n");
        }
        }while(p1[i].hbpm<0);
    do{
        printf("Please enter the measure of cough(in dB)of person  %d :(Ideal: 70 dB)\n",i+1);
        scanf("%f",&p1[i].coughrate); //Input user cough rate
        if(p1[i].coughrate<0)
        {
        printf("INVALID VALUE FOR COUGH RATE(ENTER POSITIVE VALUES)!PLEASE ENTER AGAIN\n");
        }
        }while(p1[i].coughrate<0);
   
    do{
        flag=0;
        printf("Please enter Yes if you have any symptoms:\n");
        scanf("%s",p1[i].symptoms); //Input user symptoms
        if(strcmp(p1[i].symptoms,"yes")==0 || strcmp(p1[i].symptoms,"Yes")==0 || strcmp(p1[i].symptoms,"YES")==0 || strcmp(p1[i].symptoms,"No")==0 || strcmp(p1[i].symptoms,"NO")==0 || strcmp(p1[i].symptoms,"no")==0)
        {
            flag=1;
        }
    }while(flag!=1);
    if(strcmp(p1[i].symptoms,"yes")==0 ||strcmp(p1[i].symptoms,"YES")==0 || strcmp(p1[i].symptoms,"Yes")==0)
    {
    do{
      printf("Please enter the number of symptoms:\n");
   scanf("%d",&p1[i].scount);
   if(p1[i].scount<0)
   {
   printf("INVALID VALUE FOR NUMBER OF SYMPTOMS (ENTER POSITIVE VALUES) PLEASE ENTER AGAIN\n");
    }
}while(p1[i].scount<0);
   
}
else
{
p1[i].scount=0;
}    

}
fwrite(p1,sizeof(p1),1,fp); //Writes data specified by the pointer into the file
fseek(fp,0,SEEK_END); //Moves file pointer position to the end of file
size=ftell(fp); //Gives current position of the file pointer
fclose(fp); //Close file
do{
    printf("\n");
   printf("Please input choice (1-5): ");
   printf("\nEnter 1: To find the number of persons with high temperature on a particular day\nEnter 2: To find the number of people ill in an area and predict the severity of the disease\nEnter 3: To find the probability of a person of having COVID-19\nEnter 4: Variable Reference Manual\nEnter 5: To get details of all users\nEnter 6: To exit\n");
   scanf("%d",&choice); //Input user choice(1-5)
   switch(choice)
   {
    case 1:
        a=choice1( p1,nofpersons,fp,size); //Choice1 function call  //avantika
        printf("%d",a);
        break;
    case 2:
        choice2(p1,nofpersons,fp,size); //Choice2 function call     //charitha
        break;
    case 3:
        choice3(p1,nofpersons,fp,size); //Choice3 function call     //sanjay
        break;
   case 4:
        choice4(); //Choice4 function call                          //adithi 
        break;
    case 5:
        choice5(p1,nofpersons,fp,size);//choice5 function call      //sherwin
        break;
    case 6:
        printf("User manual created by : \n20303-ADITHI BALAJI\n20309-AVANTIKA BALAJI\n20311-CHARITHA UPPALAPATI\n20354-SANJAY BALAJI\n20358-SHERWIN AKSHAY\nTHANK YOU FOR CHOOSING OUR APPLICATION :)"); //Exit Application
        return 0;
        break;
    default:
        printf("INVALID CHOICE:");
}
printf("\n\nPlease enter yes if you want to continue else press any key:\n");
        scanf("%s", enter);
}while(strcmp(enter,"yes")==0||strcmp(enter,"YES")==0);
printf("User manual created by : \n20303-ADITHI BALAJI\n20309-AVANTIKA BALAJI\n20311-CHARITHA UPPALAPATI\n20354-SANJAY BALAJI\n20358-SHERWIN AKSHAY\nTHANK YOU FOR CHOOSING OUR APPLICATION :)"); //Exit Application

return 0;
}

int choice1(struct people* p1,int nofpersons1,FILE *fp,int size) //Choice1 function definition and passing arguments
{
int i,tcount=0;
    int dd1,mm1,yy1;
    int flag3;
    int size1;
    size1=size/sizeof(p1[0]); //Determine size of file
    struct people p2[size1]; //Creating struct variable of size of the file
    fp=fopen("New","r"); //Open file using read mode
    fread(&p2,sizeof(p2),1,fp); //Reads data from a file
    int flag2;
    do{
        flag2=0;
        printf("Please enter a DATE to find the number of people with high temperature:\n"); 
        scanf("%d/%d/%d",&dd1,&mm1,&yy1); //Input date
    if(yy1>=1900 && yy1<=9999)
    {
        if(mm1>=1 && mm1<=12)
        {
            if((dd1>=1 && dd1<=31) && (mm1==1 || mm1==3 || mm1==5 || mm1==7 || mm1==8 || mm1==10 || mm1==12))
                printf("Date is valid.\n");
            else if((dd1>=1 && dd1<=30) && (mm1==4 || mm1==6 || mm1==9 || mm1==11))
                printf("Date is valid.\n");
            else if((dd1>=1 && dd1<=28) && (mm1==2))
                printf("Date is valid.\n");
            else if(dd1==29 && mm1==2 && (yy1 %400==0 ||(yy1 %4==0 && yy1 %100!=0)))
                printf("Date is valid. Continue.\n");
            else
            {
            printf("INVALID DATE,PLEASE ENTER AGAIN\n");
            flag2=1;
        }  
        }
        else
        {
        printf("INVALID MONTH,PLEASE ENTER AGAIN\n");
            flag2=1;
        }
    }
    else
    {
    printf("INVALID YEAR,PLEASE ENTER AGAIN\n");
        flag2=1;
    }
}while(flag2==1);
   
for(i=0;i<size1;i++)
{
        if(((*p2[i].dd)==dd1) && (*p2[i].mm==mm1) && (*p2[i].yy==yy1)) //Comparing user input date to date stored in file
        {
            if(p2[i].temp>37 || p2[i].temp<28)
            {
                tcount++;
            }
        }
}
printf("Number of people with high temperature on %d/%d/%d: ",dd1,mm1,yy1);

return tcount; //Return count of people ill
fclose(fp); //Close file
}
void choice2(struct people* p1,int nofpersons1,FILE *fp,int size) //Choice2 function definition and passing arguments
{
    int m,icount,n,x,sd,sm,sy,ed,em,ey,nofpersons,flag2,flag1,j1,i;
    icount = 0;
    int illscounter[10]; //Keeps count of ill people
    char place[50];
    int mv,yv;
    int size1;
    size1=size/sizeof(p1[0]); //Determine size of file
    struct people p2[size1]; //Creating struct variable of size of the file
    fp=fopen("New","r"); //Open file using read mode
    fread(&p2,sizeof(p2),1,fp); //Reads data from a file
    do{
        j1=0;
        flag1=0;
        printf("Please enter your AREA of residence: \n"); 
        scanf(" %[^\n]",&*place); //Input geographical area
        while(place[j1]!='\0')
        {
            if(isalpha(place[j1])==0 && place[j1]!=32)
            {
                printf("INVALID AREA(ONLY ALPHABETS ALLOWED!),PLEASE ENTER AGAIN\n");
                flag1=1;
                break;
            }
                j1++;
           }
        }while(flag1==1);
    do{
    flag2=0;
    mv=0;
    printf("Enter START date: \n" ); 
    scanf("%d/%d/%d",&sd,&sm,&sy); //Input start date
    if(sy>=1900 && sy<=9999)
    {
        if(sm>=1 && sm<=12)
        {
            if((sd>=1 && sd<=31) && (sm==1 || sm==3 || sm==5 || sm==7 || sm==8 || sm==10 || sm==12))
            {  
                printf("Date is valid.\n");
                mv=31;
            }
            else if((sm>=1 && sm<=30) && (sm==4 || sm==6 || sm==9 || sm==11))
            {    
                printf("Date is valid.\n");
                mv=30;
            }
            else if((sd>=1 && sd<=28) && (sm==2))
            {    
                printf("Date is valid.\n");
                mv=28;
            }
            else if(sd==29 && sm==2 && (sy %400==0 ||(sy %4==0 && sy %100!=0)))
            {    
                printf("Date is valid. Continue.\n");
                mv=29;
            }
            else
            {
            printf("INVALID DATE,PLEASE ENTER AGAIN\n");
            flag2=1;
            }     
        }
        else
        {
        printf("INVALID MONTH,PLEASE ENTER AGAIN\n");
            flag2=1;
        }
    }
    else
    {
    printf("INVALID YEAR,PLEASE ENTER AGAIN\n");
        flag2=1;
    }
}while(flag2==1);
   
    do{
    printf("Enter END date: \n");
    scanf("%d/%d/%d", &ed,&em,&ey); //Input end date
    if(sm==em)
    {
        mv=0;
    }
    if(ey>=1900 && ey<=9999)
    {
        if(em>=1 && em<=12)
        {
            if((ed>=1 && ed<=31) && (em==1 || em==3 || em==5 || em==7 || em==8 || em==10 || em==12))
            {    
                printf("Date is valid.\n");
                ed=ed+mv;
            }
            else if((em>=1 && em<=30) && (em==4 || em==6 || em==9 || em==11))
            {    
                printf("Date is valid.\n");
                ed=ed+mv;
            }
            else if((ed>=1 && ed<=28) && (em==2))
            {  
                printf("Date is valid.\n");
                ed=ed+mv;
            }
            else if(ed==29 && em==2 && (ey %400==0 ||(ey %4==0 && ey %100!=0)))
            {    
                printf("Date is valid. Continue.\n");
                ed=ed+mv;
            }
            else
            {
            printf("INVALID DATE,PLEASE ENTER AGAIN\n");
            flag2=1;
            }    
        }
        else
        {
        printf("INVALID MONTH,PLEASE ENTER AGAIN\n");
            flag2=1;
        }
    }
    else
    {
    printf("INVALID YEAR,PLEASE ENTER AGAIN\n");
        flag2=1;
    }
}while(flag2==1);
    if(sm>em)
    {
        em=em+12;
    }

    if(sd<=ed && sm<=em && sy<=ey)
   {
     for (m = sd; m <= ed; m++)
    {
        for (n = 0; n <= size1 - 1; n++)
        {
            if(m>mv)
            {
                if (strcmp(p2[n].area,place)==0 && *p2[n].dd == (m-mv)) //Compare place and date entered
                {
                    if (p2[n].temp > 37 && p2[n].spo2lvl < 90) //Checks condition for illness
                    {
                        icount = icount + 1; //Counter incremented
                    }
                }
            }
            else
            {
                if (strcmp(p2[n].area,place)==0 && *p2[n].dd == m)
                {
                    if (p2[n].temp > 37 && p2[n].spo2lvl < 90)
                    {
                        icount = icount + 1;
                    }
                }
            }
        }
        illscounter[m - sd] = icount; //Counter variable
        icount = 0;
    }
   }
    for (x = sd; x <= ed; x++)
    {
        if(x>mv)
        {
            if(sy<ey)
            {
                printf("The number of people ILL on day %d/%d/%d are %d \n",x-mv,em-12,ey,illscounter[x-sd]);
            }
            else
            {
                printf("The number of people ILL on day %d/%d/%d are %d \n",x-mv,em,sy,illscounter[x-sd]);
            }
        }
        else
        {
            printf("The number of people ILL on day %d/%d/%d are %d \n",x,sm,sy,illscounter[x-sd]);
        }
    }    
    for (x = 0; x <= ed-sd- 1; x++)
    {
        if (illscounter[x] < illscounter[x+1])
        {
            if(sd+x>mv)
            {
                printf("From days %d to %d  the severity of the disease increased\n",sd+x-mv,sd+x+1-mv); //Predicts severity if it has increased or not
            }
            else
            {
                if(sd+x+1>mv)
                {
                    printf("From days %d to %d  the severity of the disease increased\n",sd+x,sd+x+1-mv);
                }
                else
                {
                    printf("From days %d to %d  the severity of the disease increased\n",sd+x,sd+x+1);
                }
            }
        }
        else
        {
            if(sd+x>mv)
            {
                printf("From days %d to %d  the severity of the disease was not increased\n",sd+x-mv,sd+x+1-mv);
            }
            else
            {
                if(sd+x+1>mv)
                {
                    printf("From days %d to %d  the severity of the disease was not increased\n",sd+x,sd+x+1-mv);
                }
                else
                {
                    printf("From days %d to %d  the severity of the disease was not increased\n",sd+x,sd+x+1);
                }
            }
        }
    }
fclose(fp); //Close file

}
void choice3(struct people* p1,int nofpersons1,FILE *fp,int size) //Choice3 function definition and passing arguments
{
    int pcount,i1,flag,j;
    int size1;
    size1=size/sizeof(p1[0]);  //Determine size of file
    struct people p2[size1]; //Creating struct variable of size of the file
    fp=fopen("New","r"); //Open file using read mode
    fread(&p2,sizeof(p2),1,fp); //Reads data from a file

    char n[50];
    do{
            j=0;
            flag=0;
            printf("Please enter your NAME to login: \n"); //Input name to find probability
            scanf(" %[^\n]",n);
            while(n[j]!='\0')
            {
                if(isalpha(n[j])==0 && n[j]!=32)
                {
                printf("INVALID NAME(ONLY ALPHABETS ALLOWED!)PLEASE ENTER AGAIN\n");
                    flag=1;
                    break;
                }
                j++;
            }
      }while(flag==1);
    int flag3;
    for (i1 = 0; i1 <= size1 - 1; i1++)
    {
        if (strcmp(p2[i1].name,n)==0) //Compares name entered from file
        {
            pcount = 0;
            if (p2[i1].temp > 37) //Conditions for checking illness
            {
                pcount = pcount + 1;
            }
            if (p2[i1].hbpm < 60)
            {
              pcount = pcount + 1;
            }
            if (p2[i1].spo2lvl < 90)
            {
                pcount = pcount + 1;
            }
            if (p2[i1].coughrate > 70)
            {
                pcount = pcount + 1;
            }
            if (p2[i1].scount> 1)
            {
                pcount = pcount + 1;
            }
            if (pcount > 3 && pcount < 6)
             {
                    printf("RESULT: Probability of you having COVID-19 is HIGH ON DAY : %d/%d/%d\n " ,*p2[i1].dd,*p2[i1].mm,*p2[i1].yy) ; //Display for high probability case
                    printf("Follow these remedial measures:\n1. Stay at home and completely isolate yourself from others\n");  
                    printf("2. Get rest & stay hydrated \n");
                    printf("3. Inform your close contacts whom you were around recently\n");
                    printf("4. Contact your local medical heath care\n");
            }
             else
            {
                if (pcount > 1 && pcount < 4) 
                {
                    printf("RESULT: Probability of you having COVID-19 is MEDIUM ON DAY %d/%d/%d\n ",*p2[i1].dd,*p2[i1].mm,*p2[i1].yy); //Display for medium probability case
                    printf("Follow these remedial measures:\n1. Maintain social distancing\n");
                    printf("2. Use hand sanitizers\n");
                    printf("3. Avoid public transportation\n");
                    printf("4. Avoid touching face\n");
                }
            else
            {
                if (pcount == 0 || pcount < 2)
                {
                    printf("RESULT: Probability of you having COVID-19 is LOW ON DAY %d/%d/%d\n ",*p2[i1].dd,*p2[i1].mm,*p2[i1].yy); //Display for low probability case
                    printf("Follow these preventive measures:\n1. Maintain social distancing\n ");
                    printf("2. Stay at home\n");
                    printf("3. Monitor your symptoms\n");
                    printf("4. Wash hands often\n");
                }
                }
            }
        }
    }
    fclose(fp); //Close file
}
void choice4() //Choice4 - Variable Reference Guide
{
printf("\n");
printf(" MAIN VARIABLES USED IN THE CODE: \n");
printf("-----------------------------------\n");
printf(" name        - Stores Name of the person\n");
printf(" area        - Stores area of the person\n");
printf(" symptoms    - Stores the condition whether the person has symptomps or not\n");
printf(" dd,mm,yy    - Stores dd->date/mm->month/yy->year respectively of the person\n");
printf(" temp        - Stores Temperature of the person\n");
printf(" hbpm        - Stores Hbpm of the person\n");
printf(" spo2lvl     - Stores spo2level Name of the person\n");
printf(" coughrate   - Stores coughrate of the person\n");
printf(" scount      - Stores the count of the symptoms of the person\n");
printf(" nofpersons  - Stores the total number of persons\n");
printf(" choice      - Stores the choice of the person\n");
printf(" filepointer - Stores the pointer to the file\n");
printf(" tcount      - Stores the count of the temperature which is more than 37\n");
printf(" icount      - Stores the count of ill persons\n");
printf(" sd          - Stores the start date\n");
printf(" ed          - Stores the end date\n");
printf(" sm          - Stores the start month\n");
printf(" em          - Stores the start month\n");
printf(" sy          - Stores the start year\n");
printf(" ey          - Stores the start year\n");
printf(" pcount      - Stores the count of the symptoms to determine probability of having COVID-19\n");
}

void choice5(struct people* p1,int nofpersons1,FILE *fp,int size) //Choice5 function definition and passing arguments
{
    int size1;
    size1=size/sizeof(p1[0]);  //Determine size of file
    struct people p2[size1]; //Creating struct variable of size of the file
    fp=fopen("New","r"); //Open file using read mode
    fread(&p2,sizeof(p2),1,fp); //Reads data from a file
    int i;
    for(i=0;i<size1;i++)
    {
        printf("Name : %s\nArea : %s\nDate : %d/%d/%d\nTemperature : %.3f\nSPO2 level : %.3f\nHBPM : %.3f\nCoughrate : %.3f\nNumber of symptoms : %d\n",p2[i].name,p2[i].area,*p2[i].dd,*p2[i].mm,*p2[i].yy,p2[i].temp,p2[i].spo2lvl,p2[i].hbpm,p2[i].coughrate,p2[i].scount);
        printf("\n\n");
    }
    
}
