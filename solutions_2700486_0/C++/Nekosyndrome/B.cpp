#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 1000005
using namespace std;
typedef long long LL;
int t,e,r,n,cur,in[M],rem[M];
LL ans;
struct comp
{
	bool operator () (int x,int y)
	{
		return in[x]<in[y];
	}
};
set<int,comp> s;

int main()
{
	int x;
	scanf("%d",&t);
	REP(tt,1,t)
	{
		//MSET(dp,-1);
		ans=0;
		scanf("%d %d",&e,&r);
		scanf("%d",&n);
		r=min(e,r);
		REP(i,1,n)scanf("%d",&in[i]);
		

		s.clear();
		cur=r;
		ans=(LL)in[1]*e;
		s.insert(1);
		rem[1]=e;
		REP(i,2,n)
		{
			while(s.SZ && in[*s.begin()]<in[i] && cur<e)
			{
				x = min(rem[*s.begin()], e-cur);
				rem[*s.begin()]-=x;
				ans-=(LL)x*in[*s.begin()];
				cur+=x;

				x=*s.begin();
				if(!rem[x])s.erase(x);
			}

			rem[i]=cur;
			s.insert(i);
			ans+=(LL)cur*in[i];
			cur=r;
		}
		
		printf("Case #%d: %I64d\n",tt,ans);
	}
	return 0;
}

