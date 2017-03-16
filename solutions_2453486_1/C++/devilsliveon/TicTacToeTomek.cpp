#include<iostream>
#include<conio.h>
#include<stdio.h>
int main()
{
    int t;
    FILE *fp=fopen("input.txt","r");
    FILE *f2=fopen("output.txt","w");
    fscanf(fp,"%d",&t);
    printf("%d\n",t);
   // char blank[10];
    int status =0,tcn=0,i,j;
    for(tcn=1;tcn<=t;tcn++)
    {
      char a[10][10];
      status =0;
      for(j=0;j<4;j++)
      {
      fscanf(fp,"%s",a[j]);
      }
      
      // Vertical checks are performed here
      for(i=0;i<4;i++)
      {
                      
         
            //Checking vertically for X          
         int x=0,t1=0;
         for(j=0;j<4;j++)
           {
             if(a[j][i]=='X')
             x++;
             if(a[j][i]=='T')
             t1++;
           }
         if((x+t1)==4)
         {
          
          status=1;
          
          }
          
          //Checking vertically for Y
          int y=0;
          t1=0;
          for(j=0;j<4;j++)
           {
             if(a[j][i]=='O')
             y++;
             if(a[j][i]=='T')
             t1++;
           }
         if((y+t1)==4)
         {
          status=2;
          
          }
          
        //}  //If code completed
        
      } //for loop (vertical checker) completed
      
   if(status==0)
   {   
      // Horizontal checks are performed here
      for(i=0;i<4;i++)
      {
            //Checking horizontally for X          
         int x=0,t1=0;
         for(j=0;j<4;j++)
           {
             if(a[i][j]=='X')
             x++;
             if(a[i][j]=='T')
             t1++;
           }
         if((x+t1)==4)
         {
          status=1;
          break;
          }
          
          //Checking horizontally for O
          int y=0;
          t1=0;
          for(j=0;j<4;j++)
           {
             if(a[i][j]=='O')
             y++;
             if(a[i][j]=='T')
             t1++;
           }
         if((y+t1)==4)
         {
          status=2;
          
          }
          
        //}  //If code completed
        
      } //for loop (horizontal checker) completed

      } // If code to check for status completed here  
      
if(status==0)
{
       //Diagonal checks are performed here
             
       // Main diagonal check for X
        int x=0,t1=0; 
        for(i=0;i<4;i++)
        {
                       j=i;
                       {
                       if(a[i][j]=='X')
                       x++;
                       if(a[i][j]=='T')
                       t1++;
                       }
                             
        }
            if((x+t1)==4)
                       {
                       status=1;
                       }  
        // Main diagonal check for O
         int y=0;t1=0;
        for(i=0;i<4;i++)
        { 
                       j=i;
                       {
                       if(a[i][j]=='O')
                       y++;
                       if(a[i][j]=='T')
                       t1++;
                       }
                                 
        }
        
                       if((y+t1)==4)
                       {
                       status=2;
                       }  
        // Perpendicular diagonal check for X
        x=0;t1=0; 
        for(i=0;i<4;i++)
        {
                       j=(3-i);
                       {
                       if(a[i][j]=='X')
                       x++;
                       if(a[i][j]=='T')
                       t1++;
                       }
                                 
        }
                       if((x+t1)==4)
                       {
                       status=1;
                       }  
        // Perpendicular diagonal check for O
        y=0;t1=0; 
        for(i=0;i<4;i++)
        {
                       j=(3-i);
                       {
                       if(a[i][j]=='O')
                       y++;
                       if(a[i][j]=='T')
                       t1++;
                       }
                                   
        }
                       if((y+t1)==4)
                       {
                       status=2;
                       }
} // Diagonal checks completed

// Checking for status 3 viz. a Draw and status 4 (Not completed)
if(status==0)
{
             for(i=0;i<4;i++)
             {
                             for(j=0;j<4;j++)
                             {
                               if(a[i][j]=='.')
                               {
                                               status=4;
                                               }
                             }
             }
            if(status==0) status=3;
}

//fprintf(f2,"The status is :%d\n",status);
if(status==1)
{
             fprintf(f2,"Case #%d: X won\n",tcn);
             }
else if(status==2)
{
            fprintf(f2,"Case #%d: O won\n",tcn);
            }
else if(status==3)
{
     fprintf(f2,"Case #%d: Draw\n",tcn);
     }
else if(status==4)
{
     fprintf(f2,"Case #%d: Game has not completed\n",tcn);
     }

}
     return 0;
     }
