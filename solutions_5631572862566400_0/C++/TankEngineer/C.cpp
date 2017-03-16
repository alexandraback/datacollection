#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;

vector<int> edge[N];

int n, fa[N];

bool vis[N];

int getLen(int u) {
	int ret = 1;
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i];
		if (v == fa[u]) {
			continue;
		}
		ret = max(ret, 1 + getLen(v));
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		static int id = 0;
		printf("Case #%d: ", ++id);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			edge[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", fa + i);
			--fa[i];
			edge[fa[i]].push_back(i);
			vis[i] = false;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				int u = i;
				while (!vis[u]) {
					vis[u] = true;
					u = fa[u];
				}
				int v = u, tmp = 0;
				do {
					v = fa[v];
					++tmp;
				} while (v != u && tmp < n + 1);
				if (tmp <= n) {
					ans = max(ans, tmp);
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (fa[fa[i]] == i && i < fa[i]) {
				sum += getLen(i) + getLen(fa[i]);
			}
		}
		ans = max(ans, sum);
		printf("%d\n", ans);
	}
	return 0;
}
