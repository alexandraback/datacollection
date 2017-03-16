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

int M[4][4] = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };

int mul(int a, int b) {
	int res = 1;
	if (a < 0) {
		a = -a;
		res = -res;
	}
	if (b < 0) {
		b = -b;
		res = -res;
	}
	return res * M[a - 1][b - 1];
}

int mul(string s) {
	int res = 1;
	for (auto c : s) {
		res = mul(res, c - 'i' + 2);
	}
	return res;
}

int mypow(int x, long long p) {
	if (p == 0) {
		return 1;
	}
	if (p == 1) {
		return x;
	}
	int r = mypow(x, p / 2);
	r = mul(r, r);
	if (p & 1) {
		r = mul(r, x);
	}
	return r;
}

int main()
{
	freopen_s(&tmp, "input.txt", "r", stdin);
	freopen_s(&tmp, "output.txt", "w+", stdout);

	int tt;
	cin >> tt;
	for (size_t t = 1; t <= tt; ++t) {
		cout << "Case #" << t << ": ";

		long long n, x;
		cin >> n >> x;
		string s;
		cin >> s;

		int ss = mul(s);
		//cout << ss << endl;
		//cout << mypow(ss, x) << endl;
		if (mypow(ss, x) != -1) {
			cout << "NO" << endl;
			continue;
		}

		int cur = 1;
		int stage = 0;

		REP(i, x) {
			for (auto c : s) {
				cur = mul(cur, c - 'i' + 2);

				if (stage == 0 && cur == 2) {
					stage = 1;
					cur = 1;
				} else if (stage == 1 && cur == 3) {
					std::cout << "YES" << endl;
					goto next;
				}
			}

			if (i > 16) {
				break;
			}
		}
		cout << "NO" << endl;

	next:;
	}

	return 0;
}
