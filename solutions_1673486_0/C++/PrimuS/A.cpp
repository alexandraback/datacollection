#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

double p[100007];
double correct_p[1000007];

int main()
{
	freopen("A-small0.in","r",stdin);
	FILE *out_fp = fopen("Al.out","w");
	int T;
	scanf("%d", &T);
	for(int test = 1; test <= T; ++test)
	{
		int a, b;

		memset(p, 0, sizeof(p));
		memset(correct_p, 0, sizeof(correct_p));
		scanf("%d%d", &a, &b);
		for (int i = 1; i <= a; ++i)
			scanf("%lf", &p[i]);

		correct_p[0] = 1.0;
		for (int i = 1; i <= a; ++i)
		{
			correct_p[i] = correct_p[i - 1] * p[i];
		}

		for (int i = 0; i < a; ++i)
		{
			correct_p[i] *= (1 - p[i + 1]);
		}

		double exp_tries = b + 2;
		for (int i = 0; i <= a; ++i)
		{
			int cor_tryes = i * 2 + (b - a) + 1;
			int uncor_tries = cor_tryes + b + 1;
			double expext = 0;

			for (int j = 0; j <= a; ++j)
			{
				if (j >= (a - i))
					expext += cor_tryes * correct_p[j];
				else
					expext += uncor_tries * correct_p[j];
			}

			if (expext < exp_tries)
				exp_tries = expext;
		}
		printf("%.8lf\n", exp_tries);
		fprintf(out_fp, "Case #%d: %.8lf\n", test,exp_tries);
	}
	fclose(out_fp);
	return 0;
}