#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAXN = (long long)(1e14) + 10000;

vector <long long> x;

bool ok(long long x) {
	long long y = 0, t = x;
	for (; t; t/=10) y = y * 10 + (t % 10);
	return x == y;
}

void init() {
	for (long long i=1; i*i<=MAXN; ++i) {
		long long j = i * i;
		if (ok(i) && ok(j)) x.push_back(j);
	}	
//	for (int i=0; x[i]<=1000; ++i) printf("%lld ", x[i]); puts("");
}

int main() {
	int tc, cn = 0;

	init();
	scanf("%d", &tc);
	while (tc--) {
		long long A, B;
		scanf("%lld%lld", &A, &B);
		int AA = lower_bound(x.begin(), x.end(), A) - x.begin();
		int BB = upper_bound(x.begin(), x.end(), B)	- x.begin();
		printf("Case #%d: %d\n", ++cn, BB-AA);
	}

	return 0;
}
