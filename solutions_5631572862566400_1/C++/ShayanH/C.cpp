#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define VAL(x) #x << " = " << (x) << "   "
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 2 * 1000 + 10;

int f[MAXN], ans = 0;
bool mark[MAXN];

void dfs(int x, int cnt, int s) {
	if (x == s && cnt) {
		ans = max(ans, cnt);
		return ;
	}
	if (mark[x]) return ;

	mark[x] = true;
	dfs(f[x], cnt + 1, s);
}

int go(int x, int cnt, int tar, int frd) {
	if (x == frd) return 0;
	if (x == tar) return cnt;
	if (mark[x]) return 0;

	mark[x] = true;
	int res = go(f[x], cnt + 1, tar, frd);
	mark[x] = false;
	return res;
}

int d[MAXN];

int main () {
	ios::sync_with_stdio(false);

	int tc; cin >> tc;
	for (int o = 0; o < tc; o ++) {
		cout << "Case #" << o + 1 << ": ";
		ans = 0;
		CLR(d, 0); CLR(mark, 0); CLR(f, 0);

		int n; cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> f[i];
			f[i] --;
			d[f[i]] ++;
		}

		vector<int> syn;
		for (int i = 0; i < n; i ++) {
			if (d[i]) {
				CLR(mark, 0);
				dfs(i, 0, i);
			}
			else syn.pb(i);
		}

		vector<int> pp;	
		for (int i = 0; i < n; i ++)
			if (i < f[i] && f[f[i]] == i)
				pp.pb(i);

		CLR(mark, 0);
		vector<int> t;
		for (int i = 0; i < SZ(pp); i ++) {
			int v = pp[i], u = f[v];
			int k1 = 0, k2 = 0;

			for (int j = 0; j < SZ(syn); j ++) {
				int w = syn[j];
				k1 = max(k1, go(w, 0, v, u));
				k2 = max(k2, go(w, 0, u, v));
			}
			t.pb(k1 + k2 + 2);
		}
		int cur = 0;
		for (int i = 0; i < SZ(t); i ++)
			cur += t[i];
		ans = max(ans, cur);

		cout << max(1, ans) << endl;
	}
	return 0;
}

