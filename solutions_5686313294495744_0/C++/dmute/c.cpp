#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

const int maxn = 2050;
map<string, int> num[2];
int tot[2], counter=0;
vector<int> edge[maxn];
int n, vis[maxn], lk[maxn];

int getnum(int k, string &s) {
	if (num[k].count(s)) return num[k][s];
	num[k][s] = ++ tot[k];
	if (k == 0) edge[tot[k]].clear();
	return num[k][s];
}

void add(int a, int b) {
	edge[a].push_back(b);
}

bool dfs(int x) {
	for (int y : edge[x]) {
		if (vis[y] == counter) continue;
		vis[y] = counter;
		if (!lk[y] || dfs(lk[y])) {
			lk[y] = x;
			return true;
		}
	}return false;
}

void solve(int t) {
	for (int i = 0; i < 2; i ++) {
		num[i].clear();
		tot[i] = 0;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		string s[2];
		cin >> s[0] >> s[1];
		add(getnum(0, s[0]), getnum(1, s[1]));
	}
	memset(vis, 0, sizeof vis);
	memset(lk, 0, sizeof lk);
	counter=0;
	int ans = tot[0] + tot[1];
	for (int i = 1; i <= tot[0]; i ++) {
		++ counter;
		if (dfs(i)) ans --;
	}
	printf("Case #%d: %d\n", t, max(0, n - ans));
	for (int i = 0; i <= tot[0]; i ++) edge[i].clear();
}

int main() {
	int tst;
	scanf("%d", &tst);
	for (int t = 1; t <= tst; t ++) {
		solve(t);
	}
	return 0;
}