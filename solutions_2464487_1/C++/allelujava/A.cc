#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

bool tell(LL k, LL r, LL t) {
	return 2 * k * k + (2 * r - 1) * k <= t;
}

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		LL r, t;
		scanf("%lld%lld", &r, &t);
		int le = 1, ri = 1e9 + 1;
		if (t / (2 * r - 1) + 1 < ri)
			ri = t / (2 * r - 1) + 1;
		while (le + 1 != ri) {
			int mid = (le + ri) / 2;
			if (tell(mid, r, t))
				le = mid;
			else
				ri = mid;
		}
		printf("Case #%d: %d\n", cas, le);
	}
	return 0;
}
