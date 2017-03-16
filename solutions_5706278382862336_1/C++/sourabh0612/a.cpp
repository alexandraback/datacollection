#include<cstdio>
#include<iostream>

using namespace std;

long long int gcd(long long int n, long long int m)
{
	long long int gc, remainder;
 
	while (n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;
	}
 
	gc = m;
 
	return gc;
}

int main()
{
	long long int t;
	long long int kase=1;
	scanf("%lld",&t);
	while(t--)
	{
		long long int num, den;
		char ch;
		scanf("%lld",&num);
		scanf("%c",&ch);
		scanf("%lld",&den);
		long long int gcd2 = gcd(num,den);
		num/=gcd2;
		den/=gcd2;
		if((den != 1) && (den & (den - 1)))
		{
			printf("Case #%lld: impossible\n",kase);
			kase++;
			continue;
		}
		if(den%num == 0)
		{
			den = den/num;
			num = 1;
		}
		long long int count = 0;
		long long int div = den/num;
		if(num == 1)
		{
			while(den != 1)
			{
				den/=2;
				count++;
			}
			printf("Case #%lld: %lld\n", kase,count);
			kase++;
			continue;
		}
		while(div != 0)
		{
			div/=2;
			count++;
		}
		printf("Case #%lld: %lld\n", kase,count);
		kase++;
	}
	return 0;
}