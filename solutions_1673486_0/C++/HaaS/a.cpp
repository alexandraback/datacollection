#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

#define pie pair <int, int>
#define ff first
#define ss second

const int maxN = 100000 + 10;

int a, b;
double p[maxN];
double pp[maxN];

void solve () {
	cin >> a >> b;
	double res = 1 + b + 1;
	pp[0] = 1;
	for (int i = 0; i < a; i++) 
		cin >> p[i],
		pp[i + 1] = pp[i] * p[i];

	for (int x = 0; x <= a; x++) {
		int tcor = 2 * x + b - a + 1, twro = 2 * x + 2 * b - a + 2;
		double pcor = pp[a - x], pwro = 1 - pp[a - x];
		double ans = pcor * tcor + pwro * twro;
		res = min (res, ans);
	}

	cout << fixed << setprecision (20) << res << endl;
}

int main()
{
	ios::sync_with_stdio (false);

	int tests; cin >> tests;
	for (int i = 1; i <= tests; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
