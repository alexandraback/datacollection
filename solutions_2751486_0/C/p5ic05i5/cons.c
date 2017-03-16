#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, len;
char w[1000002];
int is_cons[128];

int test(int i, int j) {
	int c = 0;
	int run = 0;
	for ( ; i < j && c < n ; ++i )
		if ( is_cons[w[i]] ) {
			if ( !run )	c = 1;
			else c++;
			run = 1;
		} else run = 0;
	return c >= n;
}

long long int n_val() {
	int i, j;
	long long int k = 0;
	for ( i = 0 ; i < len ; ++i ) {
		for ( j = i+1 ; j <= len ; ++j ) {
			k += test(i, j);
		}
	}
	return k;
}

int main() {
	int i, t, x = 1;
	scanf("%d\n", &t);
	memset(&is_cons, 1, sizeof(is_cons));
	is_cons['a'] = is_cons['e'] = is_cons['i'] = is_cons['o'] = is_cons['u'] = 0;
	while ( t-- ) {
		scanf("%[^ ]%n %d\n", &w, &len, &n);
		printf("Case #%d: %lld\n", x++, n_val());
	}
	return 0;
}
