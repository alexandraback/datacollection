#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int dp[1100][1100];
int n,p[1100],tmp;
int main()
{
	int T;
	//freopen("bout.txt","w",stdout);
	scanf("%d",&T);
	for (int nT=1;nT<=T;nT++)
	{
		memset(dp,0,sizeof dp);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for (int i=0;i<=1000;i++)
			dp[1][i]=p[1]/(i+1)+( (p[1]%(i+1)!=0)?1:0 );
		for (int i=2;i<=n;i++)
			for (int j=0;j<=1000;j++)
			{
				dp[i][j]=2147483647;
				for (int k=0;k<=j;k++) //divide
				{
					tmp=p[i]/(k+1)+( (p[i]%(k+1)!=0)?1:0 );
					dp[i][j]=min(dp[i][j],max(dp[i-1][j-k],tmp));
				}
			}
		int ans=2147483647; 
		for (int i=0;i<=1000;i++)
			if (i+dp[n][i]<ans)
			{
				ans=i+dp[n][i];
//				printf("%d %d;\n",i,dp[n][i]);
			}
		printf("Case #%d: %d\n",nT,ans);
	}
}
