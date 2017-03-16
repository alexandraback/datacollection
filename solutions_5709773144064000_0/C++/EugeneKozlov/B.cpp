#include <cstdio>
#include <vector>

int main()
{
	// 4 30.0 1.0 2.0 30.0 2.0 100.0 30.50000 3.14159 1999.19990 500.0 4.0 2000.0
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int N;
	double C, F, X;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%lf %lf %lf", &C, &F, &X);
		double ct = 1/0.00000000000000000000000000000000001, pt;
		double v = 2;
		double t = 0;
		do
		{
			pt = ct;
			double rf = C / v;
			double rw = X / v;
			ct = t + rw;
			t += rf;
			v += F;
		}
		while(ct < pt);
		printf("Case #%d: %8.7lf\n", i, pt);
	}

	return 0;
}
