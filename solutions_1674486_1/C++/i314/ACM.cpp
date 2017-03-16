#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#define MAXN 1003
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

vector<int> g[MAXN];
int cnt[MAXN], od[MAXN];
int n;
int path[MAXN];

bool bfs(int s) {
	queue<int> q;
	for(int i=1; i<=n; ++i) {
		od[i] = 0;
		path[i] = 0;
	}
	q.push(s);
	path[s] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=g[u].size()-1; i>=0; --i) {
			int v = g[u][i];
			++od[v];
			path[v] += path[u];
			if(od[v] == cnt[v]) {
				q.push(v);
			}
		}
	}

	for(int i=1; i<=n; ++i) {
		if(path[i] > 1) {
			return true;
		}
	}
	return false;
}

bool flag[MAXN];
bool dfs(int u) {
	flag[u] = true;
	for(int i=g[u].size()-1; i>=0; --i) {
		int v= g[u][i];
		if(!flag[v]) {
			if(dfs(v)) {
				return true;
			}
		} else {
			return true;
		}
	}
	return false;
}

bool solve() {
	for(int i=1; i<=n; ++i) {
		memset(flag, 0, sizeof(flag));
		if(dfs(i)) {
			return true;
		}
		if(bfs(i)) {
			return true;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif

	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) {
			g[i].clear();
			cnt[i] = 0;
		}
		for(int i=1, m, v; i<=n; ++i) {
			scanf("%d", &m);
			while(m--) {
				scanf("%d", &v);
				g[i].push_back(v);
				++cnt[v];
			}
		}
		printf("Case #%d: %s\n", cas, solve()? "Yes": "No");
	}

	return 0;
}
