#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <stack>
#include <deque>
#include <cmath>
#define SIZE 20
#define MX 1000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll digit[SIZE];
int dp[MX];

int get(int n)
{
	int sz=0;
	while(n>0)
	{
		digit[sz++]=n%10;
		n/=10;
	}
	ll ret=0,t=1;
	for(int i=sz-1;i>=0;i--)
	{
		ret+=digit[i]*t;
		t*=10LL;
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	dp[1]=1;
	queue <int> que;
	que.push(1);
	while(!que.empty())
	{
		int n=que.front();que.pop();
		if(n+1<MX&&dp[n+1]==-1)
		{
			dp[n+1]=dp[n]+1;
			que.push(n+1);
		}
		int m=get(n);
		if(m<MX&&dp[m]==-1)
		{
			dp[m]=dp[n]+1;
			que.push(m);
		}
	}
	for(int t2=1;t2<=T;t2++)
	{
		ll n;
		scanf("%lld",&n);
		printf("Case #%d: %d\n",t2,dp[n]);
	}
	return 0;
}
