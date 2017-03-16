#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef pair<int, int> pii;

int getind(map<string, int> &ind, string s) {
	if (!ind.count(s)) {
		int z = ind.size();
		ind[s] = z;
	}
	return ind[s];
}

const int maxn = 1000;
vi e[maxn];
int match[maxn], vis[maxn];

bool dfs(int v) {
	if (vis[v]) return false;
	vis[v] = 1;
	for (int u: e[v]) {
		if (match[u] == -1 || dfs(match[u])) {
			match[u] = v;
			return true;
		}
	}
	return false;
}

int main() {
	cout.precision(10);
	cout << fixed;
	int T;
	cin >> T;
	for1(tt, T) {
		int n;
		cin >> n;
		map<string, int> ind1, ind2;
		forn(i, n) {
			string s, t;
			cin >> s >> t;
			e[getind(ind1, s)].pb(getind(ind2, t));
		}
		int a = ind1.size(), b = ind2.size();
		forn(i, b) match[i] = -1;
		int ps = 0;
		forn(i, a) {
			forn(j, a) vis[j] = 0;
			ps += dfs(i);
			//cerr << ps << '\n';
		}
		cout << "Case #" << tt << ": " << n - (ps + (a - ps) + (b - ps)) << '\n';
		forn(i, a) e[i].clear();
	}
}


