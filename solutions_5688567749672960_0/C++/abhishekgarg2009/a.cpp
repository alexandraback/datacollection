#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;
long long dp[1000006];
long long findrev(long long a)
{
	long long b = 0;
	while(a)
	{
		b = b*10;
		b = b + a%10;
		a = a/10;
	}
	return b;
}
int main()
{
	int t;
	long long n;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		memset(dp,0,sizeof(dp));
		for(long long j=1;j<=1000000;j++)
		{
			dp[j]= j;
		}
		//cout<<"dp[n] : "<<dp[n]<<"\n";
		for(int k=0;k<3;k++)
		{	
			for(long long j=2;j<=n;j++)
			{
				//if(j==n)
				//cout<<"j : "<<j<<"\n";
				//	cout<<"dp[j] : "<<dp[j]<<"\n";
				//if(j==n)
				//{
					//cout<<"findrev(j) : "<<findrev(j)<<"\n";
				//}
				if(j%10!=0)
				dp[j] = min(dp[j],min(dp[j-1]+1,dp[findrev(j)]+1));
				else
				dp[j] = min(dp[j],dp[j-1]+1);
				//if(j==n)
					//cout<<"dp[j] : "<<dp[j]<<"\n";
			}
		}
		printf("Case #%d: %lld\n",i,dp[n]);
	}
	return 0;
}