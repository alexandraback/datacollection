#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		LL r, t;
		scanf("%lld%lld", &r, &t);
		LL cc = 0;
		while (t >= 2 * r + 1) {
			t -= 2 * r + 1;
			r += 2;
			++cc;
		}
		printf("Case #%d: %lld\n", cas, cc);
	}
	return 0;
}
