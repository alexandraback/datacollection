#include <stdio.h>

int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int cs, ct, ans;
int a, b;
int mark[2000001] = {0};
int list[100], nl;

int main()
{
	int x, y, h, k;

	scanf("%d", &cs);
	for (ct = 1; ct <= cs; ct++) {
		scanf("%d%d", &a, &b);
		ans = 0;
		for (x = a; x <= b; x++) {
			for (k = -1, y = x; y; y /= 10) k++;
			nl = 0;
			for (y = x, h = 0; h < k; h++) {
				y = y / 10 + (y % 10) * p10[k];
				if (y > x && y <= b) {
					if (!mark[y]) {
						ans++;
						list[nl++] = y;
						mark[y] = 1;
					}
				}
			}
			while (nl) {
				nl--;
				mark[list[nl]] = 0;
			}
		}
		printf("Case #%d: %d\n", ct, ans);
	}	
	return 0;
}
