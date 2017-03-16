#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int t, a, b, k;
LL dp[50][2][2][2];

LL go(int m, short af, short bf, short kf) {
	if (m == -1)
		return 1;
	if (dp[m][af][bf][kf] != -1)
		return dp[m][af][bf][kf];
	int mask = 1 << m;
	LL ret = 0;
	if ((af || (a & mask)) && (bf || (b & mask)) && (kf || (k & mask))) {
		ret += go(m - 1, af, bf, kf);
	}
	if (af || (a & mask)) {
		short bbf = bf || (b & mask);
		short kkf = kf || (k & mask);
		ret += go(m - 1, af, bbf, kkf);
	}
	if (bf || (b & mask)) {
		short aaf = af || (a & mask);
		short kkf = kf || (k & mask);
		ret += go(m - 1, aaf, bf, kkf);
	}
	short aaf = af || (a & mask);
	short bbf = bf || (b & mask);
	short kkf = kf || (k & mask);
	ret += go(m - 1, aaf, bbf, kkf);
	return dp[m][af][bf][kf] = ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	REP(test, t) {
		cin >> a >> b >> k;
		--a; --b; --k;
		int start = 0;
		while ((1 << start) <= max(max(a, b), k))
			++start;
		REP(i, start + 1)
			REP(j, 2) REP(p, 2) REP(q, 2)
				dp[i][j][p][q] = -1;
		cout << "Case #" << test + 1 << ": " << go(start, 0, 0, 0) << endl;
	}
	return 0;
}
