#include<cstring>
#include<cstdio>
int a[1111];
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq(1); qq <= tests; qq++) {
		int k, c, s;
		printf("Case #%d:", qq);
		scanf("%d%d%d", &k, &c, &s);
		if(s >= (k + c - 1) / c) {
			for(int i(1); i <= (k + c - 1) / c; i++) {
				for(int j(0); j < c; j++) {
					a[j] = (i - 1) * c + j;
					if(a[j] >= k) {
						a[j] = 0;
					}
				}
				long long ans(0);
				for(int j(0); j < c; j++) {
					ans = ans * k + a[j];
				}
				printf(" %I64d", ans + 1);
			}
			printf("\n");
		}else {
			printf(" IMPOSSIBLE\n");
		}
	}
}
