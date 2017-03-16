#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

int T,N,M,i,j,k;
int dp[1010];
vector<int> adjlist[1010];

int solve(int now)
{
	if(now==k) return 1;
	if(dp[now]!=-1) return dp[now];
	
	int &ret = dp[now]= 0;
	for(int x=0;x<adjlist[now].size();x++)
		ret+=solve(adjlist[now][x]);
	return ret;
}

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		for(j=1;j<=N;j++)
		{
			adjlist[j].clear();
			scanf("%d",&M);
			while(M--)
			{
				scanf("%d",&k);
				adjlist[j].pb(k);
			}
		}
		
		bool ada = false;
		for(j=1;j<=N && !ada;j++)
			for(k=1;k<=N && !ada;k++) if(j!=k)
			{
				memset(dp,-1,sizeof(dp));
				if(solve(j)>1) ada=true;
			}
			
		printf("Case #%d: %s\n",i,ada?"Yes":"No");
	}
	return 0;
}

