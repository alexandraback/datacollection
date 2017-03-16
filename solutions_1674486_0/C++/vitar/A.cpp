#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <set>
#include <map>
using namespace std;

#define N 1005

vector<vector<int> > v(N);
int u[N];

int i, j, k, n, m, x, y, z, t, T, tt, res;
int vv, ee;

int dfs(int cur, int tg) {
	if (u[cur] != -1) {
		return u[cur];
	}
	if (cur == tg) {
		u[cur] = 1;
		return 1;
	}
	int i, x, r = 0;
	for (i = 0; i < v[cur].size(); i ++) {
		x = v[cur][i];
		r += dfs(x, tg);
	}
	if (r > 1) {
		res = 1;
	}
	return u[cur] = r;
}

int main() {
	freopen("small4.in", "r", stdin);	freopen("small4.out", "w", stdout);
	scanf("%d", &T);
	for (tt = 1; tt <= T; tt ++) {
		scanf("%d", &n);
		for (i = 0; i < N; i ++) {
			v[i].clear();
		}
		for (i = 0; i < n; i++) {
			scanf("%d", &m);
			for (j = 0; j < m; j++) {
				scanf("%d", &x);
				x --;
				v[i].push_back(x);
			}
		}
		res = 0;
		memset(u, 0, sizeof(u));
		for (i = 0; i < n; i ++) {
			memset(u, -1, sizeof(u));
			for (j = 0; j < n; j ++) {
				if (u[j] == -1) {
					dfs(j, i);
				}
			}
		}
	
		printf("Case #%d: ", tt);
		if (res == 1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}


