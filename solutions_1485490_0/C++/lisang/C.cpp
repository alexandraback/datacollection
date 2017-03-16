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



const double eps = 1.0e-10;
const double pi = acos(-1.0);
double sum = 0;


LL Solve(vector<pair<LL, LL> > b, vector<pair<LL, LL> > t, LL bi, LL ti) {
	if (bi >= b.size() || ti >= t.size()) {
		return 0;
	}
	if (b[bi].first == 0) {
		return Solve(b, t, bi + 1, ti);
	}
	if (t[ti].first == 0) {
		return Solve(b, t, bi, ti + 1);
	}
	if (b[bi].second == t[ti].second) {
		LL tmp = min(b[bi].first, t[ti].first);
		b[bi].first -= tmp;
		t[ti].first -= tmp;
		return Solve(b , t, bi, ti) + tmp;
	} else {
		return max(Solve(b, t, bi + 1, ti), Solve(b , t, bi, ti + 1));
	}
}


int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("outputC.txt", "w", stdout);
	LL TESTS;
	cin >> TESTS;

	REP(test, TESTS) {
		printf("Case #%lld: ", test + 1);
		LL n, m;
		cin >> n >> m;
		vector<pair<LL, LL> > box(n), toy(m);
		REP(i, n) {
			cin >> box[i].first >> box[i].second;
		}
		REP(j, m) {
			cin >> toy[j].first >> toy[j].second;
		}
		cout << Solve(box, toy, 0, 0) << endl;
	}
	return 0;
}