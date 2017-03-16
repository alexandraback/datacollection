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

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >


void precompute(void)
{
}
int dp[16][16],n;
int E,R,v[16];
int rec(int cur,int energy)
{
	if(dp[cur][energy]==-1)
	{
		int &ret=dp[cur][energy];
		ret=0;
		if(cur!=n)
		{
			for(int i=0;i<=energy;i++)
				ret=max(ret,v[cur]*i+rec(cur+1,min(E,energy+R-i)));
		}
	}
	return dp[cur][energy];
}

int main()
{
	int t,test;
	precompute();
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			test++;
			printf("Case #%d: ",test);
			fprintf(stderr,"Case #%d: ",test);
		
			scanf("%d%d%d",&E,&R,&n);
			for(int i=0;i<n;i++)
				scanf("%d",&v[i]);

			memset(dp,-1,sizeof(dp));
			int ans=rec(0,E);
			printf("%d\n",ans);
			fprintf(stderr,"%d\n",ans);
		}
	}
	return 0;
}
