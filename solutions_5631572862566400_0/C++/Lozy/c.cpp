#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
int T, ans;
const int N = 1111;
vector<int> G[N], sig[N];
bool vis[N];
int step[N], lk[N];
void dfs(int x, int t) {
	vis[x] = 1;
	step[x] = t;
	for (int i = 0; i < G[x].size(); ++i) {
		int k = G[x][i];
		if (!vis[k]) dfs(k, t + 1);
		else {
			int temp = step[x] - step[k] + 1;
			ans = max(temp, ans);
		}
	}
}
typedef pair<int, int> P;
int bfs(int x) {
	int res = 0;
	queue<P> que;
	vis[lk[x]] = true;
	vis[x] = true;
	for (int i = 0; i < sig[x].size(); ++i) {
		int k = sig[x][i];
		if (!vis[k]) {
			vis[k] = true;
			que.push(P(k, 1));
		}
	}
	while (!que.empty()) {
		P cur = que.front(); que.pop();
		res = cur.second;
		for (int i = 0; i < sig[cur.first].size(); ++i) {
			int k = sig[cur.first][i];
			if (vis[k]) continue;
			vis[k] = true;
			que.push(P(k, cur.second + 1));
		}
	}
	return res;
}
int n, x;
int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &n);
		for (int i = 0; i < N; ++i) {
			G[i].clear();
			sig[i].clear();
		}
		memset(vis, 0, sizeof(vis));
		memset(step, 0, sizeof(step));
		memset(lk, 0, sizeof(lk));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &x);
			G[i].push_back(x);
			G[x].push_back(i);
			sig[x].push_back(i);
			lk[i] = x;
		}
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) dfs(i, 1);
		}
		for (int i = 1; i <= n; ++i) {
			if (i != lk[lk[i]]) continue;
			memset(vis, 0, sizeof(vis));
			ans = max(ans, 2 + bfs(i) + bfs(lk[i]));
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}