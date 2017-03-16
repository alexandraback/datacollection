#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int t, n, m;
vector<int> e[50];
string s[50], ans;
bool vis[50], vis2[50], excl[50] = {};
int nxt[50], ord[50], oc;
int start = 0;

void dfs2(int v) {
	vis2[v] = true;
	REP(i, e[v].size())
		if (!vis2[e[v][i]])
			dfs2(e[v][i]);
}

int mmn = -1;

void dfs(int v) {
	ord[oc++] = v;
	vis[v] = true;
	REP(i, n) if (nxt[i] != -1 && e[i][nxt[i]] == v) {
		for (int j = nxt[i] + 1; j < (int)e[i].size(); ++j)
			if (!vis[e[i][j]])
				nxt[i] = j;
		if (vis[e[i][nxt[i]]])
			nxt[i] = -1;
	}
	ans += s[v];
	REP(i, e[v].size())
		if (!vis[e[v][i]]) {
			if (mmn != -1 && mmn != e[v][i]) {
				--oc;
				return;
			}
			if (mmn != -1)
				mmn = -1;
			int mn = e[v][i];
			int lastch = -1, lastj = -1;
			for (int j = oc - 2; j >= 0; --j) {
				lastj = j;
				excl[ord[j + 1]] = true;
				REP(p, n)
					vis2[p] = excl[p];
				dfs2(start);
				bool flag = true;
				REP(p, n)
					if (!vis2[p]) {
						flag = false;
						break;
					}
				if (flag && (ord[j] != v && nxt[ord[j]] != -1 && s[e[ord[j]][nxt[ord[j]]]] < s[mn])) {
					mn = e[j][nxt[j]];
					lastch = j;
				}
				if (!flag) break;
			}
			if (lastj != -1) {
				if (lastch == -1)
					for (int j = oc - 2; j >= lastj; --j)
						excl[j] = false;
				else
					for (int j = lastch - 1; j >= lastj; --j)
						excl[j] = false;
			}
			if (mn != e[v][i]) {
				mmn = mn;
				--oc;
				return;
			}
			nxt[v] = -1;
			for (int j = i + 1; j < (int)e[v].size(); ++j)
				if (!vis[e[v][j]]) {
					nxt[v] = j;
					break;
				}
			dfs(e[v][i]);
		}
	--oc;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	REP(test, t) {
		cin >> n >> m;
		ans = "";
		REP(i, n) {
			cin >> s[i];
			e[i].clear();
			nxt[i] = -1;
		}
		REP(i, m) {
			int x, y;
			cin >> x >> y;
			--x; --y;
			e[x].pb(y);
			e[y].pb(x);
		}
		REP(i, n) {
			REP(p, e[i].size() - 1)
				REP(q, e[i].size() - 1 - p)
					if (s[e[i][q]] > s[e[i][q + 1]]) {
						e[i][q] ^= e[i][q + 1];
						e[i][q + 1] ^= e[i][q];
						e[i][q] ^= e[i][q + 1];
					}
		}
		start = 0;
		for (int i = 1; i < n; ++i)
			if (s[i] < s[start])
				start = i;
		REP(i, n) vis[i] = false;
		oc = 0;
		dfs(start);
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}
