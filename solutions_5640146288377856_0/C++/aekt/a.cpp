#include <cstdio>

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		int a;
		if (w == c) a = c;
		else if (w == 1) a = c;
		else a = (c-1)/w + w;
		printf("Case #%d: %d\n", t, a);
	}
	return 0;
}
