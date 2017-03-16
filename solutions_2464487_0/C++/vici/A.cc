#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
double const pi = acos(-1.0);
double const eps = 1e-9;
int main() {
	freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-ans.txt", "w", stdout);
	//freopen("A-large.in", "r", stdin);  freopen("A-large-ans.txt", "w", stdout);
	int T, ca = 1;
	double r, t;
	for (scanf("%d", &T); T--; ) {
		scanf("%lf %lf", &r, &t);
		ll low = 1, high = 2e18, mid;
		ll ret = 1;
		while (low <= high) {
			mid = (low + high) / 2;
			double x = (double)(mid * 2 - 1);
			if ((2.0 * r * mid + x * mid)  <= t) {
				low = mid + 1;
				ret = mid;
			}
			else high = mid - 1;
		}
		printf("Case #%d: %lld\n", ca++, ret);
	}
	return 0;
}

