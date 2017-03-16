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
#define M 1005
using namespace std;
typedef long long LL;
int t,e,r,n,ans,in[M],dp[M][M];
int main()
{
	int x;
	scanf("%d",&t);
	REP(tt,1,t)
	{
		MSET(dp,-1);
		scanf("%d %d",&e,&r);
		scanf("%d",&n);
		REP(i,1,n)scanf("%d",&in[i]);
		
		dp[1][e] = 0;
		REP(i,1,n)REP(j,0,e)REP(k,0,j)//[i,j] spend k
		{
			if(dp[i][j]==-1)continue;
			x = min(j-k+r, e);

			dp[i+1][x] = max(dp[i+1][x], dp[i][j]+in[i]*k);
		}
		

		ans=-1;
		REP(i,0,e)ans = max(ans,dp[n+1][i]);
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

