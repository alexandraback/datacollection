#include <cstdio>
#include <cmath>

#define PI (acos(-1.0))

long long r, t;

void read() {
	scanf("%lld %lld", &r, &t);
}

void process() {
	long long val;
	if (r & 1) {
		val = 3;
	} else {
		val = 5;
	}
	long long lo = 0, hi = t / r;
	long long initial = (r - 1) / 2;
	while (lo < hi) {
		long long k = lo + (hi - lo + 1) / 2;
		if (k > t / k) {
			hi = k - 1;
			continue;
		}
		long long test = k * val + 2 * (initial + initial + k - 1) * k;
		if (test <= t) {
			lo = k;
		} else {
			hi = k - 1;
		}
	}
	printf("%lld\n", lo);
	return;
	long long accum = 0;
	int i = (r - 1) / 2;
	long long count = 0;
	while (accum + val + 4 * i <= t) {
		accum += val + 4 * i;
		i++;
		count++;
	}
	printf("%lld\n", count);
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		read();
		printf("Case #%d: ", i);
		process();
	}
	return 0;
}