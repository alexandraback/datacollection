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

string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int ord[10] = {4, 5, 0, 7, 6, 2, 8, 1, 3, 9};

pair<i64, i64> dp[19][3];

bool better(pair<i64, i64> a, pair<i64, i64> b) {
	if (abs(a.se - a.fi) != abs(b.se - b.fi)) return abs(a.se - a.fi) < abs(b.se - b.fi);
	return a < b;
}

int fl(pair<i64, i64> a) {
	if (a.fi == a.se) return 1;
	return a.fi < a.se ? 0 : 2;
}

string zfill(i64 x, int n) {
	string s;
	forn(i, n) {
		s += (char)('0' + x % 10);
		x /= 10;
	}
	reverse(all(s));
	return s;
}

int main() {
	cout.precision(10);
	cout << fixed;
	int T;
	cin >> T;
	for1(tt, T) {
		string s, t;
		cin >> s >> t;
		int n = s.size();
		forn(i, n + 1) forn(j, 3) dp[i][j] = mp(-1e18, 1e18);
		dp[0][1] = mp(0, 0);
		forn(i, n) forn(j, 3) forn(d1, 10) forn(d2, 10) {
			if (dp[i][j].fi < 0) continue;
			if (s[i] != '?' && s[i] != '0' + d1) continue;
			if (t[i] != '?' && t[i] != '0' + d2) continue;
			pair<i64, i64> q = mp(10 * dp[i][j].fi + d1, 10 * dp[i][j].se + d2);
			int nfl = fl(q);
			if (better(q, dp[i + 1][nfl])) dp[i + 1][nfl] = q;
		}
		pair<i64, i64> ans = mp(-1e18, 1e18);
		forn(j, 3) if (better(dp[n][j], ans)) ans = dp[n][j];
		cout << "Case #" << tt << ": " << zfill(ans.fi, n) << ' ' << zfill(ans.se, n) << '\n';
	}
}

