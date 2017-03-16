#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 10+5;
int T, E, R, N, v[MAXN], sum, ans;
void dfs(int n, int e)
{
	if (n > N)
	{
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i <= e; i++)
	{
		sum += i*v[n];
		dfs(n+1, min(e-i+R, E));
		sum -= i*v[n];
	}
}
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &v[i]);
		sum = ans = 0;
		dfs(1, E);
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
