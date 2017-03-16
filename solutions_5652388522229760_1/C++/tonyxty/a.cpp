#include <cstdio>
using namespace std;

static const int FULL = (1 << 10) - 1;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int n;
		scanf("%d", &n);
		if (!n) printf("Case #%d: INSOMNIA\n", i);
		else {
			int r = 0, f = 0;
			int k;
			do {
				r += n;
				k = r;
				while (k) {
					f |= 1 << (k % 10);
					k /= 10;
				}
			} while (f != FULL);
			printf("Case #%d: %d\n", i, r);
		}
	}
}
