#include <stdio.h>
#include <math.h>
#include <string.h>

typedef long long LL;

double pi = acos(-1.0);
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		LL r, t;
		scanf("%lld%lld", &r, &t);
		LL ans = 1;
		LL low = 2, high = 100000000000L;
		while(low <= high) {
			LL mid = (low + high) >> 1;
			double first = 2.0 * r + 1;
			double last = (double)(mid - 1) * 4 + first;
			double area = (double)(first + last) * mid / 2;
			if(area <= t) {
				ans = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}
