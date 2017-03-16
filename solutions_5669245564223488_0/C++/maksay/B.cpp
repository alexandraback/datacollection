#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define VI vector<int>
#define inf 1000000000
#define L(s) ((int)(s).size())
#define x first 
#define y second
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define all(s) (s).begin(), (s).end()
int t;
int n;
string s;
const int mod = 1000000007;
VI lft[33], rgt[33], alone[33], full[33];
int g[111][111];
int u[111];

bool dfs(int v) {
	u[v] = 1;
	for(int i = 0; i < n; ++i) {
		if (g[v][i]) {
			if (u[i] == 1) return 0;
			if (!dfs(i)) return 0;
		}
	}
	u[v] = 2;
	return 1;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for(int tc = 1; tc <= t; ++tc) {
		cin >> n;

		for(int let = 0; let < 26; ++let) {
			lft[let].clear();
			rgt[let].clear();
			full[let].clear();
			alone[let].clear();
		}

		for(int act = 0; act < n; ++act) {
			cin >> s;
			for(int i = 0; i < L(s);) {
				int j = i + 1;
				while(j < L(s) && s[i] == s[j]) ++j;
				if (i == 0) {
					if (j == L(s)) {
						full[s[i] - 'a'].pb(act);
					} else {
						lft[s[i] - 'a'].pb(act);
					}
				} else {
					if (j == L(s)) {
						rgt[s[i] - 'a'].pb(act);
					} else {
						alone[s[i] - 'a'].pb(act);
					}
				}
				i = j;
			}
		}

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				g[i][j] = 0;

		int ans = 1;
		for(int let = 0; let < 26; ++let) {
			if (L(alone[let])) {
				if (L(lft[let]) || L(rgt[let]) || L(full[let]) || L(alone[let]) > 1) {
					ans = 0;
					break;
				}
			} else {
				if (L(lft[let]) > 1 || L(rgt[let]) > 1) {
					ans = 0;
					break;
				} else {
					if (L(lft[let]) == 1 && L(rgt[let]) == 1 && lft[let][0] == rgt[let][0]) {
						ans = 0;
						break;
					} else {
						for(int i = 1; i <= L(full[let]); ++i) {
							ans = (ll)ans * i % mod;
						}
						if (L(lft[let])) full[let].insert(full[let].begin(), lft[let][0]);
						if (L(rgt[let])) full[let].pb(rgt[let][0]);
						for(int i = 0; i < L(full[let]) - 1; ++i) {
							g[full[let][i]][full[let][i + 1]] = 1;
						}
					}
				}
			}
		}


		for(int i = 0; i < n; ++i) u[i] = 0;
		for(int i = 0; i < n; ++i) if (u[i] == 0) {
			if (!dfs(u[i])) {
				ans = 0;
				break;
			} 
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			int sin = 0, sout = 0;
			for(int j = 0; j < n; ++j) {
				if (g[j][i]) ++sin;
				if (g[i][j]) ++sout;
			}
			if (sin > 1 || sout > 1) {
				ans = 0;
				break;
			}
			if (sin == 0) {
				++cnt;
				ans = (ll)ans * cnt;
			}
		}

		cout << "Case #" << tc <<": ";
		cout << ans << endl;
	}
}
	