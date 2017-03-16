#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> a[2000];
int mark[2000];
int b[2000];
int c[2000];

int dfs(int u, int x) {
	int res = 1;
	for (int i = 0; i < a[u].size(); ++i) 
	if (x != a[u][i]) {
		res = max(res, dfs(a[u][i], u) + 1);
	}

	return res;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.txt", "w", stdout);
	int T, n;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		for (int i = 0; i < 2000; ++i) {
			a[i].clear();
			mark[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			b[i] = x;
			a[x].push_back(i);
		}
		int res = 0;
		int circle = 0;
		
		for (int i = 1; i <= n; ++i) {
			if (b[b[i]] == i && i < b[i]) {
				res += dfs(i, b[i]) + dfs(b[i], i);
			}
		}

		for (int i = 1; i <= n; ++i) 
		if (!mark[i]) {
			int x = i;
			mark[x] = 1;
			c[x] = i;
			while (!mark[b[x]]) {
				mark[b[x]] = mark[x] + 1;
				x = b[x];
				c[x] = i;
			}

			if (c[b[x]] == i)
				circle = max(circle, mark[x] - mark[b[x]] + 1);
		}

		res = max(res, circle);

		printf("Case #%d: %d\n", t, res);
	}
}
