#include<bits/stdc++.h>
using namespace std;

int reverse(int N)
{
	int num = 0;
	while(N)
	{
		num = num*10 + N%10;
		N = N/10;
	}
	return num;
}

int dp[1000010] = {0};
int main(void)
{
	int c = 1,T,N;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	for(int i=1;i<=10;i++)
		dp[i] = dp[i-1] + 1;
	for(int i=11;i<=1000000;i++)
	{
		int rev = reverse(i);
		if(rev != i && dp[rev] != -1 && i % 10 != 0)
			dp[i] = min(dp[i-1]+1,dp[rev]+1);
		else
			dp[i] = dp[i-1] + 1;
	}
	while(T--)
	{
		printf("Case #%d: ",c++);
		scanf("%d",&N);
		printf("%d\n",dp[N]);
	}
	return 0;
}
