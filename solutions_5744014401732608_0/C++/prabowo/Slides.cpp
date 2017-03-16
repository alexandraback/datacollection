#include <cstdio>
#include <cstring>

typedef long long LL;

int Main () {
	int b;
	LL m;
	
	scanf ("%d %lld", &b, &m);
	if ((1LL << b - 2) < m) {
		puts ("IMPOSSIBLE");
		return 0;
	}
	
	puts ("POSSIBLE");
	
	bool mat[b][b];
	memset (mat, 0, sizeof mat);
	
	for (int i=1; i<b; i++) {
		for (int j=i+1; j<b; j++)
			mat[i][j] = 1;
	}
	
	for (int i=1; i<b-1; i++) {
		if ((1LL << b - i - 2) <= m) {
			mat[0][i] = 1;
			m -= (1LL << b - i - 2);
		}
	}
	
	if (m) mat[0][b-1] = 1;
	
	for (int i=0; i<b; i++) {
		for (int j=0; j<b; j++) 
			printf ("%d", mat[i][j]);
		printf ("\n");
	}
}

int main () {
	freopen ("B-small-attempt0.in", "r", stdin);
	freopen ("B-small-attempt0.out", "w", stdout);

	int t;
	scanf ("%d", &t);
	for (int tc=0; tc<t; tc++) {
		printf ("Case #%d: ", tc + 1);
		Main();
	}
	return 0;
}