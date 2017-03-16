#include <cstdio>
#define min(a, b) ((a)>(b)?(b):(a))
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, R, C, W, runs = 1;
	for (scanf("%d", &T); T--;) {
		scanf("%d%d%d", &R, &C, &W);
		printf("Case #%d: %d\n", runs++, min((C / W)*R + (C%W == 0 ? W - 1 : W), R*C));
	}
}