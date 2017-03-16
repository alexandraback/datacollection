#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;

int n;

pair<int, int> zips[55];
bool adj[55][55];
vector<int> neigh[55];

int visited2[55];
int stack2[55];
int spos2 = 0;

void dfs(int v) {
	visited2[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int w = neigh[v][i];
		if (!visited2[w]) {
			dfs(w);
		}
	}
}

bool can_finish_dfs() {
	for (int i = 0; i < spos2; i++) {
		dfs(stack2[i]);
	}
	for (int i = 0; i < n; i++) {
		if (!visited2[i]) {
			return false;
		}
	}
	return true;
}

bool visited[55];
int stack[55];
int spos = 0;

int ans[55];

int attempt(int v) {
	for (int i = 0; i < n; i++) {
		visited2[i] = visited[i];
		stack2[i] = stack[i];
	}
	spos2 = spos;

	bool okay = false;
	int val;
	for (int i = spos-1; i >= 0; i--) {
		if (adj[stack[i]][v]) {
			okay = true;
			spos2 = i+1;
			val = spos2;
			break;
		}
	}
	if (!okay) {
		return -1;
	}

	stack2[spos2++] = v;
	visited2[v] = true;

	if (can_finish_dfs()) {
		return val;
	} else {
		return -1;
	}
}

void solve() {
	int m;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &zips[i].first);
		zips[i].second = i;

		visited[i] = false;
		for (int j = 0; j < n; j++) {
			adj[i][j] = false;
		}
		neigh[i].clear();
	}
	sort(zips, zips+n);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		a--; b--;
		adj[a][b] = true;
		adj[b][a] = true;
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}

	int fv = zips[0].second;
	visited[fv] = true;
	stack[0] = fv;
	spos = 1;

	ans[0] = zips[0].first;

	for (int nvisited = 1; nvisited < n; nvisited++) {
		bool okay = true;
		for (int i = 0; i < n; i++) {
			int v = zips[i].second;
			if (!visited[v]) {
				int whereto = attempt(v);
				if (whereto != -1) {
					ans[nvisited] = zips[i].first;

					spos = whereto;
					stack[spos++] = v;
					visited[v] = true;

					okay = true;
					break;
				}
			}
		}
		assert(okay);
	}

	for (int i = 0; i < n; i++) {
		printf("%d", ans[i]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}
