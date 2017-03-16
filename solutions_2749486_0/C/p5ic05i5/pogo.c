#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int X, Y;

void solve() {
	int i;
	if ( X > 0 ) {
		for ( i = 0 ; i < X ; ++i )
			printf("WE");
	} else {
		for ( i = 0 ; i < -X ; ++i )
			printf("EW");
	}
	if ( Y > 0 ) {
		for ( i = 0 ; i < Y ; ++i )
			printf("SN");
	} else {
		for ( i = 0 ; i < -Y ; ++i )
			printf("NS");
	}
}


int main() {
	int i, t, x = 1;
	scanf("%d\n", &t);
	while ( t-- ) {
		scanf("%d %d\n", &X, &Y);
		printf("Case #%d: ", x++);
		solve();
		printf("\n");
	}
	return 0;
}

