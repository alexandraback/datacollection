#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;


int TC;
int n;
vector<int> g;
vector<vector<int>> h;

vector<bool> vis;
int dfs(int v) {
	if (vis[v]) return 0;
	vis[v] = true;
	int ans = 0;
	for(auto w : h[v]) {
		ans = max(ans, dfs(w));
	}
	return ans + 1;
}
void solve() {
	cin >> n;
	g.clear();
	h.clear();
	g.resize(n);
	h.resize(n);
	rep(i, n) {
		int a;
		cin >> a;
		a--;
		g[i] = a;
		h[a].push_back(i);
	}

	int ans = 0;
	rep(i, n) {
		vector<bool> vis(n);
		vis[i] = true;
		int v = i;
		int cnt = 0;
		while(true) {
			v = g[v];
			cnt++;
			if (i == v) {
				ans = max(cnt, ans);
				break;
			}
			if (vis[v]) break;
			vis[v] = true;
		}
	}

	int res = 0;
	rep(i, n) rep(j, i) {
		if (g[i] == j && g[j] == i) {
			int x = 0;
			vis.assign(n, false);
			vis[j] = true;
			x += dfs(i);
			vis.assign(n, false);
			vis[i] = true;
			x += dfs(j);
			res += x;
		}
	}

	ans = max(ans, res);
	cout << ans << endl;
}
int main() {
	int T; cin >> T;
	for(int TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

