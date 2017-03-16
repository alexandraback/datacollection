#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n;
std::vector<int> from[1001];
int vis[1001];

void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < from[u].size(); i++) {
		if (!vis[from[u][i]]) {
			dfs(from[u][i]);
		} else {
			vis[from[u][i]] = 2;
		}
	}
}

int main() {
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++) {
		printf("Case #%d: ", tt);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int m;
			from[i].clear();
			scanf("%d", &m);
			int x;
			for (int j = 0; j < m; j++) {
				scanf("%d", &x);
				from[i].push_back(x - 1);
			}
		}
		bool yes = false;
		for (int i = 0; i < n; i++) {
			memset(vis, 0 ,sizeof(vis));
			dfs(i);
			for (int j = 0; j < n; j++) {
				if (vis[j] > 1) {
					yes = true;
					break;
				}
			}
			if (yes) break;
		}
		if (yes)
			printf("Yes\n");
		else
			printf("No\n");
	}
}