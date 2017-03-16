#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

double C, F, X;

void solve()
{
	double NM = X / C - 2.0 / F - 1.0;
	int N = (int)(NM + 0.99999999);
	N = (N < 0) ? 0 : N;
	double t = 0.0;
	for (int i = 0; i < N; i++) {
		t += C / (2.0 + F * i);
	}
	t += X / (2.0 + F * N);
	printf("%.07lf\n", t);
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		scanf("%lf %lf %lf", &C, &F, &X);

		solve();
	}
	return 0;
}
