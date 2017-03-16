#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <assert.h>
#include <ctime>
#include <bitset>
#include <numeric>
#include <complex>
using namespace std;

#define double long double
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define FORE(i, a, n) for (i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
#define ll long long
#define pb push_back
#define error(x) cout << #x << " = " << (x) << endl;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define point complex<double>
//#define X real()
//#define Y imag()
#define X first
#define Y second
#define EPS 1e-12
//#define endl "\n"
#define pdd pair<double, double>
bool gt(double a, double b) { return a > b+EPS; }

int main() {
	int t;
	cin >> t;
	FOR(l, 1, t+1) {
		int n;
		cin >> n;
		vector<int> V(n);
		FOR(i, 0, n) cin >> V[i];
		cout << "Case #" << l << ":";
		cout << fixed << setprecision(15);
		FOR(i, 0, n) {
			double s = accumulate(all(V), 0);
			double mn = 0, mx = 100000;
			FOR(rep, 0, 200) {
				double mid = (mn+mx)/2;
				double Y = 0;
				FOR(j, 0, n) Y += max((double)0, (mid-V[j])/s);
				if (Y <= 1)
					mn = mid;
				else
					mx = mid;
			}
			double res = (mn-V[i]+0.)/s;
			cout << " " << max((double)0., res)*100;
		}
		cout << endl;
	}
	return 0;
}

