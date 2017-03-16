#include<stdio.h>
#include<string.h>
#include<stdlib.h>
solve()
{
	int i,mp;
	double n,sum,sum2,ss,max,e;
	max=-1;ss=-2;e=0;
	double a[300];
	double ans;
	sum=0;sum2=0;
	scanf("%lf",&n);
	for(i=0;i<n;i++)
		 {scanf("%lf",&a[i]);sum2+=a[i];}
	while(ss<max)
	{
		max=-1;sum=0;
		for(i=0;i<n;i++)
		{ 
			if(a[i]>0)sum+=a[i];
			if(max<a[i])
			{
				max=a[i];
				mp=i;
			}
		}
		ss=sum+sum2;ss/=n-e;
		e+=1;//printf("%lf %lf %lf\n",n-e,ss,max);
		if(ss<max)
			a[mp]=-1;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=-1)
		{ans=(ss-a[i])/sum2;
		printf("%lf ",ans*100);}
		else
			printf("0.000000 ");
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
		printf("\n");
	}
	return 0;
}
