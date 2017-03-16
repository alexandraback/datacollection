#include <bits/stdc++.h>

int main() {freopen("inn.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d",&T);
	for (int tc = 1; tc <= T; tc++) {
		int Smax,count=0,add=0;
		char c;
		scanf("%d ",&Smax);
		for (int i = 0; i <= Smax; i++) {
			scanf("%c",&c);
			if (i > count) {
				add += (i-count);
				count += (i-count);
			}
			count += (c-'0');
		}
		printf("Case #%d: %d\n",tc,add);
	}
	return 0;
}