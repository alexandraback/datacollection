#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

#define maxn 110

int dp[maxn][maxn],mat[maxn],one[maxn],two[maxn];

int main()
{
	int i,j,n,m,p,x,y,t,ca;
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++)
	{
		scanf("%d%d%d",&n,&m,&p);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&mat[i]);
			one[i]=mat[i]/3;
			if(mat[i]%3==0)
			{
				one[i]=mat[i]/3;
				two[i]=one[i]+1;
			}
			else if(mat[i]%3==1)
			{
				one[i]=mat[i]/3+1;
				two[i]=one[i];
			}
			else
			{
				one[i]=mat[i]/3+1;
				two[i]=mat[i]/3+2;
			}
			if(mat[i]==0)
			{
				one[i]=0;
				two[i]=-1;
			}
			else if(mat[i]==1)
			{
				one[i]=1;
				two[i]=-1;
			}
			else if(mat[i]==30)
			{
				one[i]=10;
				two[i]=-1;
			}
			else if(mat[i]==29)
			{
				one[i]=10;
				two[i]=-1;
			}
			
		}
		printf("Case #%d: ",ca);
		for(i=0;i<maxn;i++)
		{
			for(j=0;j<maxn;j++)
			{
				dp[i][j]=-100000;
			}
		}
		dp[0][0]=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=i&&j<=m;j++)
			{
				if(j!=i&&one[i]!=-1)
				{
					if(one[i]>=p)
					{
						x=dp[i-1][j]+1;
					}
					else
					{
						x=dp[i-1][j];
					}
				}
				else
				{
					x=-10000;
				}
				if(two[i]!=-1&&j>0)
				{
					if(two[i]>=p)
					{
						y=dp[i-1][j-1]+1;
					}
					else
					{
						y=dp[i-1][j-1];
					}
				}
				else
				{
					y=-10000;
				}
				dp[i][j]=max(x,y);
			}
		}
		if(dp[n][m]<0)dp[n][m]=0;
		printf("%d\n",dp[n][m]);
	}
}
