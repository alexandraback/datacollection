#include <cstdio>
#include <vector>

using namespace std;

int n;
int flag;
vector<int> adj[1000], rev[1000];
int chk[1000];
int ind[1000];
int order;

int dfs(int ver, int prev) {
	if (flag == 0) return 0;
	chk[ver] = ++order;
	int m = chk[ver];
	for (int i = 0; i < (int)adj[ver].size(); ++i) {
		int v = adj[ver][i];
		if (chk[v]) {
			if (chk[v] < m) m = chk[v];
		} else {
			int tmp = dfs(v, ver);
			if (tmp < m) m = tmp;
		}
	}
	for (int i = 0; i < (int)rev[ver].size(); ++i) {
		int v = rev[ver][i];
		if (chk[v] && v != prev) {
			if (chk[v] < m) m = chk[v];
		}
	}
	if (m < chk[ver]) flag = 0;
//	printf("%d %d %d\n", ver, m, chk[ver]);
	return m;
}

int main() {
	int r, cs = 0;
	scanf("%d", &r);	
	while (r--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) { rev[i].clear(); ind[i] = 0; }
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; ++j) {
				int k;
				scanf("%d", &k);
				adj[i].push_back(k - 1);
				rev[k - 1].push_back(i);
				ind[k - 1]++;
			}
		}
		flag = 1;
		for (int i = 0; i < n; ++i) {
			if (ind[i] == 0) {
				order = 0;
				for (int j = 0; j < n; ++j) chk[j] = 0;
				dfs(i, -1);
			}
			if (flag == 0) break;
		}
		printf("Case #%d: ", ++cs);
		printf("%s\n", flag ? "No" : "Yes");
	}
	return 0;
}
