#include <stdio.h>
#include <string.h>

#define MAXN 1010

int n;
int mp[MAXN][MAXN];
int d[MAXN];
bool used[MAXN];

bool dfs(int u) {
	used[u] = true;
	for(int v = 1; v <= n; ++v) if(mp[u][v]) {
		if(used[v] || dfs(v)) return true;
	}
	return false;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		printf("Case #%d: ", cas);
		scanf("%d", &n);
		memset(mp, 0, sizeof(mp));
		memset(d, 0, sizeof(d));
		bool ok = false;
		for(int i = 1; i <= n; ++i) {
			int cnt;
			scanf("%d", &cnt);
			while(cnt--) {
				int j;
				scanf("%d", &j);
				mp[i][j]++;
				if(mp[i][j] > 1) ok = true;
				++d[j];
			}
		}

		for(int i = 1; i <= n && !ok; ++i) if(d[i] == 0) {
			memset(used, false, sizeof(used));
			ok = dfs(i);
		}
		puts(ok? "Yes": "No");
	}
	return 0;
}
