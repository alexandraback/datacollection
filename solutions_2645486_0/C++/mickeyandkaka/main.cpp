#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define clr(a,b)    (memset(a,b,sizeof(a)))
#define rep(i,a)    for(int i=0; i<(int)a.size(); i++)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;

int dp[22][22];
int e,r,n,T;
int v[22];

int main()
{
	freopen("D:\\B-small-attempt0.in","r",stdin);
	freopen("D:\\out.txt","w",stdout);

	int cas = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&e,&r,&n);
		for(int i=1; i<=n; i++)	scanf("%d",&v[i]);
		clr(dp, -1);
		dp[0][e] = 0;

		for(int i=1; i<=n; i++)
		{
			for(int k=0; k<=e; k++)
			{
				if(dp[i-1][k] == -1)	continue;
				for(int p=0; p<=k; p++)
				{
					int t = min(k-p+r, e);
					dp[i][t] = max(dp[i][t], dp[i-1][k] + v[i]*p);
				}
			}
		}
		int ans = 0;
		for(int i=0; i<=e; i++)	ans = max(ans, dp[n][i]);
		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
}
