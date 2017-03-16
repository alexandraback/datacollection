#include <stdio.h>

long long gcd(long long a, long long b) {
	long long tmp;
	while (b) {
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}

int getmsd(long long k) {
	int ans = 0;
	while (k) {
		ans++;
		k >>= 1;
	}
	return ans;
}

bool pot2(long long k) {
	for (int i = 0; i < 60; i++) {
		if (k == 1LL<<i)	return true;
	}
	return false;
}

int main (void) {
	int T, c, x, y;
	long long p, q, d;
	scanf ("%d", &T);
	for (c = 1; c <= T; c++) {
		scanf ("%lld/%lld", &p, &q);
		d = gcd(p, q);
		p /= d; q /= d;
		printf ("Case #%d: ", c);
		if (!pot2(q)) {
			printf ("impossible\n");
			continue;
		}
		x = getmsd(p);
		y = getmsd(q);
		//printf ("%d %d\n", x, y);
		printf ("%d\n", y-x);
	}
	return 0;
}