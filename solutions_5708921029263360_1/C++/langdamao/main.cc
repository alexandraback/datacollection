#include <cstdio>
#include <algorithm>

using namespace std;

int a, b, c, d;

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("Case #%d: %d\n", tt, a * b * min(c, d));
		for (int i = 1; i <= a; i++) {
			int tmp = ((i - 1) * d) % c + 1;
			for (int j = 1; j <= b; j++)
				for (int k = 1; k <= min(c, d); k++) {
					printf("%d %d %d\n", i, j, tmp);
					tmp++;
					if (tmp > c) tmp = 1;
				}
		}
	}
	return 0;
}
