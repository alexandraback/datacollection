#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	int t, T;
	int a, al, b, bl, k;
	int r;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d%d%d", &a, &b, &k);
		r = 0;
		for (al = 0; al < a; al++) {
			for (bl = 0; bl < b; bl++) {
				if ((al & bl) < k) {
					r++;
				}
			}
		}
		printf("Case #%d: %d\n", t, r);
	}
	return EXIT_SUCCESS;
}
