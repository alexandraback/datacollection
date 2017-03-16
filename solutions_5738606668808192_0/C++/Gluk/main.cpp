#define _CRT_SECURE_NO_WARNINGS

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

bool check(std::vector<bool> x) {
	std::vector<int> res;

	FOR(base, 2, 11) {
		FOR(div, 2, 10000) {
			long long r = 0;
			int c = 0;
			FORD(i, x.size() - 1, 0) {
				r *= base;
				if (x[i])
					r++;
				r %= div;
			}

			if (!r) {
				res.pb(div);
				goto next;
			}
		}
		return false;

	next:;
	}

	FORD(i, x.size() - 1, 0)
		cout << (int)x[i];
	
	for (auto r : res) {
		cout << " " << r;
	}
	cout << endl;
}

void increment(std::vector<bool>& x) {
	REP(i, x.size()) {
		x[i] = !x[i];
		if (x[i])
			break;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int tt;
	cin >> tt;
	REP(t, tt) {
		cout << "Case #" << t + 1 << ":" << endl;

		int n, m;
		cin >> n >> m;

		std::vector<bool> x(n);
		x[0] = 1;
		x[n - 1] = 1;

		while (m) {
			if (check(x)) {
				m--;
			}
			increment(x);
			increment(x);
		}
	}

	return 0;
}
