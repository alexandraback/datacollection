#include<stdio.h>

int elf(long long a, long long b)
{
	if(a==b)
		return 1;
	if(a>b)
		return -1;
	int iter = 0;
	int min = -1;
	while(a!=b && iter<40)
	{
		iter++;
		a*=2;
		if(a==b)
		{
			if(min==-1)
				min=iter;
		}
		if(a>b)
		{
			a-=b;
			if(min==-1)
				min=iter;
		}
	}
	if(a==b)
		return min;
	return 0;
}

long long gcd(long long a, long long b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	long long a, b;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%lld/%lld",&a,&b);
		long long fpb = gcd(a,b);
		int iter = elf(a/fpb,b/fpb);
		if(iter>0)
			printf("Case #%d: %d\n",cs,iter);
		else
			printf("Case #%d: impossible\n",cs);
	}
}