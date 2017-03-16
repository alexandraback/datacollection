#include <stdio.h>

int main() {
	int n, i, j, k, x, r, c;

	scanf("%d", &n);
	for(i=0; i < n; i++) {
		scanf("%d%d%d", &x, &r, &c);
		if(x >= 7 || (r*c)%x != 0 || (x > r && x > c) || x/2+x%2 > r || x/2+x%2 > c || ((r%2 == 0 && r >= 4 && c == 2 || r == 2 && c%2 == 0 && c >= 4) && x == 4) || ((r%2 == 0 && r >= 6 && c == 3 || r == 3 && c%2 == 0 && c >= 6) && x == 6))
			printf("Case #%d: RICHARD\n", i+1);
		else
			printf("Case #%d: GABRIEL\n", i+1);
	}
}
