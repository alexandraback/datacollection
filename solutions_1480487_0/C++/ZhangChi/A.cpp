#include <stdio.h>

const int MAXN = 1000;
const double delta = 1e-8;
const double eps = 1e-10;

int T, N, s[MAXN], sum;

bool check (int p, double m)
{
	double avg = s[p] + sum * m / 100;
	double t = 0;
	for (int i = 0; i < N; ++i)
	{
		if (i == p) continue;
		if (s[i] < avg)
			t += (avg - s[i]) / sum * 100;
	}

	return t + m > 100;
}

void Solve ()
{
	scanf ("%d", &N);
	sum = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf ("%d", s + i);
		sum += s[i];
	}

	for (int i = 0; i < N; ++i)
	{
		double L = 0, R = 100;
		while (L < R)
		{
			double m = (L + R) / 2;
			if (check (i, m))
				R = m - delta;
			else
				L = m + delta;
		}

		printf (" %.6lf", R + delta);
	}
	printf ("\n");
}

int main(int argc, char *argv[])
{
	freopen ("A-small-attempt1.in", "r", stdin);
	freopen ("A-small.out", "w", stdout);

	scanf ("%d", &T);

	for (int i = 1; i <= T; ++i)
	{
		printf ("Case #%d:", i);
		Solve ();
	}	

	return 0;
}
