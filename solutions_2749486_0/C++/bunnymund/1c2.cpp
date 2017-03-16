#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std; 
int main()
{
 //freopen("C:\\Users\\DELL\\Desktop\\input.txt","r",stdin); 
//freopen("C:\\Users\\DELL\\Desktop\\output.txt","w",stdout);
int i,j,test,x,y;
 
scanf("%d",&test);
for(i=1;i<=test;i++)
{
char steps[1000];
char xxx[4];
char yyy[4];
steps[0]='\0';
scanf("%d %d",&x,&y);
        if(x<0)
          {
           xxx[0]='E';
           xxx[1]='W';
           xxx[2]=0;
           x*=-1;
           }
         else if(x>0)
          {   xxx[0]='W';
              xxx[1]='E';
              xxx[2]=0;
          }
 
          if(y<0)
          {
          yyy[0]='N';
          yyy[1]='S';
          yyy[2]=0;
          y*=-1;
          }
 
        else if(y>0)
          {
          yyy[0]='S';
          yyy[1]='N';
          yyy[2]=0;
          }
 
 
          for(j=0;j<x;j++)
          strcat(steps,xxx);
          for(j=0;j<y;j++)
          strcat(steps,yyy);
 
printf("Case #%d: %s\n",i,steps);

}
return 0;
}
