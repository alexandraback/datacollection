/*
#include<stdio.h>
#include<stdlib.h>
int n,a[210],sum;

double cal(int k)
{
	int i;
	double l,r,m,t,he;

	l=0.0;r=100.0;
	while(r-l>1e-10)
	{
		m=(r+l)/2;
		t=a[k]*100+m*sum;
		he=0;
		for(i=1;i<=n;i++)
		{
          he+=(t-a[i]*100)/sum;
		}
		if(he>100) r=m-1e-10;
		else l=m+1e-10;
	}
	return m;
}

int main()
{
	int ca,i,j,test=0;

	freopen("Ain.txt","r",stdin);
	freopen("Aout.txt","w",stdout);
	scanf("%d",&ca);
	while(ca--)
	{

		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}

		printf("Case #%d:",++test);
		for(i=1;i<=n;i++)
		{
			printf(" %.6lf",cal(i));
		}
		printf("\n");
	}
	return 0;
}*/

#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

int main()
{
	int t,i,j,n,test=0;
	int a[210];
	double ans[210];
		freopen("Ain.txt","r",stdin);
	freopen("Aout.txt","w",stdout);

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		double sum=0.0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(i=1;i<=n;i++)
		{
			double l=0.0,r=100.0,mid,tt;
			while(l+1e-10<r)
			{
				mid=(l+r)/2.0;
				double now=a[i]+sum*mid;
				double yu=1-mid;
				for(j=1;j<=n;j++)
				{
					if(i==j) continue;
					if((double)a[j]+0.0>=now) continue;
					double ty=(now-a[j])/sum;
					if(yu<ty) break;
					yu-=ty;
				}
				if(j<=n)
				{
					tt=mid;
					r=mid;
				}
				else l=mid;
			}
			ans[i]=tt;
			ans[i]*=100.0;
		}
	     printf("Case #%d: ",++test);
		for(int k=1;k<n;k++) printf("%.9lf ",ans[k]);
		printf("%.9lf\n",ans[k]);
	}
	
	return 0;
}


        
