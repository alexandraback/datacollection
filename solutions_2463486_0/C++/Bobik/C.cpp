// {{{
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))
#define DEBUG(x) { cerr << #x << ": " << (x) << endl; }
#define SQR(x) ((x) * (x))
#define INF 1023456789
using namespace std;

typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;
// }}}

bool fair(LL x) {
	VI D;
	while (x) {
		D.push_back(x % 10);
		x /= 10;
	}
	REP(i, SIZE(D))
		if (D[i] != D[SIZE(D) - i - 1])
			return false;
	return true;
}

int solve(LL n) {
	int m = sqrt(n) + 7, res = 0;
	REP(x, m) {
		if (!fair(x))
			continue;
		LL y = SQR((LL) x);
		if (y <= n && fair(y))
			++res;
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	FOR(ti, 1, T) {
		LL a, b;
		cin >> a >> b;
		cout << "Case #" << ti << ": " << solve(b) - solve(a - 1) << endl;
	}
}
