#include <algorithm>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <iostream>

using namespace std;

long long GCD(long long x, long long y) { return y == 0 ? x : GCD(y, x % y); }

int main(void)
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	for (int tt = 1; tt <= TC; tt++) {
		printf("Case #%d: ", tt);
		long long P, Q;
		scanf("%lld/%lld", &P, &Q);
		int Ans = -1;
		for (int i = 1; i <= 40; i++) {
			P *= 2;
			long long g = GCD(P, Q);
			P /= g; Q /= g;
			if (Q == P) {
				if (Ans == -1) Ans = i;
				break;
			} else if (P > Q) {
				if (Ans == -1) Ans = i;
				P -= Q;
				g = GCD(P, Q);
				P /= g; Q /= g;
			}
		}
		if (Ans == -1 || !(P == 0 || P == Q)) printf("impossible\n");
		else printf("%d\n", Ans);
	}

	return 0;
}
