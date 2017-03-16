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

const int MAXN = 1 * 100 + 10;

ll pw[MAXN];

ll get_index(vector<int> v, int c) {
	ll res = 0;
	for (int i = 0; i < SZ(v); i ++)
		res += (ll)v[i] * pw[c - i - 1];
	return res;
}

bool mark[MAXN];

int main () {
	ios::sync_with_stdio(false);

	int oo; cin >> oo;
	for (int o = 0; o < oo; o ++) {
		cout << "Case #" << o + 1 << ": ";

		int k, c, s; 
		cin >> k >> c >> s;

		pw[0] = 1;
		for (int i = 1; i <= c; i ++)
			pw[i] = pw[i - 1] * (ll)k;

		if (s * c < k) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		CLR(mark, 0);
		for (int i = 0; i < s; i ++) {
			vector<int> cur;
			for (int j = 0; j < k; j ++)
				if (!mark[j] && SZ(cur) < c) {
					cur.pb(j);
					mark[j] = true;
				}
			if (!SZ(cur)) break;
			cout << get_index(cur, min(k, c)) + 1 << ' ';
		}
		cout << endl;
	}
	return 0;
}

