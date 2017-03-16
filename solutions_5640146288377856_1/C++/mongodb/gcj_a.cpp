#include <cstdio>

int main() {
	int T, r, c, w;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: %d\n", t, (c/w+(c%w != 0))*r+w-1);
	}
	return 0;
}
