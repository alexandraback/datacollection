#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main() {
	int T;
	scanf("%d", &T);
	LL k, c, s;//初始个数， 层数， 可以看的列数
	int kase = 0;
	while (T--) {
		printf("Case #%d: ", ++kase);
		scanf("%lld%lld%lld", &k, &c, &s);
		if (k - c + 1 > s) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		LL idx = 0;
		for (int i = 1; i < c; i++) {
			if (i < k) idx = idx * k + i;
			else idx = idx * k;
		}
		printf("%lld", idx + 1);
		for (int i = 1; i < s && i < k - c + 1; i++) {
			printf(" %lld", idx + i + 1);
		}
		printf("\n");
	}
	return 0;
}
