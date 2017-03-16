#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int tt,zz;
	cin>>tt;
	for (zz=1;zz<=tt;zz++)
	{
		long long a,b;
		scanf("%lld/%lld",&a,&b);
		long long c=gcd(a,b);
		a/=c;
		b/=c;
		if (a>b || b>(1LL<<40) || (b&(-b))!=b)
		{
			printf("Case #%d: impossible\n",zz);
		}
		else
		{
			int ans=1;
			while (a<b/2)
			{
				b/=2;
				ans++;
			}
			printf("Case #%d: %d\n",zz,ans);
		}
	}
}
