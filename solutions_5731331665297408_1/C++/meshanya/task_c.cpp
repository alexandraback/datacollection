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
#define taskname "task_c"
const ldb pi = acos(-1.0);
const int N = 55;
bool marked[N], entered[N], bad[N], adj[N][N];
int t, n, m, value[N], u, v;

void mark(int v) {
	if (bad[v] || marked[v]) return;
	marked[v] = true;
	for (int i = 0; i < n; ++i)
		if (adj[v][i]) mark(i);
}

int main() {
	assert(freopen(taskname".in", "r", stdin));
	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &value[i]);
		memset(adj, 0, sizeof(adj));
		memset(bad, 0, sizeof(bad));
		memset(entered, 0, sizeof(entered));
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v), --u, --v;
			adj[u][v] = adj[v][u] = true;
		}
		int start = 0;
		for (int i = 0; i < n; ++i)
			if (value[i] < value[start]) start = i;
		vector<int> path, res;
		path.pb(start);
		res.pb(value[start]);
		while (true) {
			int v = path.back(), best = -1;
			entered[v] = true;
			for (int i = sz(path) - 1; i >= 0; --i) {
				for (int j = 0; j < n; ++j)
					if (!entered[j] && adj[path[i]][j])
						if ((best == -1) || (value[best] > value[j]))
							best = j;
				bad[path[i]] = true;
				memset(marked, 0, sizeof(marked));
				mark(start);
				bool good = true;
				for (int j = 0; j < n; ++j)
					if (!entered[j] && !marked[j]) {
						good = false;
						break;
					}
				if (!good) break;
			}
			if (best == -1) break;
			for (int i = sz(path) - 1; i >= 0; --i)
				bad[path[i]] = false;
			while (!adj[path.back()][best]) {
				bad[path.back()] = true;
				path.pop_back();
			}
			path.pb(best);
			res.pb(value[best]);
		}
		printf("Case #%d: ", it + 1);
		for (int i = 0; i < n; ++i)
			printf("%d", res[i]);
		printf("\n");
	}
	return 0;
}