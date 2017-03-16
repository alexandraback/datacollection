#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long t;
long long n, ten[20], f_ten[20];

void init() {
	ten[0] = 1;
	for (long long i = 1; i <= 14; ++i)
		ten[i] = ten[i - 1] * 10;
	f_ten[0] = 1;
	f_ten[1] = 10;
	long long tmp1 = 19, tmp2 = 90;
	for (long long i = 2; i <= 14; i += 2) {
		f_ten[i] = f_ten[i - 1] + tmp1;
		tmp1 += tmp2;
		f_ten[i + 1] = f_ten[i] + tmp1;
		tmp1 += tmp2;
		tmp2 *= 10;
	}
}

long long reverse(long long k) {
	long long ret = 0;
	while (k) {
		ret = ret * 10 + k % 10;
		k /= 10;
	}
	return ret;
}

long long calcBit(long long k) {
	long long ret = 0;
	while (k) {
		ret++;
		k /= 10;
	}
	return ret;
}

long long calc(long long k) {
	if (k <= 10) return k;
	long long b = calcBit(k);
	long long x = ten[(b + 1) / 2];
	long long k1 = k / x, k2 = k % x;
	if (k2 == 0) {
		return calc(k - 1) + 1;
	}
//	cout << f_ten[b] << " " << k - ten[b - 1] << " " << reverse(k1) + k2 << endl;
	return f_ten[b - 1] + min(k - ten[b - 1], reverse(k1) + k2);
}

int main()
{
	init();
	scanf("%lld", &t);
/*	for (long long ca = 1; ca <= t; ++ca) {
		n = ca;
		printf("%d %lld\n", ca, calc(n));
	}
*/	for (long long ca = 1; ca <= t; ++ca) {
		scanf("%lld", &n);
		printf("Case #%lld: %lld\n", ca, calc(n));
	}
	return 0;
}
