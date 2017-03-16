#include <stdio.h>
#include <iostream>
using namespace std;
int t, d, p[1020];
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d", &d);
		for (int i = 0; i < d; i++) {
			scanf("%d", &p[i]);
		}
		int z = 0x3f3f3f3f;
		for (int k = 1; k <= 1000; k++) {
			int tmp = k;
			for (int i = 0; i < d; i++) {
				tmp += (p[i] - 1) / k;
			}
			z = min(z, tmp);
		}
		printf("Case #%d: %d\n", tt, z);
	}
	return 0;
}