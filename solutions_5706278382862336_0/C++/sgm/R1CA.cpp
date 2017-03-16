#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

using namespace std;

int T;
long long P, Q;

long long gcd(long long x, long long y) {
	long long z;
	while(x > 0) {
		z = y % x;
		y = x;
		x = z;
	}
	return y;
}

bool good(long long m) {
	long long n = 1;
	for(int i = 0; i < 40; i++) {
		n <<= 1;
		if(n == m) return true;
		else if(n > m) return false;
	}
	return false;
}

char NUL;

int main(void) {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%lld", &P);
		scanf("%c", &NUL);
		scanf("%lld", &Q);

		long long g = gcd(P, Q);
		P /= g;
		Q /= g;

		if(!good(Q)) {
			printf("Case #%d: impossible\n", t);
			continue;
		}

		int r = 0;
		while(r < 40) {
			r++;
			P <<= 1;
			if(P >= Q) {
				printf("Case #%d: %d\n", t, r);
				goto next;
			}
		}

		printf("Case #%d: impossible\n", t);
next:
		;
	}
	return 0;
}
