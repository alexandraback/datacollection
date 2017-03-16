#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

FILE* tmp;

VI u, b;
VI a;
int maxcycle = 0;

int go(int x, int v, bool fill) {
	if (b[x] == INF) {
		if (fill) b[x] = 1;
		return v - 1;
	}

	if (b[x] && b[x] != INF) return 0;

	if (u[x]) {
		maxcycle = max(maxcycle, (v - u[x]));
		if (u[x] == v - 2) {
			u[a[x]] = INF;
			return v - 1;
		}
		return 0;
	}

	u[x] = v;
	return go(a[x], v + 1, fill);
}

int main()
{
	freopen_s(&tmp, "input.txt", "r", stdin);
	freopen_s(&tmp, "output.txt", "w+", stdout);

	int tt;
	cin >> tt;
	REP(t, tt) {
		cout << "Case #" << (t + 1) << ": ";

		maxcycle = 0;
		int n;
		cin >> n;
		a.resize(n);
		REP(i, n) {
			cin >> a[i];
			a[i]--;
		}

		int res = 0;

		b = VI(n);

		while (true) {
			int mm = 0;
			int mi = 0;
			REP(i, n) {
				u = VI(n);
				int v = go(i, 1, false); 
				if (v > mm) {
					mm = v;
					mi = i;
				}
			}

			if (mm) {
				res += mm;
				u = VI(n);
				go(mi, 1, true);
				REP(i, n)
					if (u[i])
						b[i] = u[i];
			}
			else break;
		}

		cout << max(res, maxcycle) << endl;
	}

	return 0;
}
