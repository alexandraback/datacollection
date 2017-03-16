#include <cstdio>
#include <cstring>
const int MAXN = 1000;
int a[MAXN], b[MAXN];
char ed[MAXN];
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	int n;
	for (int ti = 1; ti <= t; ++ti)
	{
		scanf("%d", &n);
		for (int i = 0; i != n; ++i)
		{
			scanf("%d%d", a + i, b + i);
		}
		memset(ed, 0, sizeof(ed));
		int r = 0;
		int ow = 0;
		while (ow < 2 * n) {
			int md = 0, mi = -1;
			bool oy = false;
			for (int i = 0; i != n; ++i) {
				if (ed[i] != 2) {
					if (b[i] <= ow) {
						ow += 2 - ed[i];
						ed[i] = 2;
						++r;
						oy = true;
						break;
					} else if (ed[i] == 0 && a[i] <= ow) {
						if (b[i] - ow > md) {
							md = b[i] - ow;
							mi = i;
						}
					}
				}
			}
			if (!oy) {
				if (mi == -1) {
					// Too Bad
					r = -1;
					break;
				} else {
					ed[mi] = 1;
					ow += 1;
					++r;
				}
			}
		}
		printf("Case #%d: ", ti);
		if (r == -1) {
			puts("Too Bad");
		} else {
			printf("%d\n", r);
		}
	}
	return 0;
}