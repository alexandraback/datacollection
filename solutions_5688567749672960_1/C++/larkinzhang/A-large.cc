#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int T;
long long N, ans;
int test;

inline int length(long long num) {
	int ret = 0;

	while (num) {
		ret++;
		num /= 10;
	}
	
	return ret;
}

long long count(long long num, int len) {
	long long ret1 = 0, ret2 = 0;
	long long seed = 1;
	int i;
	
	for (i = 1; i <= (len + 1) / 2; i++) {
		ret1 = ret1 + (num % 10) * seed;
		num /= 10;
		seed *= 10;
	}
	seed /= 10;
	if (len & 1) seed /= 10;
	for (; i <= len; i++) {
		ret2 = ret2 + (num % 10) * seed;
		num /= 10;
		seed /= 10;
	}
	
	if (ret2 == 1) ret2 = 0;
	return ret1 + ret2;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &N);

		int len = length(N);
		ans = 0;
		long long seed = 1;
		for (int i = 1; i < len; i++) {
			seed *= 10;
			ans += count(seed - 1, i) + 1;
		}

		if (N % 10 != 0) ans += count(N, len);
		else if (N != seed) ans += count(N - 1, len) + 1;

		printf("Case #%d: %lld\n", ++test, ans);
	}

	return 0;
}
