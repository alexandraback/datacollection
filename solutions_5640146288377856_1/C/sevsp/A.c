#include <stdlib.h>
#include <stdio.h>

int testarr[101];
int main() {
	int i, tests, r, c, w, res;
	scanf("%d", &tests);
	for (i = 1; i <= tests; i++) {
		scanf("%d %d %d", &r, &c, &w);
		if (c == w)
			res = r + (w - 1);
		else if (c % w != 0)
			res = r * (c / w) + w;
		else 
			res = r * (c / w) + w - 1;
		testarr[i] = res;
	}
for (i = 1; i <= tests; i++)
	printf("Case #%d: %d\n", i, testarr[i]);

return 0;
}
