#pragma comment(linker, "/stack:256000000")

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

const long long INF = 4 * (long long)1e18 + 10;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long start = clock();
#endif
	int tst;
	cin >> tst;
	REP(_, tst) {
		long long r, t;
		cin >> r >> t;
		long long L = 0, R = 2 * (long long)1e18 + 10;
		while (L + 1 < R) {
			long long M = (L + R) / 2;
			if (M + 1 > INF / (2 * r + 1 + 2 * M)) {
				R = M;
				continue;
			}
			long long tmp = (M + 1) * (2 * r + 1 + 2 * M);
			if (tmp <= t) {
				L = M;
			} else {
				R = M;
			}
		}
		long long res = L + 1;
		cout << "Case #" << (_ + 1) << ": " << res;
		cout << "\n";
	}
	long long r, t;
#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf\n\n", (clock() - start) / 1000.);
#endif
	return 0;
}