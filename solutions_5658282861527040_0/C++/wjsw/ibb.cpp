#include <stdio.h>

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		int a,b,k;
		scanf("%d%d%d", &a,&b,&k);
		int r=0;
		for (int i = 0; i < a; ++i)for (int j = 0; j < b; ++j)if((i&j) <k)++r;
		printf("Case #%d: %d\n",tt,r);
	}
}
