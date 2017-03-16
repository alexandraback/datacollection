#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int T,ii;
int a[20][20];
int n,m;

int main()
{
    freopen("A-small-attempt0 (3).in","r",stdin);
    freopen("A-small-attempt0 (3)out.txt","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    for(i=0;i<19;i++)for(j=0;j<19;j++)a[i][j]=999999999;
   a[1][1]=1;
   a[2][1]=2;
   a[2][2]=2;

   for(i=0;i<=10;i++)a[i][i]=i;
   for(i=3;i<=10;i++)
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
   for(i=1;i<=10;i++)
    {
      for(j=1;j<=10;j++)
       {
         printf("%d %d: %d\n",i,j,a[i][j]);
       }
       printf("\n");
    }*/
scanf("%d",&T);
for(ii=1;ii<=T;ii++)
{
   scanf("%d %d %d",&k,&n,&m);
   

   
   printf("Case #%d: %d\n",ii,a[n][m]);
}

    
    
    scanf(" ");
    return 0;
}
