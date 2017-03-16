#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int T,ii;
int a[30][30];
int n,m;

int main()
{
    freopen("A-large (3).in","r",stdin);
    freopen("A-large (3)out.txt","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    for(i=0;i<29;i++)for(j=0;j<29;j++)a[i][j]=999999999;
   a[1][1]=1;
   a[2][1]=2;
   a[2][2]=2;

   for(i=0;i<=20;i++)a[i][i]=i;
   for(i=3;i<=20;i++)
    {
      for(j=1;j<=i;j++)
       {
         for(k=1;k<=j;k++)
          {
            t=999999999;
            tt=999999999;
            p=k+(j-1);
            if(i-k>=j)t=1+a[i-k][j];
            if(p>i)p=i;
            tt=a[p][j];
            if(i==3)
             {
              // printf("%d %d %d %d\n",j,k,t,tt);
             }
            if(t>tt)
             {
               if(t<a[i][j])a[i][j]=t;
             }
            else 
             {
               if(tt<a[i][j])a[i][j]=t;
             }
          }
       }
    }
   /*
   for(i=1;i<=20;i++)
    {
      for(j=1;j<=i;j++)
       {
         printf("%d %d: %d\n",i,j,a[i][j]);
       }
       printf("\n");
    }
    /*
   for(i=1;i<=14;i++)
    {
      for(j=1;j<=i;j++)
       {
         n=i;m=j;
            t=m*2-1;
              tt=1;
               while(t<n)
                {
                 t+=m;
          tt++;
           }   
           printf("%d %d %d\n",i,j,tt);
       }
       printf("\n");
    }*/
scanf("%d",&T);
for(ii=1;ii<=T;ii++)
{
   scanf("%d %d %d",&k,&n,&m);
   t=m*2-1;
   tt=1;
   while(t<n)
    {
      t+=m;
      tt++;
    }   
   //printf(">%d %d\n",t,tt);
   printf("Case #%d: %d\n",ii,a[n][m]+(k-1)*tt);
}

    
    
    scanf(" ");
    return 0;
}
