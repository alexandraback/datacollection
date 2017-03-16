#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int ll;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		ll K,C,S;
		scanf("%lld %lld %lld",&K,&C,&S);
		if(C*S<K) puts("IMPOSSIBLE");
		else
		{
			vector <ll> ret;
			for(ll i=0;i<K;)
			{
				ll ans=0;
				ll nxt=min(K,i+C);
				for(;i<nxt;i++)
				{
					ans*=K;
					ans+=i;
				}
				ret.push_back(ans);
			}
			for(int i=0;i<ret.size();i++)
			{
				if(i!=0) printf(" ");
				printf("%lld",ret[i]+1);
			}puts("");
		}
	}
	return 0;
}
