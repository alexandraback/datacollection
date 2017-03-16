#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[20][10], v[20];
int e,r,n,ans;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ++ii)
	{
		ans=0;
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
		scanf("%d%d%d", &e, &r, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d",&v[i]);
		for (int i = r; i <= e; ++i)
		{
			dp[0][i]=v[0]*(e-i+r);
			if(dp[0][i]>ans)ans=dp[0][i];
			//printf("%d ", dp[0][i]);
		}
		//printf("\n");
		for (int i = 1; i < n; ++i)
		{
			for (int j = r; j <= e; ++j)
			{
				for (int k = max(j-r,r); k <= e; ++k)
				{
					if(dp[i-1][k]+v[i]*(k-j+r)>dp[i][j])
						dp[i][j]=dp[i-1][k]+v[i]*(k-j+r);
					if(dp[i][j]>ans)ans=dp[i][j];
					//printf("%d %d %d\n", j,k, dp[i-1][k]);
				}
				//printf("%d ", dp[i][j]);
			}
			//printf("\n");
		}
		printf("Case #%d: ", ii);
		printf("%d\n", ans);
	}
	return 0;
}