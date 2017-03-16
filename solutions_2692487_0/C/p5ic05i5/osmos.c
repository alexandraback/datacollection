#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (0x7FFFFFFFFFFFFFFFLL)

int n;
int mote[1000000];


int intcmp(const void *x, const void *y) {
	const int *xx = x;
	const int *yy = y;
	return *xx - *yy;
}

long long int min(long long int a, long long int b) {
	return a < b ? a : b;
}

long long int solve(long long int a, int i, long long int ops) {
	if ( i == n )		return ops;
	if ( mote[i] < a )	return solve(a+mote[i], i+1, ops);
	long long int del = solve(a, i+1, ops+1);
	long long int add = 0;
	long long int ins = 0;
	if ( a != 1 ) {
		while ( a <= mote[i] ) {
			a = 2*a - 1;
			add++;
		}
		ins = solve(a+mote[i], i+1, ops+add);
	} else {
		ins = MAX;
	}
	return min(del, ins);
}

int main() {
	long long int a;
	int i, t, x = 1;
	scanf("%d\n", &t);
	while ( t-- ) {
		scanf("%lld %d\n", &a, &n);
		for ( i = 0 ; i < n ; ++i )
			scanf("%d", &mote[i]);
		scanf("\n");
		qsort(&mote, n, sizeof(int), intcmp);

		long long int ops = solve(a, 0, 0);
		printf("Case #%d: %lld\n", x++, ops);
	}
	return 0;
}

