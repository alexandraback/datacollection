#include <cstdio>
#include <cassert>
#include <algorithm>

long long base[16];

void init() {
	base[1] = 1;
	for (int i = 2; i < 16; ++i)
		base[i] = base[i - 1] * 10;
}

int Length(long long x) {
	int ret = 0;
	for ( ; x; x /= 10, ret++);
	return ret;
}

long long AnsL(int len) {
	if (len == 2) return 10;
	if (len == 3) return 29;
	long long ret = 29;
	long long now = 109;
	long long add = 90;
	for (int i = 4; i <= len; ++i) {
		ret += now;
		if (i % 2 == 1) add *= 10;
		now += add;
	}
	return ret;
}

long long Compute(long long target, int len) {
	int half = len / 2;
	long long ret = target % base[half + 1];
	target /= base[half + 1];
	long long tmp = 0;
	for ( ; target; target /= 10) {
		tmp = tmp * 10 + target % 10;
	}
	return ret + tmp;
}

long long work(long long target) {
	if (target <= 20) return target;
	int len = Length(target);
	long long need = AnsL(len);
	long long ans = target - base[len];
	ans = std::min(ans, Compute(target, len));
	return ans + need;
}

int main() {
	freopen("a3.out", "w", stdout);
	init();
	int TT;
	assert(scanf("%d", &TT) == 1);
	for (int s = 1; s <= TT; ++s) {
		long long n;
		assert(scanf("%lld", &n) == 1);
		printf("Case #%d: %lld\n", s, work(n));
	}
	return 0;
}
