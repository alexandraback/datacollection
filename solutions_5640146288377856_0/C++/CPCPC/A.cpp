#include <cstdio>
int main() {
	int T, r, c, w;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d%d%d", &r, &c, &w);
		int ans = (r-1)*(c/w)+(c+w-1)/w-1+w;
		printf("Case #%d: %d\n", C, ans);
	}
	return 0;
}
