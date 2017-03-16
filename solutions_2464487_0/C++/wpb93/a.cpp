#include <cstdio>
#include <cmath>

int main() {
	int T, r, t, i, b, k;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		scanf("%d%d", &r, &t);
		b = 1 - 2 * r;
		k = (int) ((b + sqrt(b * b + 8 * t)) / 4);
		printf("%d\n", k);
	}
	return 0;
}
