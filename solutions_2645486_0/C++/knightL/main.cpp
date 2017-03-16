#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[11][11];
int n,e,r;
int v[11];

int solve(int cur, int cure)
{
	if(dp[cur][cure]==-1)
	{
		if(cur==n)
			dp[cur][cure]=0;
		else
		{
			if(cure)
				dp[cur][cure]=max(solve(cur+1,min(cure+r,e)),solve(cur,cure-1)+v[cur]);
			else
				dp[cur][cure]=solve(cur+1,min(cure+r,e));
		}
	}
	return dp[cur][cure];
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		scanf("%d%d%d",&e,&r,&n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %d\n",test,solve(0,e));
	}
	return 0;
}
