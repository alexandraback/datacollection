#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int _max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	freopen("T.txt", "w", stdout);
	int t,e,r,n;
	int v[23];
	int dp[55][55];
	int i,j,k;
	cin>>t;
	int ca=1;
	while(t--)
	{
		cin>>e>>r>>n;
		for(i=0;i<n;i++)
		{
			cin>>v[i];
		}
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				for(j=0;j<=e;j++)
				{
					dp[i][j+r]=v[i]*(e-j);
				}
			}
			else
			{
				for(j=0;j<=e;j++)
				{
					for(k=j;k<=e;k++)
					{
						dp[i][j+r]=_max(dp[i][j+r],dp[i-1][k]+v[i]*(k-j));
					}
				}
			}

		}
		int tmp=-1;
		for(i=0;i<=e;i++)
		{
			tmp=_max(tmp,dp[n-1][i+r]);
		}
		printf("Case #%d: %d\n",ca++,tmp);
	}
	return 0;
}
