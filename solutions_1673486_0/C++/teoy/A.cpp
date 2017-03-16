#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int N = 100010;
double dp[N][2],p[N];
int main(void)
{
	int T,n,m,g=0;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&p[i]);
		}
		dp[0][1]=1;dp[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=dp[i-1][0]+dp[i-1][1]*(1-p[i]);
			dp[i][1]=dp[i-1][1]*p[i];
		}
		double ans=2+m;
		double tmp=dp[n][1]*(m-n+1)+(1-dp[n][1])*(m-n+2+m);
		ans=min(ans,tmp);
		for(int i=1;i<n;i++)
		{
			tmp=(n-i+m-i+1)*dp[i][1]+(1.0-dp[i][1])*(n-i+m-i+2+m);
			ans=min(ans,tmp);
		}
		printf("Case #%d: %.6f\n",++g,ans);
	}
	return 0;
}
