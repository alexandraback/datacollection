#include <cstdio>

int R, C, W, T;

int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		scanf("%d%d%d", &R, &C, &W);
		printf("Case #%d: %d\n", t, (C/W) * R + W - ((C % W == 0) ? 1 : 0));
	}
}
