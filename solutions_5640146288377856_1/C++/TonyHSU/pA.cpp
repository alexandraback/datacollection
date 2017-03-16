#include<cstdio>
#include<cstdlib>
#include<string.h>

int main() {
	int T;
	scanf("%d", &T);
	for (int nm=1;nm<=T;nm++) {
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		int ans = (c/w)*r;
		if (c%w) {
			ans+= w;
		}
		else {
			ans+= w-1;
		}
		printf("Case #%d: %d\n", nm, ans);
	}
	return 0;
}
