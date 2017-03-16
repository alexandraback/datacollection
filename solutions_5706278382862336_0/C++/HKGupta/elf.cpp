#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long gcd(long long a,long long b)
{ 
while(a!=b)
{
	if(a>b)
	a=a-b;
	else
	b=b-a;
}
return a;
 }
int main()
{
	int T;
	cin>>T;
	for (int t = 0; t < T; ++t)
	{
		long long p,q;
		scanf("%lld/%lld",&p,&q);
		
		long long count=1;
		bool f=false;
		long long g=gcd(p,q);
		p=p/g;
		q=q/g;
		while(count<=q)
		{
			if(count==q)
				f=true;
			count=count*2;
		}
		if(!f)
		{
			printf("Case #%d: impossible\n", t+1);
			continue;
		}
		double w=p/(double)q;
		
		double tr=1;
		int c=0;
		while(c<40)
		{
			c++;
			tr=tr/2;
			if(w>=tr)
			{
				printf("Case #%d: %d\n", t+1,c);
				break;
			}

		}
	}
}
