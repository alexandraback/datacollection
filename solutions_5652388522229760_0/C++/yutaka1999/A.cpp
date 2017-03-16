#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MX 20

using namespace std;
typedef long long int ll;

bool use[MX];

bool check()
{
	for(int i=0;i<10;i++)
	{
		if(!use[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		ll n;
		scanf("%lld",&n);
		if(n==0) puts("INSOMNIA");
		else
		{
			ll now=0;
			memset(use,false,sizeof(use));
			while(!check())
			{
				now+=n;
				ll t=now;
				while(t>0)
				{
					use[t%10]=true;
					t/=10;
				}
			}
			printf("%lld\n",now);
		}
	}
	return 0;
}
