#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 1000 + 10;

int next[MAX_N];

vector<int> edge[MAX_N];

int dfs(int u, int par) {
	int dep = 1;
	for (vector<int>::iterator e = edge[u].begin(); e != edge[u].end(); ++e) {
		if (*e != par)
			dep = max(dep, dfs(*e, u) + 1);
	}
	return dep;
}

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			edge[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			cin >> next[i];
			--next[i];
			edge[next[i]].push_back(i);
		}

		int ans = 0;
		int ans2 = 0;

		for (int i = 0; i < n; ++i) {
			//in cycle
			int x = i;
			for (int t = 1; t <= n; ++t) {
				x = next[x];
				if (x == i) {
					ans = max(ans, t);
					break;
				}
			}

			int j = next[i];
			if (next[j] == i && i < j) {
				ans2 += dfs(i, j) + dfs(j, i);
			}
		}
		ans = max(ans, ans2);

		printf("Case #%d: %d\n", nc, ans);
	}
	return 0;
}
