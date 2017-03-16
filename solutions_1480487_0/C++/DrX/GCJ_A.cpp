#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 400;

int s[N], n, sum;

bool chk (int x, double r) {
	double v = s[x] + r * sum;
	r = 1.0 - r;
	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		if (i == x || s[i] > v) continue;
		else {
			double f = (v - s[i]) / sum;
			if (r < 0 || r + 1e-15 < f) {
				flag = true;
				break;
			}
			else r -= f;
		}
	}
	return flag;
}

int main () {
	int i, j, k, T, t, ca;
	freopen ("/home/shuo/Desktop/A.in", "r", stdin);
	freopen ("/home/shuo/Desktop/A.o", "w", stdout);
	scanf ("%d", &T);
	for (ca = 1; ca <= T; ++ca) {
		scanf ("%d", &n); sum = 0;
		for (i = 1; i <= n; i++) scanf ("%d", &s[i]), sum += s[i];
		printf ("Case #%d:", ca);
		for (i = 1; i <= n; i++) {
			double up = 1.0, low = .0;
			while (up  > low + 1e-15) {
				double mid = (up + low) / 2;
				if (chk (i, mid))
					up = mid;
				else low = mid;
			}
			printf (" %.15lf", 100 * up);
		}
		printf ("\n");
	}
	return 0;
}
