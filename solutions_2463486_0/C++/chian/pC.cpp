#include<stdio.h>
#include<string.h>
int main()
{
	freopen("C-small-attempt1.txt","r",stdin);
	freopen("pC_out.txt","w",stdout);
	
	int dp[1002];
	memset(dp,0,sizeof(dp));
	dp[1]=1,dp[4]=1,dp[9]=1,dp[121]=1,dp[484]=1;
	for(int i=2;i<=1000;i++)dp[i]+=dp[i-1];
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d\n",cas++,dp[b]-dp[a-1]);
	}
	return 0;
}
