#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vb> vvb;
typedef vector<vs> vvs;
typedef vector<vl> vvl;

int inf = 0x3f3f3f3f;
double eps = 10e-8;
ll mod = 1000000007ll;

#define rep(k, a, b) for (int k = (a); k < int(b); k++)
#define sz(a) int(a.size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define x first
#define y second
#define mi(r, c, v) vvi(r, vi(c, v))
#define rrep(k, a, b) for (int k = (a); k >= int(b); k--)
#define irep(k, a) for (auto& k : (a))
#define md(r, c, v) vvd(r, vd(c, v))
#define mb(r, c, v) vvb(r, vb(c, v))
#define ms(r, c, v) vvs(r, vs(c, v))
#define ml(r, c, v) vvl(r, vl(c, v))
#define mc(r, c, v) vs(r, string(c, v))
#define add(i, j) ((i) + (j)) % mod
#define mul(i, j) ((i) * (j)) % mod
#define bits(n) int(__builtin_popcount(n))

int main() {
	int T, n;
	cin >> T;
	rep(X, 0, T) {
		cin >> n;
		vi F(n), maxchain(n);
		int longcycle = 0, chainlen = 0;

		irep(v, F)
			cin >> v;
		rep(i, 0, n) {
			vi dist(n, inf);
			dist[i] = 1;
			int k = i;
			while (dist[F[k] - 1] == inf) {
				dist[F[k] - 1] = dist[k] + 1;
				k = F[k] - 1;
			}

			int cyclen = dist[k] + 1 - dist[F[k] - 1];
			longcycle = max(longcycle, cyclen);

			if (cyclen == 2)
				maxchain[F[k] - 1] = max(maxchain[F[k] - 1], dist[F[k] - 1]);

			//cout << i + 1 << ' ' << head << ' ' << cyclen << ' ' << maxchain[i] << endl;
		}
		//cout << endl;

		rep(i, 0, n)
			chainlen += maxchain[i];

		printf("Case #%d: %d\n", X + 1, max(chainlen, longcycle));
	}
}
