#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int value[20];
int n;
int kid[20][20];
bool vis[20];
int num_this;

bool dfs(int u){
	vis[u] = true;
	num_this++;
	for (int i = 0; i < n; i++) {
		if (kid[u][i] == 0) continue;
		if (!vis[i])
			dfs(i);
	}
}

int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("c.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &value[i]);
			value[i]--;
		}
		int ans = 0;
		for (int i = 0; i < (1 << n); i++) {
			memset(kid, 0, sizeof(kid));
			bool flag = true;
			int num = 0;
			for (int j = 0; j < n; j++) {
				if ((i & (1<<j)) == 0) continue;
				if ((i & (1<<value[j])) == 0) {
					flag = false;
					break;
				}
				num++;
				kid[j][value[j]] = 1;
				kid[value[j]][j] = 1;
			}
			for (int j = 0; j < n && flag; j++) {
				if ((i & (1<<j)) == 0) continue;
				int tmp = 0;
				for (int p = 0; p < n; p++) {
					if (p == j) continue;
					tmp += kid[j][p];
				}
				if (tmp > 2){
					flag = false;
					break;
				}
			}
			memset(vis, 0, sizeof(vis));
			bool first = true;
			for (int j = 0; j < n && flag; j++){
				if ((i & (1<<j)) == 0) continue;
				num_this = 0;
				dfs(j);
				if (!first && num_this > 2) {
					flag = false;
					break;
				}
				first = false;
			}
			if (flag) {
				ans = max(ans, num);
			}
		}
		printf("Case #%d: %d\n", t + 1, ans);
	}
}
