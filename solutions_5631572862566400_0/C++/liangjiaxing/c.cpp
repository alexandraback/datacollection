#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int p[MAXN], vis[MAXN];
vector<int> e[MAXN];

int dfs(int m, int parent) {
	int t = 0;
	for (int i = 0; i < e[m].size(); i++) {
		int j = e[m][i];
		if (j != parent) {
			t = max(t, dfs(j, m));
		}
	}
	return t + 1;
}

int main() {
	int cas;
	scanf("%d", &cas);
	for (int re = 1; re <= cas; re++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			e[i].clear();
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			p[i]--;
			e[p[i]].push_back(i);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (p[p[i]] == i) {
				ans += dfs(i, p[i]);
			}
		}
		
		for (int i = 0; i < n; i++) {
			int k = i;
			int t = 0;
			memset(vis, 0, sizeof(vis));
			while (!vis[k]) {
				t++;
				vis[k] = t;
				k = p[k];
			}
			//printf("i = %d, k = %d, t = %d\n", i, k, t);
			ans = max(ans, t - vis[k] + 1);
		}
		printf("Case #%d: %d\n", re, ans);
	}
}