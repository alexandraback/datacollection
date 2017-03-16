#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ii,i,j,dp[100000],s,ans,t;
	char str[100001];
	scanf("%d",&t);
	for(ii=1;ii<=t;ii++)
	{
		scanf("%d",&s);
		scanf("%s",str);
		memset(dp,0,sizeof(dp));
		ans=0;
		dp[0]=str[0]-'0';
		for(i=1;i<=s;i++)
		{
			if(dp[i-1]>=i)
			{
				dp[i]=dp[i-1]+str[i]-'0';
			}
			else
			{
				dp[i]=i+str[i]-'0';
				ans=ans+i-dp[i-1];
			}
		}
		printf("Case #%d: %d\n",ii,ans);
	}
}
