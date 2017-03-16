#include<cstdio>

int t, r, c, w;

int main() {
	freopen("A_small.in", "r", stdin);
	freopen("A_small.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1 ; i <= t ; i++) {
		scanf("%d %d %d", &r, &c, &w);
		printf("Case #%d: %d\n", i, c / w * r + w - (c % w ? 0 : 1));
	}
	scanf("\n");
	return 0;
}
