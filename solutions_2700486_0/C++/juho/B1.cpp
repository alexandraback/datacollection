/******************************************************************************
 * Directives
 *****************************************************************************/
#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

/******************************************************************************
 * Header Files
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/******************************************************************************
 * Constants, Macros, Typedefs, Enums & Structures
 *****************************************************************************/

/******************************************************************************
 * Global & Static Variables
 *****************************************************************************/
int N, X, Y;

/******************************************************************************
 * Global & Static Function Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function Implementations
 *****************************************************************************/
inline double getComb(int n, int k)
{
	double p = 1.0;
	for (int i = 1; i <= k; i++) {
		p = p * (n + 1 - i) / i;
	}
	return p;
}

void runCase()
{
	scanf("%d %d %d", &N, &X, &Y);
	X = X < 0 ? -X : X;

	int Z = (X + Y) / 2;
	int NZO = 2 * Z * Z + 3 * Z + 1;

	if (N >= NZO) {
		printf("1.0\n");
		return;
	}

	if (X == 0) {
		printf("0.0\n");
		return;
	}

	int NZI = 2 * Z * Z - Z;

	if (N <= NZI) {
		printf("0.0\n");
		return;
	}

	Z = Z * 2;
	N = N - NZI; // 1 <= N <= 2 * Z
	Y = Y + 1; // 1 <= Y <= Z

	if (N >= Z + Y) {
		printf("1.0\n");
		return;
	}

	if (N <= Z) {
		// todo get P(k >= Y) = P(k=Y) + P(k=Y+1) + P(k=Y+2) + ...  + P(k=N)
		double p = 0.0;
		for (int i = Y; i <= N; i++) {
			p = p + getComb(N, i);
		}
		p = p / pow(2.0, N);
		printf("%.6lf\n", p);
	} else {
		// N > Z >= Y
		// todo get P(k < Y) = P(k=0) + P(k=1) + P(k=2) + ...  + P(k=Y-1)
		double p = 0.0;
		for (int i = 0; i <= Y - 1; i++) {
			p = p + getComb(N, i);
		}
		p = p / pow(2.0, N);
		p = 1.0 - p;
		printf("%.6lf\n", p);
	}
}

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		runCase();
	}
	return 0;
}
