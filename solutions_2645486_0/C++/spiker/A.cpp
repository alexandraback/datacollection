#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
int a[100];
int dp[10][10];
int e,r,n;
int solve(int x, int v)
{
	if (x == n)
		return 0;
	if (dp[x][v] != -1)
		return dp[x][v];
	int ans = 0;
	for (int i = 0; i<= v; i++)
	{
		int tmp = solve(x + 1, min(v-i + r, e));
		if ((tmp + i * a[x]) > ans)
		{
			ans = tmp + i * a[x];
		}
	}
	dp[x][v] = ans;
	return ans;
}
int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int q = 1; q <= T; q++)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d%d%d",&e,&r,&n);
		for (int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		int res = solve(0,e);
		printf("Case #%d: %d\n",q,res);
	}
	return 0;
}