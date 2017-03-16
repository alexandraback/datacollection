#include <cstdio>

int main() {
	int T, r, c, w;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: %d\n", t, c/w*(r-1)+c/w+w-1+(c%w != 0));
	}
	return 0;
}
