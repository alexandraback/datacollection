/*
 * Author: rush
 * Filename: A.cpp
 * Timestamp: 06/05/2012 17:07:38 CST
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long LL;

int T, N;
vector<int> son[1005];

bool vis[1005];
bool dfs(int x) {
	if (vis[x]) return true;
	vis[x] = true;
	FOR(i, SZ(son[x])) {
		int y = son[x][i];
		if (dfs(y)) return true;
	}
	return false;
}

int main() {
	scanf("%d", &T);
	for (int id = 1; id <= T; ++id) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			int m;
			scanf("%d", &m);
			son[i].resize(m);
			FOR(j, m) scanf("%d", &son[i][j]);
		}
		bool has = false;
		for (int i = 1; i <= N; ++i) {
			memset(vis, false, sizeof(vis));
			if (dfs(i)) {
				has = true;
				break;
			}
		}
		printf("Case #%d: %s\n", id, has ? "Yes" : "No");
	}
	return 0;
}
