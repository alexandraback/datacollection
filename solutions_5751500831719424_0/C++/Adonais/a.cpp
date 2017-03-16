#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	int t, T;
	int n;
	int i, j, k;
	int a, ac, at;
	char s[102];
	char *c;
	char l;
	char cl[101];
	int cls;
	int r[101][101];
	bool e;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		e = false;
		cls = 0;
		scanf("%d%s", &n, s);
		c = s;
		do {
			l = *c;
			cl[cls] = l;
			c++;
			r[0][cls] = 1;
			while (*c && l == *c) {
				c++;
				r[0][cls]++;
			}
			cls++;
		} while (*c);
		for (i = 1; i < n; i++) {
			scanf("%s", s);
			if (!e) {
				c = s;
				j = 0;
				do {
					l = *c;
					if (l != cl[j] || j >= cls) {
						e = true;
						break;
					}
					c++;
					r[i][j] = 1;
					while (*c && l == *c) {
						c++;
						r[i][j]++;
					}
					j++;
				} while (*c);
				if (j != cls) {
					e = true;
				}
			}
		}
		printf("Case #%d: ", t);
		if (e) {
			puts("Fegla Won");
		} else {
			a = 0;
			for (k = 0; k < cls; k++) {
				ac = 100000;
				for (i = 0; i < n; i++) {
					at = 0;
					for (j = 0; j < n; j++) {
						at += abs(r[i][k] - r[j][k]);
					}
					if (at < ac) {
						ac = at;
					}
				}
				a += ac;
			}
			printf("%d\n", a);
		}
	}
	return EXIT_SUCCESS;
}
