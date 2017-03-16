#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int TestCase, n, m, id[60];
bool g[60][60], v[60], b[60];
int stack[60], top, cnt;

void dfs(int i)
{
	for (int j = 1; j <= n; j ++)
	if (g[i][j] && !b[j]) {
		b[j] = true;
		cnt ++;
		dfs(j);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TestCase);
	for (int Case = 1; Case <= TestCase; Case ++) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &id[i]);
		}
		id[0] = 1000000;
		memset(v, 0, sizeof(v));
		memset(g, 0, sizeof(g));
		for (int i = 0; i < m; i ++) {
			int x, y;
			scanf("%d%d", &x, &y);
			g[x][y] = g[y][x] = true;
		}
		int s = 0;
		for (int i = 1; i <= n; i ++)
		if (id[i] < id[s]) {
			s = i;
		}
		printf("Case #%d: %d", Case, id[s]);
		v[s] = true;
		stack[0] = s;
		top = 0;
		for (int i = 1; i < n; i ++) {
			memcpy(b, v, sizeof(v));
			cnt = i;
			int k = 0;
			for (;k <= top; k ++) {
				dfs(stack[k]);
				if (cnt == n) {
					break;
				}
			}
			s = 0;
			for (int j = top; j >= k; j --) {
				int u = stack[j];
				for (int vv = 1; vv <= n; vv ++)
				if (g[u][vv] && !v[vv] && id[vv] < id[s]) {
					s = vv;
					top = j;
				}
			}
			v[s] = true;
			top ++;
			stack[top] = s;
			printf("%d",id[s]);
		}
		printf("\n");
	}
	return 0;
}
