#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <valarray>
#include <ctime>
#include <set>
#include <sstream>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
typedef unsigned long long ull;
typedef vector<int> vi;

#define x first
#define y second
#define mp make_pair

vi g[1005];
bool used[1005];

bool dfs(int v) {
	bool res = false;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (used[u]) {
			return true;
		}
		used[u] = true;
		res |= dfs(u);
	}
	return res;
}

void solution() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		g[i].clear();
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			int u;
			scanf("%d", &u);
			--u;
			g[i].push_back(u);
		}
	}

	bool res = false;
	for (int i = 0; i < n; ++i) {
		memset(used, 0, n * sizeof(bool));
		used[i] = true;
		
		for (int j = 0; j < g[i].size(); ++j) {
			used[g[i][j]] = true;
		}		
		for (int j = 0; j < g[i].size(); ++j) {
			res = dfs(g[i][j]);
			if (res) {
				break;			
			}
		}
		if (res) {
			break;
		}
	}
	if (res) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

int main() {

//	freopen("in.in", "rt", stdin);
	//freopen("out.out", "wt", stdout);

	freopen("A-small.in", "rt", stdin);
	freopen("A-small.out", "wt", stdout);

	//freopen("A-large.in", "rt", stdin);
	//freopen("A-large.out", "wt", stdout);

	/*freopen("B-small.in", "rt", stdin);
	freopen("B-small.out", "wt", stdout);*/

	//freopen("B-large.in", "rt", stdin);
	//freopen("B-large.out", "wt", stdout);


	//freopen("C-small.in", "rt", stdin);
	//freopen("C-small.out", "wt", stdout);

	//freopen("C-large.in", "rt", stdin);
	//freopen("C-large.out", "wt", stdout);
	
	int t = 0;
	scanf("%d\n", &t);
	for (int tt = 0; tt < t; tt++) {
		printf("Case #%d: ", tt + 1);
		solution();
	}

	return 0;
}