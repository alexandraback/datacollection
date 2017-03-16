#include <iostream>
#include <cstdio>
#include <cstring>

#define LL long long
LL k, c, s;
LL num;

int main() {
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int sb;
	scanf("%d", &sb);
	int kase = 0;
	while (sb--) {
		printf("Case #%d: ", ++kase);
		scanf("%lld%lld%lld", &k, &c, &s);
		printf("1");
		for (int i = 1; i < k; i++) {
			num  = i;
			for (int j = 1; j < c; j++) {
				num = num * k + i;
			}
			printf(" %lld", num + 1);
		}
		printf("\n");
	}
	return 0;
}
