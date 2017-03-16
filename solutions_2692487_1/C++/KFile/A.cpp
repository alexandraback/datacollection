#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <set>
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

int T, A, N, uku[111];
map<PII, int> dp;

int solve(int now, int cur)
{
	if(now == N) return 0;
	if(dp.count(mp(now, cur))) return dp[mp(now, cur)];
	
	int &ret = dp[mp(now, cur)] = INF;
	if(cur > uku[now]) ret = min(ret, solve(now + 1, cur + uku[now])); else
		ret = min(ret, min(solve(now, 2 * cur- 1), solve(now + 1, cur)) + 1);
		
	return ret;
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d", &A, &N);
		for(int i = 0; i < N; i++) scanf("%d", &uku[i]);
		sort(uku, uku + N);
		
		dp.clear();
		printf("Case #%d: %d\n", t, solve(0, A));
	}
	return 0;
}

