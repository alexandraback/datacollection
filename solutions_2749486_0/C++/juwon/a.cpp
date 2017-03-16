#include <cstdio>
#include <cstdlib>

int x, y;

int main() {
	int r;
	scanf("%d", &r);
	for (int cs = 1; cs <= r; ++cs) {
		printf("Case #%d: ", cs);
		scanf("%d %d", &x, &y);
		for (int i = 0; i < abs(x); ++i) {
			if (x > 0) printf("WE");
			else printf("EW");
		}
		for (int i = 0; i < abs(y); ++i) {
			if (y > 0) printf("SN");
			else printf("NS");
		}
		printf("\n");
	}
	return 0;
}
