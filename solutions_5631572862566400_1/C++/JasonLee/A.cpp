//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
typedef long long LL;
using namespace std;
#define MAXN 1010
vector<int> a[MAXN];
vector<int> b[MAXN];
bool vis[MAXN];
int current;
bool ok[MAXN][MAXN];
int dp[MAXN];
void dfs(int x, int depth, int start) {
	vis[x] = true;
	for (int i = 0; i < a[x].size(); ++i) {
		int y = a[x][i];
		if (vis[y]) {
			if (y == start) {
				current = max(current, depth);
			}
			continue;
		}
		dfs(y, depth + 1, start);
	}
}
int gao0(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(vis, false, sizeof(vis));
		current = 0;
		dfs(i, 1, i);
		ans = max(ans, current);
		//cout << i << ": " << current << endl;
	}
	return ans;
}
void dfs1(int x, int depth) {
	current = max(current, depth);
	vis[x] = true;
	for (int i = 0; i < b[x].size(); ++i) {
		int y = b[x][i];
		if (vis[y] || (ok[x][y] && ok[y][x])) {
			continue;
		}
		dfs1(y, depth + 1);
	}
}
int gao1(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (ok[i][j] && ok[j][i]) {
				ans += dp[i] + dp[j];
			}
		}
	}
	return ans;
}
int main() {
	int T;
	string path = "/Users/baidu/Downloads/";

	//change file name
	string in = "C-large.in";
	string out = "c.txt";

	freopen((path + in).c_str(), "r", stdin);
	freopen((path + out).c_str(), "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		for (int i = 0; i < MAXN; i++) {
			a[i].clear(), b[i].clear();
		}
		memset(ok, false, sizeof(ok));
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			a[i].push_back(x);
			b[x].push_back(i);
			ok[i][x] = true;
		}
		for (int i = 1; i <= n; i++) {
			memset(vis, false, sizeof(vis));
			current = 0;
			dfs1(i, 1);
			dp[i] = current;
		}
		int res = max(gao0(n), gao1(n));
		cout << "Case #" << t << ": " << res << endl;
	}
	return 0;
}
