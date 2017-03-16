#include <cstdio>
#include <cstring>

int			n;
double		S	[300];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%lf", S + i);
}

void solve()
{
	double sum = 0;
	for (int i = 0; i < n; i ++)
		sum += S[i];

	for (int i = 0; i < n; i ++)
	{
		double low = 0;
		double upp = 1.0;
		double mid;

		while ((upp - low) > 1e-10)
		{
			mid = (low + upp) / 2.0;
			
			double s = S[i] + sum * mid;
			double acc = mid;

			for (int j = 0; j < n; j ++)
				if (i != j && S[j] < s)
					acc += (s - S[j]) / sum;

			if (acc >= 1.0) upp = mid;
			else low = mid;
		}

		printf(" %.5lf", (low + upp) / 2.0 * 100);
	}
	printf("\n");
}

int main()
{
	//freopen("in.txt", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);

	int caseNo;
	scanf("%d", &caseNo);

	for (int t = 1; t <= caseNo; t ++)
	{
		printf("Case #%d:", t);

		init();
		solve();
	}
	return 0;
}