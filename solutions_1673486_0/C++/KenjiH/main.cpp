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

const int MAX_V = 100010;
double pos[MAX_V];
double wrong[MAX_V];

void solve() {
	int T;
	cin >> T;

	REP(t, T) {
		cerr << "solving #" << t << "..." << endl;
		int A, B;

		cin >> A >> B;
		REP(i, A)
			cin >> pos[i];

		wrong[0] = 1;
		double right = 1;
		REP(i, A) {
			wrong[i+1] = right * (1.0-pos[i]);
			right *= pos[i];
		}

		double ret = 1+B+1;
		ret = min(ret, right*(B-A+1) + (1.0-right)*(B-A+1+B+1));
		for (int i = A; i >= 1; i--) {
			right += wrong[i];
			int j = A-i+1;
			ret = min(ret,
					right*(j*2+B-A+1)+(1.0-right)*(j*2+B-A+1+B+1));
		}

		printf("Case #%d: %.18lf\n", t+1, ret);
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
