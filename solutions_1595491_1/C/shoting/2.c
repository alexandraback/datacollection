#include <stdio.h>
#include <string.h>


int main() {
	int t, s, p, n;
	int input, max, diff;
	int i, j, y;
	scanf("%d\n", &t);
	for (i = 0 ; i < t ; ++i) {
	  scanf("%d %d %d", &n, &s, &p);
	  y = 0;
	  max = p * 3;
	  for (j = 0; j < n ; ++j) {
	  	scanf("%d", &input);
		diff = input - max;
		if ( diff > -3 ) {
		  y++;
		} else if ( diff > -5 && s > 0 && p > 1) {
		  y++;
		  s--;
		}
	  }
	  printf("Case #%d: %d\n", i + 1, y);
	}

    return 0;
}
