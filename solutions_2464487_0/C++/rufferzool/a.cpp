#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long ret(long long r, long long p, long long t) {
	long long val = 2LL * r * p + 2LL * p * p - p;
	if(val > t)
		return false;
	return true;
}

int main() {
	int T;
	scanf(" %d", &T);
	for(int z = 1; z <= T; z ++) {
		long long r, t;
		scanf(" %lld %lld", &r, &t);
		long long high = min((long long )sqrt(t / 2LL), t / (2LL * r)) + 5LL, low = 1LL, mid;
		if(high <= low + 1) {
			if(ret(r, high, t))
				printf("Case #%d: %lld\n", z, high);
			else
				printf("Case #%d: %lld\n", z, low);
			continue;
		}
		while(1) {
			mid = (high + low) / 2LL;
			//printf("Mid is: %lld %lld %lld\n", mid, high, low);
			if(ret(r, mid, t)) {
				low = mid;
				if(high == low + 1)
					break;
			}
			else {
				high = mid;
			}
		}
		printf("Case #%d: %lld\n", z, mid);
	}
	return 0;
}
