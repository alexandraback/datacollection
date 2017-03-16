#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 10005;

int v[N];
int E, T, R, n;

void dfs(int depth, int curE, int curV, int &maxV)
{
	if (depth == n) {
		maxV = max(maxV, curV);
		return;
	}
	for (int i = 0; i <= curE; ++i) 
		dfs(depth + 1, min(E, curE - i + R), curV + v[depth] * i, maxV);
}
void work()
{
	scanf("%d%d%d", &E, &R, &n);
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
	int res = 0;
	dfs(0, E, 0, res);
	static int ttt = 0;
	printf("Case #%d: %d\n", ++ttt, res);
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	while (T--) work();
}
