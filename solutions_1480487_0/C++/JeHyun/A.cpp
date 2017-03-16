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
	int T;
	cin >> T;
	int i;

	REP(i,T) {
		int N;
		int j,k;
		cin >> N;

		int s[201];
		int total = 0;

		REP(j,N) {
			cin >> s[j];
			total += s[j];
		}

		double res[201];

		REP(j,N) {
			double x = 0;
			double y = 1;

			while (y - x >= 1e-10) {
				double m = (x + y) / 2;
				double a = s[j] + m * total;
				double mtotal = m;

				REP(k,N) {
					if (j == k)
						continue;
					if (a <= s[k])
						continue;
					double newm = (a - s[k]) / total;
					mtotal += newm;
				}

				if (mtotal > 1) {
					y = m;
				} else {
					x = m;
				}

				//cout << mtotal << ' ' << m << ' ' << x << ' ' << y << endl;
			}

			res[j] = x;
		}


		cout << "Case #" << (i + 1) << ": ";
		printf("%.7lf", res[0] * 100);

		FOR(j,1,N-1) {
			printf(" %.7lf", res[j] * 100);
		}
		cout << endl;
	}
}