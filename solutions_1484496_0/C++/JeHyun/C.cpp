#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cfloat>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <bitset>

#define REP(i,a) for(i=0;i<a;++i)
#define FOR(i,a,b) for(i=a;i<=b;++i)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
using namespace std;

void main() {
	bool* as = new bool[1999995];
	int* last = new int[1999995];

	int T;
	int i;
	cin >> T;
	REP(i,T) {
		int N;
		int j,k;
		cin >> N;

		int val[21];
		int total = 0;

		REP(j,N) {
			cin >> val[j];
			total += val[j];
		}

		memset(as, 0x00, 1999995);

		int res1;
		int res2;
		int res3;

		as[0] = true;
		last[0] = -1;

		REP(j,N) {
			for (k = total; k >= 0; --k) {
				if (as[k]) {
					if (as[k+val[j]]) {
						res1 = last[k + val[j]];
						res2 = val[j];
						res3 = k + val[j];
						break;
					}

					as[k + val[j]] = true;
					last[k + val[j]] = val[j];
				}
			}
			if (k >= 0)
				break;
		}

		cout << "Case #" << (i+1) << ":";

		if (j == N) {
			cout << " Impossible" << endl;
		} else {
			vector<int> r1;
			vector<int> r2;

			int x = res3;

			while (x > 0) {
				r1.push_back(last[x]);
				x -= last[x];
				//cout << x << ' ' << last[x] << endl;
			}

			x = res3 - res2;

			r2.pb(res2);
			while (x > 0) {
				r2.push_back(last[x]);
				x -= last[x];
				//cout << x << ' ' << last[x] << endl;
			}

			cout << endl;
			bool fir = true;

			REP(j,r1.size()) {
				REP(k,r2.size()) {
					if (r1[j] == r2[k])
						break;
				}

				if (k == r2.size()) {
					if (!fir) {
						cout << " ";
					}
					fir = false;

					cout << r1[j];
				}
			}

			cout << endl;
			fir = true;

			REP(j,r2.size()) {
				REP(k,r1.size()) {
					if (r2[j] == r1[k])
						break;
				}

				if (k == r1.size()) {
					if (!fir) {
						cout << " ";
					}
					fir = false;

					cout << r2[j];
				}
			}
			cout << endl;
		}
	}

	delete[] as;
	delete[] last;
}