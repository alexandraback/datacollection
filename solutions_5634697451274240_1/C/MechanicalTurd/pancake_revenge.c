#include <stdio.h>
#include <stdint.h>

int main() {
	int T;
	scanf("%d ", &T);
	for (int t = 1; t <= T; t++) {
		int y = 0, bot = getchar(), c;
		while ((c = getchar()) != '\n')
			y += (c != bot), bot = c;
		y += (bot != '+');
		printf("Case #%d: %d\n", t, y);
	}
	return 0;
}
