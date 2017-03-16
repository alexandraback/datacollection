#include<stdio.h>
int main()
{
	long long int ans,t,i,r,c,w;
	scanf("%lld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld%lld%lld",&r,&c,&w);
		if(r==1)
		{
			if(c%w==0)
				ans=(c/w)+w-1;
			else
				ans=(c/w)+w;
		}
		else
		{
			if(c%w==0)
				ans=(r*(c/w))+w-1;
			else
				ans=(r*(c/w))+w;
		}
		printf("Case #%lld: %lld\n",i,ans);
	}
	return 0;
}
