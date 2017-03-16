#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;

const int MAXN = 150;
const int MOD = 1000000007;
string s[MAXN];
int same[26];
int pref[26];
int suff[26];
int inner[26];
int facts[150];

void precalc() {
	facts[0] = 1;
	for (int i = 1; i < 150; ++i) {
		facts[i] = (1ll * facts[i - 1] * i) % MOD;
	}
}

void solve() {
	int n;
	cin >> n;
	forn(i, n) {
		cin >> s[i];
	}
	bool impossible = false;
	forn(i, 26) {
		same[i] = pref[i] = suff[i] = inner[i] = 0;
	}
	forn(i, n) {
		char sym = s[i][0];
		bool ok = true;
		forn(j, s[i].length()) {
			if (s[i][j] != sym) {
				ok = false;
				break;
			}
		}
		if (ok) {
			++same[sym - 'a'];
		} else {
			++pref[s[i][0] - 'a'];
			++suff[s[i][s[i].length() - 1] - 'a'];
			bool first = true;
			forn(j, s[i].length()) {
				if (j + 1 < s[i].length() && s[i][j] != s[i][j + 1]) {
					int cur = s[i][j] - 'a';
					if (!first) {
						++inner[cur];
					}
					first = false;
				}
			}
		}
	}
	int ans = 1;
	int rem = n;
	forn(i, 26) {
		if (inner[i] >= 2) {
			impossible = true;
		}
		if (inner[i] > 0 && pref[i] + suff[i] + same[i] > 0) {
			impossible = true;
		}
		if (pref[i] > 1 || suff[i] > 1) {
			impossible = true;
		}
		ans = (1ll * ans * facts[same[i]]) % MOD;
		if (pref[i] == 1 && suff[i] == 1) {
			rem -= same[i] + 1;
		} else if (pref[i] + suff[i] > 0) {
			rem -= same[i];
		} else if (same[i] > 0) {
			rem -= same[i] - 1;
		}
	}
	if (rem <= 0) {
		impossible = true;
	}
	ans = (1ll * ans * facts[rem]) % MOD;
	if (impossible) {
		cout << 0 << endl;
	} else {
		cout << ans << endl;
	}
}

int main(int argc, char **argv) {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	precalc();
	int tt;
	cin >> tt;
	forn(t, tt) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
	}
	return 0;
}
