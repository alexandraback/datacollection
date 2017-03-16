#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long gcf(long long a, long long b) {
	long long g;

	if (b != 0)
		g = gcf(b, a % b);
	else
		g = a;
	return g;
}

char checkIfpower2(long long q) {
	if ((q & (q - 1)) == 0)
		return 1;
	else
		return 0;
}

long long evaluate(long long p, long long q) {
	long long r = 0, g = 0;

	g = gcf(p, q);
	p /= g;
	q /= g;

	if (checkIfpower2(q) != 1)
		return -1;

	while (p < q) {
		p *= 2;
		r++;
	}

	if (p == q)
		return r;

	g = 0;
	while (1) {
		p -= q;
		g = gcf(p,q);
		if(g==1) break;

		p/=g;
		q/=g;
		while (p < q) {
			p *= 2;
		}
		if(p==q) return r;
	}

	if (checkIfpower2(p) == 1)
		return r;
	else
		return -1;
}

int main(void) {
	int cases = 0, casen = 0;
	FILE *fin, *fout;
	long long p, q, r;
	p = q = r = 0;

	fin = freopen("in.in", "r", stdin);
	fout = freopen("out1.out", "w", stdout);

	scanf("%d", &cases);
	for (casen = 1; casen <= cases; casen++) {
		scanf("%lld/%lld", &p, &q);

		r = evaluate(p, q);

		printf("Case #%d: ", casen);
		if (r == -1)
			printf("impossible");
		else
			printf("%lld", r);
		printf("\n");
	}
	return 0;
}
