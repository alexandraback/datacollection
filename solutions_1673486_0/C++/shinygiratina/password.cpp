#include <cstdio>

using namespace std;

int main (void)
{
	int T, A, B, i, j;
	double p, P;
	double expect, e;
	FILE *fin, *fout;

	fin = fopen ("A-small-attempt2.in", "r");
	fout = fopen ("output.txt", "w");

	fscanf (fin, "%d", &T);
	for (i = 1; i <= T; i++)
	{
		fscanf (fin, "%d%d", &A, &B);

		expect = A + B + 1;

		P = 1;
		for (j = 1; j <= A; j++)
		{
			fscanf (fin, "%lf", &p);
			P = P * p;

			e = P * (B + A - 2 * j + 1) + (1 - P) * (B + A - 2 * j + 1 + B + 1);
			if (e < expect)
				expect = e;
		}

		e = (B + 2);
		if (e < expect)
			expect = e;

		fprintf (fout, "Case #%d: %.30lf\n", i, expect);
	}

	return 0;
}
