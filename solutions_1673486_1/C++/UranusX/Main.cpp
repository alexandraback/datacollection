#include <cstdio>

int N, L;
double P[100000 + 10];

double Work()
{
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i ++)
		scanf("%lf", &P[i]);
	double Ans = 2 + L;
	double R = 1;
	for (int i = 0; i <= N; i ++)
	{
		double G = (N - i) + R * (L - i + 1) + (1 - R) * (L - i + 1 + L + 1);
		if (G < Ans)
			Ans = G;
		//printf("%.2lf\n", G);
		R *= P[i];
	}
	return Ans;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		printf("Case #%d: %.6lf\n", Case, Work());
	return 0;
}