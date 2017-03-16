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

int main() {
	int T;
	cin >> T;
	FOR(ti, 1, T) {
		int k, n;
		cin >> k >> n;
		map<int, int> S;
		REP(i, k) {
			int x;
			cin >> x;
			++S[x];
		}
		VI O(n);
		vector<map<int, int> > C(n);
		REP(i, n) {
			int ki;
			cin >> O[i] >> ki;
			REP(j, ki) {
				int x;
				cin >> x;
				++C[i][x];
			}
		}

		vector<bool> P(1 << n);
		P[0] = true;
		FOR(x, 1, (1 << n) - 1) {
			map<int, int> Q(S);
			REP(i, n) if ((x & (1 << i)) == 0) {
				--Q[O[i]];
				FORE(j, C[i])
					Q[j->first] += j->second;
			}
			REP(i, n) if (x & (1 << i)) {
				if (Q[O[i]] > 0 && P[x ^ (1 << i)])
					P[x] = true;
			}
		}

		cout << "Case #" << ti << ":";
		if (!P[(1 << n) - 1]) {
			cout << " IMPOSSIBLE" << endl;
		} else {
			int x = (1 << n) - 1;
			while (x) {
				REP(i, n) if (x & (1 << i))
					if (S[O[i]] > 0 && P[x ^ (1 << i)]) {
						--S[O[i]];
						FORE(j, C[i])
							S[j->first] += j->second;
						x ^= 1 << i;
						cout << " " << i + 1;
						break;
					}
			}
			cout << endl;
		}
	}
}
