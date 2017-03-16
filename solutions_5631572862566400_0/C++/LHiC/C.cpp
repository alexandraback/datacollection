#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 1200;
int go[MAXN];
int mx[MAXN];
int cl[MAXN];
vector<int> st;
vector<int> vv[MAXN];
int was[MAXN];
int cnt;

int dfs(int v) {
	st.push_back(v);
	was[v] = 1;
	if (was[go[v]])
		return go[v];
	return dfs(go[v]);
}

void dfs2(int v, int h) {
	if (cl[v]) {
		mx[v] = max(mx[v], h);
		return;
	}
	dfs2(go[v], h + 1);
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", go + i), --go[i];
	memset(cl, 0, sizeof(cl));
	for (int i = 0; i < n; ++i)
		vv[i].clear();
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		memset(was, 0, sizeof(was));
		st.clear();
		int k = dfs(i);
		if (cl[k])
			continue;
		for (int j = (int)st.size() - 1; j >= 0; --j) {
			cl[st[j]] = 1;
			vv[cnt].push_back(st[j]);
			if (st[j] == k)
				break;
		}
		++cnt;
	}
	for (int i = 0; i < n; ++i)
		mx[i] = 0;
	for (int i = 0; i < n; ++i) {
		dfs2(i, 0);
	}

	int ans = 0;
	int sum = 0;
	for (int i = 0; i < cnt; ++i) {
		ans = max(ans, (int)vv[i].size());
		if (vv[i].size() == 2)
			sum += 2 + mx[vv[i][0]] + mx[vv[i][1]];
	}
	ans = max(ans, sum);
	cout << ans << "\n";
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}


