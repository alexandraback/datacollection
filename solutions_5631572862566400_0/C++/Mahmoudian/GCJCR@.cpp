//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
ofstream fout("a.out");
#define cout fout
const int N = 1e3 + 3;

int read() { int x; cin >> x; return x; }

int mark[N], cyc[N], f[N], path[N], deg[N], q[N], h, t;


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc = read();
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";
		memset(mark, 0, sizeof mark);
		memset(cyc, 0, sizeof cyc);
		memset(path, 0, sizeof path);
		memset(deg, 0, sizeof deg);
		int n = read();
		rep(i, n) {
			f[i] = read() - 1;
			deg[f[i]]++;
		}
		h = 0, t = 0;
		rep(i, n) {
			if (deg[i] == 0)
				q[t++] = i, path[i] = 0;
		}
		while (h != t) {
			int v = q[h++];
			deg[f[v]]--;
			path[f[v]] = max(path[f[v]], path[v] + 1);
			if (deg[f[v]] == 0)
				q[t++] = f[v];
		}
		int res = 0, two = 0;
		rep(v, n) if (!mark[v] && deg[v] != 0) {
			int cur = f[v];
			int len = 1;
			while (cur != v) {
				len++;
				cur = f[cur];
			}
			cur = f[v];
			cyc[v] = len;
			mark[v] = 1;
			while (cur != v) {
				cyc[cur] = len;
				mark[cur] = 1;
				cur = f[cur];
			}
			if (len >= 2)
				res = max(res, len);
			if (len == 2)
				two += path[v] + 1 + path[f[v]] + 1;
		}
		cout << max(res, two);
		cout << '\n';
	}
}













