#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 100000;

int A, B;
double p[N];
double minexp()
{
	int i;
	double tp = 1.0;
	double texp, mexp = 3 * B;
	for (i = 0; i <= A; i++)
	{
		texp = ((A - i) + (B - i) + 1) * tp + ((A - i) + (B - i) + 1 + B + 1) * (1.0 - tp);
		if (mexp > texp)
			mexp = texp;
		//printf("i = %d, texp = %.6lf %d*%.2lf + %d*%.2lf\n", i, texp, ((A - i) + (B - i) + 1), tp, ((A - i) + (B - i) + 1 + B + 1), 1.0 - tp);
		tp *= p[i];
	}
	return min(mexp, 1.0 + B + 1.0);
}
int T;
int main(void)
{
	int c, i;
	double ans;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (c = 1; c <= T; c++)
	{
		scanf("%d%d", &A, &B);
		for (i = 0; i < A; i++)
			scanf("%lf", &p[i]);
		printf("Case #%d: %.6lf\n", c, minexp());
	}
	return 0;
}
