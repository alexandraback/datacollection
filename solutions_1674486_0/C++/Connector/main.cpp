#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <memory.h>
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
using namespace std; 

const int inf = 1000*1000*1000; 
#define CL(x,a) memset(x,a,sizeof(x)); 
#define ALL(v) (v).begin(),(v).end() 
#define PII pair<int,int> 
#define PDI pair<double,int> 
#define MP(a,b) make_pair(a,b) 
#define FOR(i,n) for(int i=0;i<n;i++) 
typedef long long LL; 
typedef vector<int> vi; 
typedef vector< vi > vvi; 
typedef vector< vector<PII > > vvpii; 

vector< vector<int> > g;
int n;
int gX;
int dp[1024];
int DP(int x)
{
	if (x == gX)
		return 1;
	if (dp[x] != -1)
		return dp[x];
	int res = 0;
	for (int i=0;i<g[x].size();i++)
	{
		res += DP(g[x][i]);
		res = min(res,2);
	}
	return dp[x] = res;
}
void Solve()
{
	scanf("%d",&n);
	g.clear();
	g.assign(n,vector<int>());
	FOR(i,n)
	{
		int m;
		scanf("%d",&m);
		FOR(j,m)
		{
			int t;
			scanf("%d",&t);
			t--;
			g[i].push_back(t);
		}
	}
	for (int i=0;i<n;i++)
	{
		gX = i;
		CL(dp,-1);
		for (int j=0;j<n;j++)
		{
			if (i == j)
				continue;
			if (DP(j) == 2)
			{
				printf("Yes\n");
				return;
			}
		}
	}
	printf("No\n");
}
int main() 
{ 
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	FOR(i,T)
	{
		printf("Case #%d: ",i+1);
		Solve();
	}
	return 0; 
}
