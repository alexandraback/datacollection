#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0; i<(int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i < (int)(e); i++)

int point[200];
double ret[200];

void solve() {
	int T;
	cin >> T;

	REP(t, T) {
		int N;
		cin >> N;

		int sum = 0;
		REP(i, N) {
			cin >> point[i];
			sum += point[i];
		}

		REP(i, N) {
			ret[i] = 0;

			double hi = 1.0;
			double lo = 0;

			REP(k, 100) {
				double x = (hi+lo) / 2;
				double y = (1-x)*sum;
				double z = point[i] + x * sum;

				REP(j, N) {
					if (j == i)
						continue;

					if (point[j] > z) continue;
					y -= z-point[j];
				}

				if (y > 0)
					lo = x;
				else
					hi = x;
			}
			ret[i] = hi;
		}

		cout << "Case #" << t+1 << ":";
		REP(i, N)
			printf(" %.12lf", 100.0*ret[i]);
		cout << endl;
	}


}

#define SUBMIT
int main() {
#ifdef SUBMIT
	freopen("./test.in", "r", stdin);
	freopen("./test.out", "w", stdout);
#endif

	solve();

#ifdef SUBMIT
	fflush(stdout);
	cerr << "all done!" << endl;
#endif
	return 0;
}
