#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int max(long long int r, long long int t) {
	long long int i;
	for ( i = 0 ; t >= 0 ; ++i )
		t -= (2*r+4*i+1);
	return i-1;
}

int main() {
	int i, c, x = 1;
	long long int t, r;
	scanf("%d\n", &c);
	while ( c-- ) {
		scanf("%lld %lld\n", &r, &t);
		printf("Case #%d: %lld\n", x++, max(r, t));
	}
	return 0;
}

