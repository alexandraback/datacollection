#include <stdio.h>

#define MAXC (2000)

int TT;
int N, X, Y;

double C[MAXC][MAXC];

int main()
{
	int i, j;
	C[0][0] = 1;
	for(i = 1; i < MAXC; ++i)
	{
		C[i][0] = C[i][i] = C[i - 1][0] / 2.0;
		for(j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) / 2.0;
	}

/*
	for(i = 0; i <= 5; ++i)
	{
		for(j = 0; j <= i; ++j)
			printf("%.10lf ", C[i][j]);
		putchar('\n');
	}
//*/

	scanf("%d", &TT);
	for(int tt = 1; tt <= TT; ++tt)
	{
//		X = Y = 0;
//		N = tt;
//		printf("N %d\n", N);
		scanf("%d %d %d", &N, &X, &Y);

		if(X < 0)
			X = -X;
		int xy = ((X + Y) >> 1) + 1;

		j = 0;
		for(i = 0; j < N; ++i)
			j += 4 * i + 1;

//		printf("i %d  j %d\n", i, j);
//		printf("XY %d\n", xy);

		double sol = 0;
		if(xy < i) // inside
			sol = 1;
		else if(xy > i) // outside
			sol = 0;
		else if(j == N) // full triangle
			sol = 1;
		else // in-between
		{
			int l = i - 1;
			int n = j - (4*i - 3);
			int r = N - n;

//			printf("%d %d %d\n", l, n, r);

			for(i = 0; i <= r; ++i)
			{
				int a = i;
				int b = r - i;

				if(a > 2*l)
				{
					a = 2*l;
					b = r - a;
				}
				else if(b > 2*l)
				{
					b = 2*l;
					a = r - b;
				}

//				printf("%d %d -> %d %d\n", i, r - i, a, b);

				if(Y < a)
					sol += C[r][i];
			}
		}

		printf("Case #%d: %.8lf\n", tt, sol);
	}

	return 0;
}
