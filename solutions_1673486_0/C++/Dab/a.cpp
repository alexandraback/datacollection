#include <cstdio>
#include <algorithm>

using namespace std;

#define X	1000000 // MAX 

int T, A, B;
float  P[X], R,  C, CC, E;

main()
{
	scanf("%d\n", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d\n", &A, &B);
		for (int n = 0; n < A; ++n) {
			scanf("%f\n", &P[n]);
		}

		int i = 0;
		CC = 1.0;
		E = 1 + B + 1;

		do {
			C = CC * (A-i + B-i + 1) + (1.0-CC) * (A-i + B-i + 1 + B +1);
			E = min(E, C);
			CC *= P[i];
		} while (++i <= A);

		printf("Case #%d: %f\n", t, E);
	}
}
