#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1005
using namespace std;

int T, n, ans, t, tim, fa[N], tot, r[N], top;
int dfn[N], low[N], sta[N], vis[N];

struct edge { int t, n; } e[N];

void add(int x, int y) {
	e[++tot].t = y; e[tot].n = r[x]; r[x] = tot;
}

int dfs(int u, int s) {
	int res = s;
	for (int i = r[u]; i; i = e[i].n) if (e[i].t != fa[u]) res = max(res, dfs(e[i].t, s + 1));
	return res;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	sta[++top] = u;
	vis[u] = 1;
	if (!dfn[fa[u]]) {
		tarjan(fa[u]);
		low[u] = min(low[u], low[fa[u]]);
	} else if (vis[fa[u]]) low[u] = min(low[u], dfn[fa[u]]);
	if (dfn[u] == low[u]) {
		int t = 1;
		while (sta[top] != u) {
			t++;
			vis[sta[top--]] = 0;
		}
		ans = max(ans, t);
		vis[sta[top--]] = 0;
	}
}

int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d", &n);
		memset(r, 0, sizeof r);
		tot = 0; ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &fa[i]);
			add(fa[i], i);
		}
		memset(dfn, 0, sizeof dfn);
		for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
		t = 0;
		for (int i = 1; i <= n; i++) if (fa[fa[i]] == i) t += dfs(i, 1) + dfs(fa[i],1);
		printf("Case #%d: ", k);
		printf("%d\n", max(ans, t / 2));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}