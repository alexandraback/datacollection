#include <stdio.h>
#include <vector>
#include <set>

using std::vector;
using std::set;
typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < set < int > > vsi;

static const int MAXN = 1024;
int color[MAXN] = {0, };
int cc = 1;
vi top;

void init(void) {
	top.clear();
	memset(color, 0, MAXN * sizeof(int));
	cc = 1;
}

void read(void) {
}

void dfs(int v, vvi &adj) {
	color[v] = cc;
	int M = adj[v].size();
	for (int i = 0; i < M; ++i) {
		if (!color[adj[v][i]]) {
			dfs(adj[v][i], adj);
		}
	}
	top.push_back(v);
}

bool dfs1(int v, vvi &adj, set < int > &black) {
	color[v] = cc;
	int M = adj[v].size();
	for (int i = 0; i < M; ++i) {
		int u = adj[v][i];
		if (black.end() == black.find(u)) {
			black.insert(u);
		} else {
			return false;
		}
		if (!color[u]) {
			if (!dfs1(adj[v][i], adj, black)) {
				return false;
			}
		}
	}

	return true;
}

void solve(void) {
	int N = 0;
	vvi adj;
	scanf("%d", &N);
	int edges = 0;
	for (int i = 0; i < N; ++i) {
		vi cur;
		int M = 0;
		scanf("%d", &M);
		for (int j = 0; j < M; ++j) {
			int v = 0;
			scanf("%d", &v);
			cur.push_back(--v);
			++edges;
		}
		adj.push_back(cur);
	}

	/*for (int i = 0; i < N; ++i) {
		int M = adj[i].size();
		for (int j = 0; j < M; ++j) {
			adj[j].push_back(i);
		}
	}*/

	for (int i = 0; i < N; ++i) {
		if (!color[i]) {
			dfs(i, adj);
			++cc;
		}
	}
	--cc;

	cc = 1;
	for (int i = N - 1; i >= 0; --i) {
		memset(color, 0, MAXN * sizeof(int));
		set < int > black;
		if (!color[top[i]]) {
			black.insert(top[i]);
			if (!dfs1(top[i], adj, black)) {
				puts("Yes");
				return;
			}
			++cc;
		}
	}

	puts("No");

	/*if (edges != N - cc) {
		puts("Yes");
	} else {
		puts("No");
	}*/
}

int main(void) {
	freopen("a.in", "rt", stdin);
	freopen("a.out", "wt", stdout);

	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		init();
		read();
		solve();
	}

	fcloseall();

	return 0;
}
