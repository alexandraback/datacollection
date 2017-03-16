#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
char s[1000050];
void print(int x,int y)
{
    if(x>0)
    {
        for(int i=0;i<x;i++)
        {
            printf("W");
            printf("E");
        }
    }
    else if(x<0)
    {
        for(int i=0;i<-x;i++)
        {
            printf("E");
            printf("W");
        }
    }
    if(y>0)
    {
        for(int i=0;i<y;i++)
        {
            printf("S");
            printf("N");
        }

    }
    else if(y<0)
    {
        for(int i=0;i<-y;i++)
        {
            printf("N");
            printf("S");
        }
    }
}
int main()
{
    int k,t,i,j,n,m,T,x,y;
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;++t)
    {
       scanf("%d%d",&x,&y);
       printf("Case #%d: ",t);

       if(x<0)
       {
           while(x++)printf("EW");
       }
       else
       {
           while(x--)printf("WE");
       }

       if(y<0)
       {
           while(y++)printf("NS");
       }
       else
       {
           while(y--)printf("SN");
       }
       printf("\n");
    }
    return 0;
}
