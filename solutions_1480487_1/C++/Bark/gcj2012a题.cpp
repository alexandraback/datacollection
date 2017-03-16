// gcj2012a题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
double sc[305];
int tg[305];
double res[305];
int main()
{
	freopen("in.txt","r",stdin);
    freopen("out5.txt","w",stdout);
  int n,i,j,k,t;
  scanf("%d",&t);
  int tt;
  double sum;
  for(tt=1;tt<=t;tt++)
  {
	  memset(tg,0,sizeof(tg));
       sum=0;
	   printf("Case #%d:",tt);
	   scanf("%d",&n);
	   for(i=0;i<n;i++)
	   {
		   scanf("%lf",&sc[i]);
		   sum+=sc[i];
	   }
	   double sum1=sum*2.0;
	   double mb=sum1/n;
	   int maxn;double max1;
	   int tag=0;
	   int cnt1=0;
	   while(1)
	   {
		   max1=0.0;
		   maxn=-1;
		   tag=0;
       for(i=0;i<n;i++)
	   {
		   if(sc[i]>mb&&!tg[i]&&sc[i]>max1)
		   {
            max1=sc[i];
			maxn=i;
		   }
	   }
	   if(maxn<0)
		   break;
	   else
	   {
		   tg[maxn]=1;
           cnt1++;
		   sum1-=max1;
		   mb=sum1/(n-cnt1);
	   }
	   }
	   for(i=0;i<n;i++)
	   {
		   if(tg[i])
			   res[i]=0.0;
		   else
		   {
			   res[i]=(mb-sc[i])/sum*100.0;
		   }
	   }
	   for(i=0;i<n;i++)
		   printf(" %lf",res[i]);
	   printf("\n");
  }
  return 0;
}
