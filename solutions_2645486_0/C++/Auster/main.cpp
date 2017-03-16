#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <sstream>

using namespace std;

typedef vector<int> vint;
typedef long long LL;

int T;
int E, R, N, V[1 << 4];

int dp[1 << 4][1 << 4];

int go(int x, int e)
{
	if (x == N)
		return 0;
	int & res = dp[x][e];
	if (res != -1)
		return res;
	res = 0;
	for(int i = 0; i <= e; ++i)
	{
		int to = min(e - i + R, E);
		res = max(res, go(x + 1, to) + i * V[x]);
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int I = 1; I <= T; ++I)
	{
		printf("Case #%d: ", I);
		
		scanf("%d%d%d", &E, &R, &N);
		for(int i = 0; i < N; ++i)
			scanf("%d", &V[i]);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", go(0, E));
	}
	return 0;
}