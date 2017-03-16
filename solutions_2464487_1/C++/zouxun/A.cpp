#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long rr, t;
int main()
{
	int cases;
	cin >> cases;
	for (int tcase = 1; tcase <= cases; ++tcase) {
		cin >> rr >> t;
		long long k = (long long)sqrt(t / 2) + 10;
		k = min(k, t/(2*rr));
		long long f = 1, r = k;
		while (f < r) {
			long long mid = (f + r + 1) / 2;
			if (mid * 2 * rr + 2 * mid * mid - mid <= t)
				f = mid;
			else r = mid - 1;	
		}
		cout << "Case #" << tcase << ": " << f << endl;
	}
	return 0;
}
