#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;


#define FOR(i,x,y) for(LL i=x; i<=y; i++)
#define REP(i,n) for(LL i=0; i<n; i++)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define SZ(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define X first
#define Y second



const double eps = 1.0e-11;
const double pi = acos(-1.0);


int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("outputC.txt", "w", stdout);
	int TESTS;
	scanf("%d\n", &TESTS);

	REP(test, TESTS) {
		printf("Case #%lld:\n", test + 1);
		int n, sum = 0;
		cin >> n;
		vector<int> d(n);
		REP(i, n) {
			cin >> d[i];
			sum += d[i];
		}
		int s1, s2;
		bool ok = false;
		map<int, vector<int> > m;
		REP(i, (1 << n)) {
			//cout << i << endl;
			int curr = 0;
			REP(j, n) {
				if (i & (1 << j)) {
					curr += d[j];
				}
			}
			if (m.find(curr) == m.end()) {
				m[curr] = vector<int> (1, i);
			} else {
				m[curr].push_back(i);
			}
		}
		for (map<int, vector<int> > ::iterator it = m.begin(); it != m.end(); ++it) {
			if (it->second.size() == 1) {
				continue;
			} else {
				REP(t1, it->second.size() - 1)
					FOR(t2, t1 + 1, it->second.size() - 1) {
						if ((it->second[t1] & it->second[t2]) == 0) {
							ok = true;
							s1 = it->second[t1], s2 = it->second[t2];
							goto loop;
						}
				}
			}
		}
		loop:;
		if (ok) {
			REP(i, n) {
				if (s1 & (1 << i)) {
					cout << d[i] << " ";
				}
			}
			cout << endl;
			REP(i, n) {
				if (s2 & (1 << i)) {
					cout << d[i] << " ";
				}
			}
			cout << endl;
		} else {
			cout << "Impossible\n";
		}
	}
	return 0;
}