#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

int v[10001];
int largest[10001];


int main()
{
	freopen("/home/knightl/B-large.in","r",stdin);
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		int E,R,N;
		scanf("%d%d%d",&E,&R,&N);
		if(R>E) R=E;
		REP(i,N)
			scanf("%d",&v[i]);
		largest[N-1]=v[N-1];
		for(int i=N-2;i>=0;i--)
		{
			largest[i]=max(largest[i+1],v[i]);
		}
		ll curE=E;
		ll res=0;
		for(int i=0;i<N;i++)
		{
//			ll cost=max(0LL,curE+R -E);
			bool reachGreater=false;
			int nextLarger=i+1;
			for(nextLarger=i+1;nextLarger<N;nextLarger++)
			{
				if(v[nextLarger]>v[i])
				{
					reachGreater=true;
					break;
				}
			}
			if(largest[i]==v[i])
			{
				res+=curE*v[i];
				curE=0;
			}
			else
			{
				ll can_spend=min(max(0LL,curE+ll(R)*(nextLarger-i)-E),curE);
				res+=(can_spend)*v[i];
				curE-=can_spend;
			}
			curE+=R;

//			assert(0<=curE&&curE<=E);
			assert(0<=curE);
			assert(curE<=E);
		}
		printf("Case #%d: %lld\n",test,res);
	}
	return 0;
}
