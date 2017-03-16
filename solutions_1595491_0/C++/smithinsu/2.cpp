#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;
#define PB push_back
#define INF 1000000000
#define MOD 1000000007


int possible[512][128][2];
void precompute(void)
{
	int i,j,k,sur,l;
	for(i=0;i<512;i++)
	{
		for(j=0;j<128;j++)
		{
			for(k=0;k<2;k++)
			{
				possible[i][j][k]=0;
			}
		}
	}
	for(i=0;i<128;i++)
	{
		for(j=i;j<128&&j<=i+2;j++)
		{
			for(k=j;k<128&&k<=j+2&&k<=i+2;k++)
			{
				sur=0;
				if(j>i+1||k>i+1||k>j+1)
					sur=1;
				else
					sur=0;
			//	printf("%d %d %d\n",i+j+k,k,sur);
				for(l=k;l>=0;l--)
				{
					possible[i+j+k][l][sur]=1;
				}
			}
		}
	}
}

int t,memo[128][128],n,p,total[128];

int rockers(int cur,int rem)
{
	if(rem<0)
		return -(n+10);
	if(memo[cur][rem]!=-1)
		return memo[cur][rem];
	if(cur==n)
	{
		if(rem==0)
			return 0;
		return -(n+10);
	}
//	printf("%d %d\n",cur,rem);
//	printf("without %d with %d\n",possible[total[cur]][p][0],possible[total[cur]][p][1]);
	return max(rockers(cur+1,rem)+possible[total[cur]][p][0],rockers(cur+1,rem-1)+possible[total[cur]][p][1]);
}

int main()
{
	int i;
	precompute();
	int s,test;
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			memset(memo,-1,sizeof(memo));
			scanf("%d %d %d",&n,&s,&p);
			for(i=0;i<n;i++)
				scanf("%d",&total[i]);
			test++;
			printf("Case #%d: %d\n",test,rockers(0,s));
		}
	}
	return 0;
}
