#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_c_slow"
const ldb pi = acos(-1.0);
const int N = 8;
bool adj[N][N];
int n, m, t, u, v, value[N], p[N];

int main() {
	assert(freopen(taskname".in", "r", stdin));
	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d", &n, &m);
		memset(adj, 0, sizeof(adj));
		for (int i = 0; i < n; ++i) {
			scanf("%d", &value[i]);
			p[i] = i;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v), --u, --v;
			adj[u][v] = adj[v][u] = true;
		}
		vector<int> best;
		do {
			vector<int> path, res;
			path.pb(p[0]), res.pb(value[p[0]]);
			bool bad = false;
			for (int i = 1; i < n; ++i) {
				while (!path.empty() && !adj[path.back()][p[i]])
					path.pop_back();
				if (path.empty()) {
					bad = true;
					break;
				}
				path.pb(p[i]);
				res.pb(value[p[i]]);
			}
			if (!bad && (best.empty() || (best > res))) best = res;
		} while (next_permutation(p, p + n));
		printf("Case #%d: ", it + 1);
		for (int i = 0; i < n; ++i)
			printf("%d", best[i]);
		printf("\n");
	}
	return 0;
}