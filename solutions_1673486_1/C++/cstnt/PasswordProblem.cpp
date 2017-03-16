#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 100100;
double P[MAXN];
double C[MAXN];
int A, B;

double solve()
{
	C[0] = P[0];
	for (int i = 1; i < A; i++)
	{
		C[i] = P[i] * C[i - 1];
	}

	// back space all
	double best = (A + B + 1);

	double current;

	for (int i = 0; i < A; i++)
	{
		double allCorrect = C[A - i - 1];
		int finishStrokes = 2 * i + B - A + 1;
		int failedStrokes = finishStrokes + B + 1;

		current = allCorrect * finishStrokes + (1 - allCorrect) * failedStrokes;

		best = min(current, best);
	}

	if (A == B)
	{
		current = C[A - 1] * 1 + (1 - C[A - 1]) * (B + 2);
	}
	else
	{
		current = B + 2;
	}

	return min(best, current);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d%d", &A, &B);
		for (int j = 0; j < A; j++)
		{
			scanf("%lf", &P[j]);
		}

		printf("Case #%d: %.7lf\n", i + 1, solve());
	}
}