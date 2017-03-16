#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int T,ii;
char a[10];
char b[10];
char x[10];
int A,B,n;
double sum,maxx,countt;

int f(int h)
{
   int i,j,k,t;
   if(h==n)
    {
      t=0;
      for(i=0;i<n-B+1;i++)
      {
        k=0;
        for(j=i;j<i+B;j++)
         {
           if(x[j]!=b[k])break;
           k++;
         }
        if(j==i+B)
         {
           t++;
         }
      }
        sum+=(double)(t);
        if(maxx==-1.0)maxx=(double)(t);
        else
         {
           if((double)(t)>maxx)maxx=(double)(t);
         }
        countt+=1.0;
      return 0;
    }
   for(i=0;i<A;i++)
   {
     x[h]=a[i];
     f(h+1);
   }
   return 0;
}

int main()
{
    freopen("B-small-attempt0 (3).in","r",stdin);
    freopen("B-small-attempt0 (3)out.txt","w",stdout);
   int i,j,k;
   double t,tt,ttt;
    
scanf("%d",&T);
for(ii=1;ii<=T;ii++)
{
   scanf("%d %d %d",&A,&B,&n);
   scanf("%s",a);
   scanf("%s",b);
   sum=0.0;
   maxx=-1.0;
   countt=0.0;
   f(0);
   t=maxx - (sum/countt);

   printf("Case #%d: %.6lf\n",ii,t);
}

    
    
    scanf(" ");
    return 0;
}
