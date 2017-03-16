#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

long long t, b, a[55][55];
long long m;

void recall(long long k) {
	if (k == b) { return; }

	long long l = b - k;
	long long cc = 1;
	for (long long i = 1; i <= l - 2; i++) {
		cc *= 2;
	}

	if (cc == m) {
		a[k][k + 1] = 1;
		for (long long i = k + 1; i < b; i++) {
			for (long long j = i + 1; j <= b; j++) {
				a[i][j] = 1;
			}
		}
	}
	else if (cc < m && m < cc * 2) {
		a[k][k + 1] = a[k][b] = 1;
		long long v = m - cc - 1;
		for (long long i = b - 1; v; i--) {
			a[k][i] = v % 2;
			v /= 2;
		}
		for (long long i = k + 1; i < b; i++) {
			for (long long j = i + 1; j <= b; j++) {
				a[i][j] = 1;
			}
		}
	}
	else {
		a[k][k + 1] = 1;
		recall(k + 1);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%lld", &t);
	for (long long tt = 1; tt <= t; tt++) {
		scanf("%lld %lld", &b, &m);
		long long c = 1;
		for (long long i = 1; i <= b - 2; i++) {
			c *= 2;
		}
		for (long long i = 1; i <= b; i++) {
			for (long long j = 1; j <= b; j++) {
				a[i][j] = 0;
			}
		}
		if (m > c) {
			printf("Case #%lld: IMPOSSIBLE\n", tt);
			continue;
		}
		printf("Case #%lld: POSSIBLE\n", tt);

		if (m == c) {
			for (long long i = 1; i <= b; i++) {
				for (long long j = 1; j <= b; j++) {
					if (i < j) {
						printf("1");
					}
					else {
						printf("0");
					}
				}
				printf("\n");
			}
		}
		else if (m == 1) {
			for (long long i = 1; i <= b; i++) {
				for (long long j = 1; j <= b; j++) {
					if (i + 1 == j) {
						printf("1");
					}
					else {
						printf("0");
					}
				}
				printf("\n");
			}
		}
		else {
			recall(1);
			for (long long i = 1; i <= b; i++) {
				for (long long j = 1; j <= b; j++) {
					printf("%lld", a[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
