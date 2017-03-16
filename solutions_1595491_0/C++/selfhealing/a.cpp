#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Inf = 1000000;
int dp[105][105],a[105];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas=0;scanf("%d",&T);
	while(T--)
	{
		int n,m,p;
		scanf("%d%d%d",&n,&m,&p);
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= m; j++)
				dp[i][j] = -Inf;
		dp[0][0] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j <= m; j++)if(dp[i][j]!=-Inf)
			{
				for(int k = 0; k <= 10 && k<=a[i]; k++)
					for(int l = 0; l <= 10 && l+k<=a[i]; l++)
					{
						int mx = max(max(k,l),a[i]-k-l);
						int mi = min(min(k,l),a[i]-k-l);
						if(mx-mi > 2)continue;
						if(mx-mi==2)
						{
							if(j+1<=m)
								dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+(mx>=p));
						}
						else
						{
							dp[i+1][j] = max(dp[i+1][j], dp[i][j]+(mx>=p));
						}
					}
			}
		printf("Case #%d: %d\n",++cas,dp[n][m]);
	}

	return 0;
}
