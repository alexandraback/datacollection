#include <cstdio>

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		int a = (c-1)/w;
		a *= r;
		a += w;
		printf("Case #%d: %d\n", t, a);
	}
	return 0;
}
