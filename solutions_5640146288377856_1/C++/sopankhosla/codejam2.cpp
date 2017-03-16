#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int dp[21][21][21];
	int t,cas=0;
	for(int j=1;j<21;j++)
			for(int k=1;k<21;k++)
			{
				dp[1][j][k] = (ceil((j*1.0)/k) -1 + k);
			}
	for(int i=2;i<21;i++)
		for(int j=1;j<21;j++)
			for(int k=1;k<21;k++)
			{
				dp[i][j][k] = dp[1][j][k] + (i-1)*(floor((j*1.0)/k));
			}
	scanf("%d",&t);
	while(t--)
	{
		int result=0,N,r,c,w;	
		scanf("%d %d %d",&r,&c,&w);
		printf("Case #%d: %d\n",++cas,dp[r][c][w]);		
	}
	return 0;
}
