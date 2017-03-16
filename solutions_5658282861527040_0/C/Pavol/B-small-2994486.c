#include <stdio.h>

int main() {

	int t, _t;
	scanf("%d", &t);

	for ( _t = 0; _t < t; ++_t ) {
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);

		int c = 0;
		int i, j;
		for ( i = 0; i < a; ++i )
			for ( j = 0; j < b; ++j )
				if ( (i & j) < k )
					++c;
		printf("Case #%d: %d\n", _t+1, c);
	}

	return 0;

}
