#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		LL r, t;
		cin >> r >> t;

		LL R = t / (2 * r) + 1;
		LL L = 0;
		while (L + 1 < R) {
			LL mid = (L + R) / 2;
			LL rest = t - 2 * r * mid;
			bool ok = 1;
			if (rest >= 0)
				rest -= mid;
			else
				ok = 0;

			if (rest >= 0) { 
				if (rest / mid + 1 >= (mid - 1) * 2)
					rest -= mid * (mid - 1) * 2;
				else
					ok = 0;
			}
			else
				ok = 0;

			if (rest < 0)
				ok = 0;

			if (ok)
				L = mid;
			else
				R = mid;
		}
		printf("Case #%d: %d\n", i + 1, L);
	}

	return 0;
}
