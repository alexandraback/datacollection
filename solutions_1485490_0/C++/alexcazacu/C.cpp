#include <cstdio>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

#define NMAX 110

int N, M;
int A[NMAX], B[NMAX];
long long a[NMAX], b[NMAX];

long long solve () {

	int i, j, l;
	long long sol = 0, x, y, z, dif;
	x = 0;
	for (i = 0; i <= M; i++) {
		if (B[i] == A[1]) {
			if ( a[1] - x > 0) {
				dif = min ( (a[1] - x) , b[i] );
				x+= dif;
			}
		}

		y = 0;
		for (j = 0; j <= M; j++) {
			if (B[j] == A[2]) {
				if ( a[2] - y > 0) {
					dif = min ( (a[2] - y) , b[j] );
					y+= dif;
				}
			}

			z = 0;
			for (l = 0; l <= M; l++) {
				if (B[l] == A[3]) {
					if ( a[3] - z > 0) {
						dif = min ( (a[3] - z) , b[l] );
						z+= dif;
					}
				}

				sol = max (sol, x + y + z);
				//if (l == M) {
					//printf ("%d %d %d = %lld\n", i, j, l, x+y+z);
				//}

				if (l == 0) {
				    if (j - 1 >= 0 || i - 1 >= 0)
                        l = max (j-1, i-1);
				}
			}

			if (j == 0 && i - 1 >= 0) j = i-1;
		}
	}

	return sol;
}

int main () {

	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);

	int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {

		scanf ("%d %d", &N, &M);

		memset (a, 0, sizeof (a)); memset (b, 0, sizeof (b));
		memset (A, 0, sizeof (A)); memset (B, 0, sizeof (B));

		for (int i = 1; i <= N; i++)
			scanf ("%lld %d", &a[i], &A[i]);
		for (int i = 1; i <= M; i++)
			scanf ("%lld %d", &b[i], &B[i]);

		printf ("Case #%d: ", t);
		printf ("%lld\n", solve ());
	}

	return 0;
}

