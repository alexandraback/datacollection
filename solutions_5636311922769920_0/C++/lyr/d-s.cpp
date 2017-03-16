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
		printf("1");
		for (int i = 1; i < k; i++) {
			LL num  = i;
			for (int j = 1; j < c; j++) {
				num = num * k + i;
			}
			printf(" %lld", num + 1);
		}
		printf("\n");
	}
	return 0;
}
