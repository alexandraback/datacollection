#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int t, k, c, s;
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d %d %d", &k, &c, &s);
		if (c * s < k) {
			printf("Case #%d: IMPOSSIBLE\n", tt);
		} else {
			printf("Case #%d:", tt);
			for (int i = 0; i < k; i += c) {
				long long t = 0;
				for (int j = i; j < min(i + c, k); j++) {
					t = t * k + j;
				}
				printf(" %lld", t + 1);
			}
			printf("\n");
		}
	}
	return 0;
}