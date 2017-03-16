#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

int k, l, s;
char buf[1000];
string a, str;

bool read() {
	if (scanf("%d %d %d", &k, &l, &s) != 3)
		return false;
	swap(k, s);
	scanf("%s", buf);
	a = buf;

	scanf("%s", buf);
	str = buf;
	return true;
}

int calc_sp(string a, string b) {
	for (int res = min(sz(a), sz(b)); res >= 0; --res)
		if (a.substr(sz(a) - res) == b.substr(0, res))
			return res;

	assert(false);
}

pair<ld, ld> dp[105][105];
int npref[105][105];

void solve() {
	forn(i, sz(str))
		if (a.find(str[i]) == -1) {
			puts("0.0");
			return;
		}

	int supref = calc_sp(str.substr(1), str);

	int cur = 0;
	int mx = 0;
	forn(i, k) {
		cur++;
		if (cur == sz(str))
			cur = supref, mx++;
	}

	forn(i, sz(str) + 1) {
		string pref = str.substr(0, i);
		forn(j, sz(a)) {
			npref[i][j] = calc_sp(pref + a[j], str);
		}
	}

	memset(dp, 0, sizeof dp);

	dp[0][0] = mp(1.0, 0);

	forn(i, k) {
		forn(p, sz(str) + 1) {
			forn(x, sz(a)) {
				int np = npref[p][x];
				dp[i + 1][np].ft += dp[i][p].ft / sz(a);
				dp[i + 1][np].sc += (dp[i][p].sc + (np == sz(str)) * dp[i][p].ft) / sz(a);
			}
		}
	}

	ld sum = 0;
	forn(j, sz(str) + 1)
		sum += dp[k][j].sc;

	printf("%0.9lf\n", mx - sum);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifdef TASK_NAME
	freopen(TASK_NAME ".in", "r", stdin);
	freopen(TASK_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);

	forn(t, T) {
		assert(read());
		printf("Case #%d: ", t + 1);
		solve();
	}
	
	return 0;
}
