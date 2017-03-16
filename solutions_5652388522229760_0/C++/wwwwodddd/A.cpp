#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", tt);
			continue;
		}
		int v = 0, c = 0;
		while (v != 1023) {
			c += n;
			int t = c;
			while (t > 0) {
				v |= 1 << (t % 10);
				t /= 10;
			}
		}
		printf("Case #%d: %d\n", tt, c);
	}
	return 0;
}
