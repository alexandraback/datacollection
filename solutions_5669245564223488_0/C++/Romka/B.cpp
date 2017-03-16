#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int md = 1000000007;

int n;
string s[110];
int p[110], u[1010];
int uniq[110], inside[110], g[110][110];
ll fact[110];

bool equal(string s) {
	forn(i, s.size())
		if (s[i] != s[0]) return false;

	return true;
}

bool go(int i, int s) {
	// printf("go %d %d\n", i, s);
	forn(j, 26)
		if (g[i][j]) {
			if (j == s) return true;
			return go(j, s);
		}
	return false;
}

int solve() {
	scanf("%d", &n);
	forn(i, 26) {
		uniq[i] = 0;
		inside[i] = 0;
		forn(j, 26) g[i][j] = 0;
	}

	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = fact[i-1] * i % md;

	int parts = 0;
	forn(i, n) cin >> s[i];
	forn(i, n) {
		string& t = s[i];

		if (equal(t)) uniq[t[0] - 'a']++;
		else if (t[0] == t[t.size() - 1]) return 0;
		     else { g[t[0] - 'a'][t.back() - 'a']++; parts++; }

		for (int j = 1; j + 1 < t.size(); j++)
			if (t[j] != t[0] && t[j] != t[t.size() - 1])
				if (t[j] != t[j-1]) inside[t[j] - 'a']++;
	}
/*
	forn(i, 26) {
		forn(j, 26) printf("%d ", g[i][j]);
		printf("\n");
	}
*/
	forn(i, 26) {
		if (inside[i] > 1) return 0;
		int sum = 0, s2 = 0;
		forn(j, 26) {
			sum += g[i][j];
			s2 += g[j][i];
		}
		if (sum > 1 || s2 > 1) return 0;
		// printf("%d: %d\n", i, uniq[i]);
		if (inside[i] && sum + s2 > 0) return 0;
		if (go(i, i)) return 0;
	}

	// printf("parts = %d\n", parts);
	forn(i, 26)
		forn(j, 26)
			forn(k, 26)
				if (g[i][j] && g[j][k])
					parts--;

	ll ans = 1;
	forn(i, 26)
		if (uniq[i]) {
			ans = ans * fact[uniq[i]] % md;
			bool fixed = false;
			forn(j, 26)
				if (g[i][j] || g[j][i]) {
					fixed = true;
					break;
				}
			if (!fixed) parts++;
		}

	// cout << ">> " << ans << " " << parts << endl;

	ans = ans * fact[parts] % md;

	return ans % md;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		printf("%d\n", solve());
		fprintf(stderr, "Case %d done.\n", q);
	}
	return 0;
}
