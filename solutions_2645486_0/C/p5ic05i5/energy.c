#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int E, R, N;
int v[10001];

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}


int _profit(int i, int e, int p) {
	if ( i == N )	return p;
	int j;
	int mp = 0;
	for ( j = 0 ; j <= e ; ++j )
		mp = max(mp, _profit(i+1, min(E, e-j+R), p+j*v[i]));
	return mp;
}

int profit() {
	return _profit(0, E, 0);
}

int main() {
	int i, t, x = 1;
	scanf("%d\n", &t);
	while ( t-- ) {
		scanf("%d %d %d\n", &E, &R, &N);
		for ( i = 0 ; i < N ; ++i )
			scanf("%d", &v[i]);
		scanf("\n");
		printf("Case #%d: %d\n", x++, profit());
	}
	return 0;
}

