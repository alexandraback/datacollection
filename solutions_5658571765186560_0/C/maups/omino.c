#include <stdio.h>

int main() {
	int n, i, j, k, x, r, c;

	scanf("%d", &n);
	for(i=0; i < n; i++) {
		scanf("%d%d%d", &x, &r, &c);
		if(x >= 7 || (r*c)%x != 0 || (x > r && x > c) || x/2+x%2 > r || x/2+x%2 > c || ((r == 4 && c == 2 || r == 2 && c == 4) && x == 4))
			printf("Case #%d: RICHARD\n", i+1);
		else
			printf("Case #%d: GABRIEL\n", i+1);
	}
}
