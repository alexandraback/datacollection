#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int v[100020];
int t, n;
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		memset(v, 0, sizeof v);
		scanf("%d", &n);
		for (int i = 0; i < n * (2 * n - 1); i++) {
			int x;
			scanf("%d", &x);
			v[x] ^= 1;
		}
		printf("Case #%d: ", tt);
		for (int i = 0; i < 10000; i++) {
			if (v[i] > 0) {
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}