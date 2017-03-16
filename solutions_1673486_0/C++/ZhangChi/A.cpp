#include <stdio.h>

const int MAXN = 100000 + 10;

double p[MAXN];
int T, A, B;

void Solve ()
{
	scanf ("%d%d", &A, &B);
	for (int i = 1; i <= A; ++i)
		scanf ("%lf", p + i);

	double notypo = 1;
	double answer = 2 + B;
	double keystroke;

	for (int i = 0; i <= A; ++i)
	{
		if (i > 0) {
			notypo = notypo * p[i];
		}

		keystroke = (A - i + B - i + 1) * notypo + (A - i + B - i + 1 + B + 1) * (1 - notypo);

		if (keystroke < answer)
			answer = keystroke;
	}

	printf ("%.6lf\n", answer);
}

int main(int argc, char *argv[])
{
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("A-small.out", "w", stdout);

	scanf ("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		printf ("Case #%d: ", i);
		Solve ();
	}	

	return 0;
}
