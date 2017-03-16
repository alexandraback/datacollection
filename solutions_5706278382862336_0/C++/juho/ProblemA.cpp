#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

long long P;
long long Q;

long long X;

void makeSimple()
{
	long long p = P;
	long long q = Q;
	while (1) {
		long long r = q % p;
		if (r == 0) {
			break;
		}
		q = p;
		p = r;
	}
	P = P / p;
	Q = Q / p;
}

void solve()
{
	makeSimple();
	if (X % Q) {
		printf("impossible\n");
		return;
	}
	for (int i = 0; i < 40; i++) {
		P = P * 2;
		if (P >= Q) {
			printf("%d\n", i+1);
			return;
		}
	}
	printf("impossible\n");
}

int main()
{
	int T;
	scanf("%d", &T);

	X = (long long)1 << 40;

	for (int i = 1; i <= T; i++) {
		scanf("%lld/%lld", &P, &Q);

		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
