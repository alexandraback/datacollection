#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <functional>
#include <string>

using namespace std;

//	Pairs
#define MP make_pair
#define F first
#define S second
typedef pair<int, int> ii;

// Vectors
#define PB push_back
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX 1005

vector<vector<int> > v(MAX);

void add(int a, int b) { v[a].push_back(b); }
bool found;
vector<bool> visited(MAX);

void dfs(int node, int p) {
	for (int i=0; i<v[node].size(); i++)
		if (!visited[ v[node][i] ]) {
			visited[ v[node][i] ] = true;
			dfs( v[node][i], node );
			if (found) return;
		} else if (v[node][i] != p) { found = true; return; }
}

int main() {
	//freopen("a.in", "r", stdin);
	int tst, m, a, n;

	scanf("%d", &tst);
	for (int t=1; t<=tst; t++) {
		scanf("%d", &n);
		for (int i=1; i<=n; i++) {
			scanf("%d", &m);
			for (int j = 1; j<=m; j++) { scanf("%d", &a); add(i, a); }
		}

		for (int i=1; i<=n; i++) {
			found = false;
			for (int j=1; j<=n; j++) visited[j] = false;
			dfs(i, -1);
			if (found) { printf("Case #%d: Yes\n", t); break; }
		}

		if (!found) printf("Case #%d: No\n", t);

		for (int i=1; i<=n; i++) v[i].clear();

	}
	return 0;
}

