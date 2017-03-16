#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())

const int MAXINT = -1u>>1;

int used[1010];

vector<int> e[1010];
int n;

int dfs(int u) {
	if (used[u]) return 1;
	used[u] = 1;
	for (int i=0; i<(int)e[u].size(); ++i) {
		if(dfs(e[u][i])) return 1;
	}
	return 0;
}

void solve() {
	for (int i=1; i<=n; ++i) {
		memset(used, 0, sizeof(used));
		if (dfs(i)) {
			puts("Yes");
			return;
		}
	}
	puts("No");
}


int main() {
	int z, m, t;
	scanf("%d", &z);
	for (int ca=1; ca<=z; ++ca) {
		printf("Case #%d: ", ca);
		scanf("%d", &n);
		for (int i=0; i<=n; ++i) {
			e[i].clear();
		}
		for (int i=1; i<=n; ++i) {
			scanf("%d", &m);
			for (int j=0; j<m; ++j) {
				scanf("%d", &t);
				e[i].push_back(t);
			}
		}
		solve();
	}
    return 0;
}

