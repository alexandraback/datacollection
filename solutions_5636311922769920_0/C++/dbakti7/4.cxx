#include <cstdio>
int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int t, k, c, s;
	scanf("%d", &t);
	for(int x = 1;x<=t;++x) {
		scanf("%d %d %d", &k, &c, &s);
		printf("Case #%d:", x);
		for(int i = 1;i<=s;++i)
			printf(" %d", i);
		printf("\n");
		
	}
	return 0;
}
