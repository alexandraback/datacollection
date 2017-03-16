#include <cstdio>
#define min(a,b) (a<b)?(a):(b)
double p[100000];
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	int a, b;
	for (int ti = 1; ti <= t; ++ti)
	{
		scanf("%d%d", &a, &b);
		for (int i = 0; i < a; ++i)
		{
			scanf("%lf", p + i);
		}
		double tr = 2 + b;
		double ps = 1;
		int rn = b + a + 1;
		for (int bk = a - 1; bk >= 0; --bk) {
			ps *= p[a - bk - 1];
			rn -= 2;
			double r = ps * rn + (1 - ps) * (rn + b + 1);
			//printf("%d %.6f\n", bk, r);
			tr = min(tr, r);
		}
		printf("Case #%d: %.6f\n", ti, tr);
	}
	return 0;
}