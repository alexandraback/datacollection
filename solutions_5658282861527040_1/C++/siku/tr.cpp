#include<stdio.h>
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("t.txt","w",stdout);
	long long a,b,k,t,i,j,tt=0,x,s=0;
	long long c=0,ans=0;
	scanf("%lld",&t);
	while(t--)
	{
		tt++;
		c=0;ans=0;
		scanf("%lld %lld %lld",&a,&b,&k);
		if((k<a)&&(k<b))
		{
		for(i=k;i<a;i++)
			for(j=0;j<b;j++)
			{
				x=i&j;
				if(x<k)
				c++;
			}
		ans=k*b+c;
		}
		else 
		{
			ans=a*b;
		}
	
		printf("Case #%lld: %lld\n",tt,ans);
	}
	return 0;
}
