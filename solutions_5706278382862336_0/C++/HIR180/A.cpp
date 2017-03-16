#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll p,q;
int n;

int main()
{
	scanf("%d",&n);
	for(int test = 1;test <= n;++test)
	{
		printf("Case #%d: ",test);
		scanf("%lld/%lld",&p,&q);
		ll s = __gcd(p,q);
		p/=s; q/=s;
		if( (1LL<<40)%q !=0)
		{
			puts("Impossible");
			continue;
		}
		ll v = (1LL<<40)/q*p;
		for(int i=1;i<=40;i++)
		{
			if(v < (1LL<<i) )
			{
				printf("%d\n",41-i);
				break;
			}
		}
	}
}