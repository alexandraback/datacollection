#include <cstdio>

#define MAX(a, b) (a > b ? a : b)

int main()
{
	int T, test, N, s[200], i, sum, l1;
	double av, val, a, b, resp[200], s1;

	scanf("%d", &T);
	for (test = 1; test <= T; test++)
	{
		scanf("%d", &N);
		sum = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &s[i]);
			sum += s[i];
		}

		av = 100.0 / (double)N;
		val = (double)sum / (double)N;
		l1 = 0;
		s1 = 0.0;

		printf("Case #%d: ", test);
		for (i = 0; i < N; i++)
		{
			a = 1.0 - ((double)s[i] / val);
			resp[i] = av + av * a;
			if (resp[i] < 0.0)
			{
				l1++;
				s1 += resp[i];
			}
			//printf("%lf ", (b >= 0 ? b : 0));
		}

				for (i = 0; i < N; i++)
				{
					if (resp[i] > 0.0)
					{
						printf("%lf ", MAX((resp[i] + (s1 / (double)(N-l1))), 0.0));
					}
					else
					{
						printf("%lf ", 0.0);
					}
				}
		printf("\n");
	}

	return 0;
}
