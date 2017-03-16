#include <stdio.h>

double PROB[131072];
double tudocertoate[131072];
double min;
double tmp;

int main(void)
{
	int T, A, B;
	int now, i;

	scanf("%d", &T);

	now = T;
	while (now--)
	{
		scanf("%d%d", &A, &B);

		for (i = 0; i < A; i++)
		{
			scanf("%lf", &PROB[i]);
			tudocertoate[i] = PROB[i];
			if (i)
				tudocertoate[i] *= tudocertoate[i - 1];
		}

		/* i = A */
		min = A + B + 1;

		for (i = 0; i < A; i++)
		{
			tmp = tudocertoate[A - 1 - i] * (B - A + 1 + 2*i) +
			 (1 - tudocertoate[A - 1 - i])*((B - A + 1 + 2*i) + (B + 1));
			if (tmp < min)
				min = tmp;
		}

		tmp = 1 + B + 1;
		if (tmp < min)
			min = tmp;


		printf("Case #%d: %.6lf\n", T - now, min);
	}

	return 0;
}
