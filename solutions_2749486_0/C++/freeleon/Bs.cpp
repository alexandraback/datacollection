#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int get_step(int x) {
	if (x == 0) return 0;
	if (x > 0) return 2*x - 1;
	return 2 * (-x);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int run = 1; run <= T; run++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int a = get_step(x), b = get_step(y);

		printf("Case #%d: ", run);
		int d = 1;
		for (int i = 0; i < a; ++i) {
			putchar( d ? 'E' : 'W');
			d = 1 - d;
		}

		if (y > 0) {
			printf("SN");
			d = 0;
			b = get_step( y );
		} else if (y < 0) {
			printf("NS");
			d = 1;
			b = get_step( -y );
		}
		for (int i = 1; i < b; ++i) {
			putchar( d ? 'N' : 'S');
			d = 1 - d;
		}
		putchar('\n');
	}
	return 0;
}
