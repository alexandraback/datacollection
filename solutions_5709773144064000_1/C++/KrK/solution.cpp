#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const ld eps = 1e-10;

int t;
ld c, f, x;

ld Get(ld v, ld lim) 
{ 
	ld t1 = x / v, t2 = c / v;
	lim = min(t1, lim);
	if (t2 + eps >= lim) return lim;
	return t2 + Get(v + f, lim - t2);
}

int main()
{
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> c >> f >> x;
		cout << "Case #" << tc << ": " << fixed << setprecision(7) << Get(2.0, x / 2.0) << endl;
	}
	return 0;
}