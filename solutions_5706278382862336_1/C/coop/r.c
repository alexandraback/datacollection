#include<stdio.h>
long long int gcd(long long int a,long long int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int main()
{
	long long int t,z,p,q,a;
	scanf("%lld",&t);
	for(z=1;z<=t;z++)
	{
		scanf("%lld/%lld",&p,&q);
		a=gcd(p,q);
		p=p/a;
		q=q/a;
		a=q;
		while(a%2==0)
		{
			a=a/2;
		}
		if(a==1)
		{
			a=0;
			while(p<q)
			{
				p=p*2;
				a++;
			}
			if(a==0)
			{
				a=1;
			}
			printf("Case #%lld: %lld\n",z,a);
		}
		else
		{
			printf("Case #%lld: impossible\n",z);
		}
	}
	return 0;
}
