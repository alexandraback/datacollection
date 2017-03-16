#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 110
#define M 1000010
int n,a,s[N],dp[N][M];
int main()
{
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	int tt,_;
	scanf("%d",&_);
	for(tt=1;tt<=_;tt++)
	{
		memset(dp,-1,sizeof(dp));
		cin>>a>>n;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		sort(s+1,s+n+1);
		dp[0][a]=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=1000001;j++)
		if(dp[i-1][j]!=-1)
		{
			if(j>s[i])
			{
				int k=j+s[i];
				if(k>=1000001) k=1000001;
				if(dp[i][k]==-1 || dp[i][k]>dp[i-1][j]) dp[i][k]=dp[i-1][j];
			}
			else
			{
				if(dp[i][j]==-1 || dp[i][j]>dp[i-1][j]+1) dp[i][j]=dp[i-1][j]+1;
				int k=j,sum=0,lst;
				if(k-1==0) continue;
				while (k<=s[i]) { k+=k-1; sum++; }
				k+=s[i];
				if(k>=1000001) k=1000001;
				if(dp[i][k]==-1 || dp[i][k]>dp[i-1][j]+sum) dp[i][k]=dp[i-1][j]+sum;
			}
		}
		int ans=INF;
		for(int i=1;i<=1000001;i++)
			if(dp[n][i]!=-1) ans=min(ans,dp[n][i]);
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
