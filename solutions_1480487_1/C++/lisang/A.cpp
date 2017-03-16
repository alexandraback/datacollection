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

bool Check(vector<LL>& d, double m, int i) {
	double all = 1.0;
	vector<double> t(d.size());
	REP(j, SZ(d)) {
		t[j] = d[j];
	}
	t[i] += (sum * m);
	all -= m;
	REP(j, SZ(t)) {
		if (t[j] < t[i]) {
			all -= (abs(t[i] - t[j]) / double(sum));
		}
	}
	if (all < 0) {
		return true;
	}
	return false;
}

double Solve(vector<LL>& d, double l, double r, int i) {
	if (abs(l - r) < eps) {
		return (l + r) / 2.0;
	}
	double m = (l + r) / 2.0;
	if (Check(d, m, i)) {
		return Solve(d, l, m, i);
	} else {
		return Solve(d, m, r, i);
	}
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("outputA.txt", "w", stdout);
	int TESTS;
	scanf("%d\n", &TESTS);

	REP(test, TESTS) {
		LL n;
		sum = 0;
		cin >> n;
		vector<LL> d(n);
		REP(i, n) {
			cin >> d[i];
			sum += d[i];
		}
		printf("Case #%lld: ", test + 1);
		REP(i, n) {
			printf("%.9llf ", 100 * Solve(d, 0.0, 1.0, i));
		}
		cout << endl;
	}
	return 0;
}