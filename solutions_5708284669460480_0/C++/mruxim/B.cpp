// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int k, l, s;
string key, str;
int cnt[33];
int f[111][33];

double solve() {
	cin >> k >> l >> s;
	cin >> key;
	cin >> str;

	memset(cnt, 0, sizeof cnt);
	rep(i, k) cnt[(int)key[i] - 'A']++;

	int addlen = l;
	fer(i, 1, l) if(str.substr(0, i) == str.substr(l - i, i)) addlen = l - i;
	int req = 1 + (s - l) / addlen;

	rep(i, l) if(cnt[str[i] - 'A'] == 0) req = 0;

	fer(i, 0, l+1) rep(c, 26) {
		f[i][c] = 0;
		rof(j, i+2, 1) {
			if(str[j-1] == char(c + 'A') && str.substr(0, j-1) == str.substr(i-(j-1), j-1)) {
				f[i][c] = j;
				break;
			}
		}
	}

	vector<double> dp(l + 1, 0), odp;
	dp[0] = 1;

	double ans = 0;

	rep(z, s) {
		odp = dp;
		dp.assign(l+1, 0);
		rep(i, l+1) rep(c, 26)
			dp[f[i][c]] += (cnt[c] / (double)k) * odp[i];
		ans += dp[l];
	}

	return req - ans;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tt; cin >> tt;
	fer(tc, 1, tt+1) {
		cout.setf(ios::fixed);
		cout.precision(8);
		cout << "Case #" << tc << ": " << solve() << endl;
	}

	return 0;
}

