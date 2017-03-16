#include <bits\stdc++.h>
using namespace std;
char s[200];
int dp[200][2];
const int inf = 2e9;
int main()
{
	freopen("0b.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i =1; i <= t; i++)
	{
		for(int j = 0; j < 200; j++)
			for(int k = 0; k < 2; k++)
				dp[j][k]  = inf;
		scanf("%s",s);
		int len = strlen(s);
		dp[0][0] = ((s[0] == '-')? 0 : 1);
		dp[0][1] = ((s[0] == '+')? 0 : 1);
		for(int j = 1; j < len;j++)
		{
			for(int k = 0; k < 2;k++)
			{
				if(s[j] == ((k == 0)? '-':'+'))
					dp[j][k] = min(dp[j-1][(k+1)%2]+1,dp[j-1][k]);
				else
					dp[j][k] = min(dp[j-1][(k+1)%2]+1,dp[j-1][k]+2);
			}
		}
		printf("Case #%d: %d\n",i,dp[len-1][1]);
	}
	return 0;
}