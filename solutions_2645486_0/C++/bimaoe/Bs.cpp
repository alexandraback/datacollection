#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
#define LIMN 11
#define LIME 6
int main (void) {
	int T, c;
	int E, R, N, i, e;
	int v[LIMN], g, ans;
	int pd[LIMN][LIME];
	scanf ("%d", &T);
	for (c = 1; c <= T; c++) {
		printf ("Case #%d: ", c);
		memset (pd, -1, sizeof pd);
		memset (pd[0], 0, sizeof pd);
		scanf ("%d%d%d", &E, &R, &N);
		if (R>E)	R = E;
		for (i = 1; i <= N; i++)	scanf ("%d", &v[i]);
		for (i = 1; i <= N; i++)
			for (e = 0; e <= E; e++)
				if (pd[i-1][e] != -1) 
					for (g = 0; g <= e; g++)
						pd[i][min(e-g+R, E)] = max(pd[i][min(e-g+R, E)],pd[i-1][e]+v[i]*g);
		ans = -1;
		for (i = 0; i <= E; i++) if (pd[N][i] > ans)	ans = pd[N][i];
		printf ("%d\n", ans);
	}
	return 0;
}
