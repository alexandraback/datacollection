#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

#define MX 100100

int tt;
int n;
int X[30];
int dp[30][MX+MX];
vector<int> A,B;

int main()
{
	scanf("%d",&tt);
	for(int t=1;t<=tt;++t)
	{
		scanf("%d",&n);
		memset(dp,-1,sizeof dp);
		dp[0][MX]=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",X+i);
			for(int j=0;j<MX+MX;++j)
			{
				if (dp[i][j]!=-1)
				{
					if (j+X[i]<MX+MX)
						dp[i+1][j+X[i]]=max(dp[i+1][j+X[i]],i+1);
					dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
					if (j-X[i]>0)
						dp[i+1][j-X[i]]=max(dp[i+1][j-X[i]],i+1);
				}
			}
		}
		printf("Case #%d:\n",t);
		if (dp[n][MX]==0)
			puts("Impossible");
		else
		{
			A.clear();
			B.clear();
			for(int i=n,j=MX;i>0;--i)
			{
				//printf("%d %d\n",j-MX,dp[i][j]);
				if (dp[i][j]==i)
				{
					if (j-X[i-1]>0&&dp[i-1][j-X[i-1]]!=-1)
					{
						A.push_back(X[i-1]);
						j-=X[i-1];
					}
					else
					{
						B.push_back(X[i-1]);
						j+=X[i-1];
					}
				}
			}
			int a=0,b=0;
			for(int i=A.size()-1;i>=0;--i)
			{
				a+=A[i];
				printf("%d",A[i]);
				if (i) printf(" ");
				else puts("");
			}
			for(int i=B.size()-1;i>=0;--i)
			{
				b+=B[i];
				printf("%d",B[i]);
				if (i) printf(" ");
				else puts("");
			}
			//printf("%d %d\n",a,b);
		}
	}
	return 0;
}
