#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int v,ans;
bool ok[35],dp[35];
int d[35];

bool check()
{
	int cnt=0;
	for (int i=1;i<=v;i++) if (ok[i]) d[++cnt]=i;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for (int i=1;i<=cnt;i++)
	{
		for (int j=v;j>=d[i];j--) dp[j]=dp[j]|dp[j-d[i]];
		int s=0;
		for (int j=1;j<=v;j++) s+=dp[j];
		if (s==v) return 1;
	}
	return 0;
}

void dfs(int x,int pre)
{
	if (x>=ans) return;
	if (check()) {ans=min(ans,x);return;}
	for (int i=pre+1;i<=v;i++)
		if (!ok[i])
		{
			ok[i]=1;dfs(x+1,i);ok[i]=0;
		}
}
	

int main()
{
	#ifdef waltz
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int test;scanf("%d",&test);
	for (int t=1;t<=test;t++)
	{
		int c,n;scanf("%d%d%d",&c,&n,&v);
		memset(ok,0,sizeof(ok));
		for (int i=1;i<=n;i++)
		{
			int x;scanf("%d",&x);
			ok[x]=1;
		}
		ans=n+5;
		dfs(n,0);
		printf("Case #%d: %d\n",t,ans-n);
	}
	return 0;
}
