#include <iostream>
#include <cstdio>
using namespace std;

char a[1005];

long long int gcd(long long int i, long long int j)
{
	long long k,q,r;
	while(j>1)
	{
		r=i%j;
		if(r==0) break;
		i=j; j=r;
	}
	return j;
}

int main() 
{
	long long int i,j,k,t,ca=0,p,q,n;
	double d1,d2; 
	scanf("%lld",&t);
	while(t--)
	{
		++ca;
		scanf("%s",a);
		p=q=0;
		for(i=0;a[i]!='/';++i)
		{
			p=p*10+(a[i]-'0');
		}
		for(i=i+1;a[i];++i)
		{
			q=q*10+(a[i]-'0');
		}
		
		if(p<q)
		{
			n=gcd(q,p);
			q=q/n; p=p/n;
		
			k=q-1;
			n=q&k; 
		}
		else n=1;
		
		if(n==0)
		{
			j=2; k=1;
			d1=(double)p/(double)q; d2=1.0/(double)j;
			while(1)
			{
				if(d1>=d2)
				{
					break;
				}
				++k; j=j<<1; d2=1.0/(double)j;
			}
			printf("Case #%lld: %lld\n",ca,k);
		}
		else
		{
			printf("Case #%lld: impossible\n",ca);
		}
	}
	//system("pause");
	return 0;
}
