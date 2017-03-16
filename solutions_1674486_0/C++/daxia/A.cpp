#include<cstdio>
#include<cstring>
int g[1000][1000], b[1000], n, f;
void dfs(int i) {
	int j;
	if (b[i]) {
		f = 1;
		return;
	}
	b[i]++;
	for (j = 0; j < n; j++)
		if (g[i][j])dfs(j);
}
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int t, tt;
	int i, j, k;
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++) {
		printf("Case #%d: ", t);
		scanf("%d", &n);
		memset(g, 0, sizeof(g));
		for (i = 0; i < n; i++) {
			scanf("%d", &k);
			while (k--) {
				scanf("%d", &j);
				j--;
				g[i][j] = 1;
			}
		}
		f = 0;
		for (i = 0; i < n; i++) {
			memset(b, 0, sizeof(b));
			dfs(i);
			if (f)break;
		}
		printf(f ? "Yes\n" : "No\n");
	}
	return 0;
}
