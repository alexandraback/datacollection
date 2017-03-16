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
int a[1024];
int b[1024];
const int INF = (int)1e9;
bool one[1024];
bool two[1024];

void solve() {
	int T;
	cin >> T;
	REP(t, T) {
		int N;
		cin >> N;

		REP(i, N) {
			cin >> a[i] >> b[i];
			one[i] = two[i] = false;
		}
		int ret = 0;
		int cnt = 0;
		int done = 0;
		bool update = true;

		while (update) {
			update = false;
			int best = 0;
			int p = 0;
			int q = 0;
			REP(i, N) {
				if (two[i]) continue;
				if (b[i] <= cnt) {
					if (one[i]) {
						best = 1;
						p = i;
						update = true;
						q = 2;
						break;
					}
					else {
						best = 2;
						p = i;
						update = true;
						q = 2;
						break;
					}
				}
				if (!one[i] && a[i] <= cnt) {
					if (q == 0) {
						best = 1;
						p = i;
						q = 1;
						update = true;
					}
					else if (b[i]-a[i] > b[p]-a[p]) {
						best = 1;
						p = i;
						q = 1;
						update = true;
					}
				}
			}
			++ret;
			if (q == 2) {
				done++;
				two[p] = true;
				cnt += best;
			}
			else if (best == 1) {
				one[p] = true;
				cnt += best;
			}
			if (done == N)
				break;
		}

		if (done < N)
			printf("Case #%d: Too Bad\n", t+1);
		else
			printf("Case #%d: %d\n", t+1, ret);
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
