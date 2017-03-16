#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long gcd(long long n,long long m)
	{ if(m<=n && n%m == 0)
	   return m;
	  if(n < m)
	   return gcd(m,n);
	  else
	   return gcd(m,n%m);
	 }
int main()
{
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		long long a,b;
		scanf("%lld/%lld",&a,&b);
		//cout<<a<<" "<<b<<endl;
		long long cn=1;
		int flag=0;
		long long divnum=gcd(a,b);
		a=a/divnum;
		b=b/divnum;
		while(cn<=b)
		{
			if(cn==b)
				flag=1;
			cn=cn*2;
		}
		if(flag==0)
		{
			printf("Case #%d: impossible\n", i+1);
			continue;
		}
		double val=a/(double)b;
		//cout<<"val "<<val<<endl;
		double ct=1;
		int count=0;
		while(count<40)
		{
			count++;
			ct=ct/2;
			if(val>=ct)
			{
				printf("Case #%d: %d\n", i+1,count);
				break;
			}

		}
	}
}