#include <stdio.h>
#include <algorithm>
using namespace std;

struct X {
	int a, b;
	int s;
} x[1010];
int cs, ct, n;
int star, game;

bool cmp(X x, X y)
{
	return x.b - x.a> y.b - y.a;
}

int main()
{
	int i;
	bool next;
	scanf("%d", &cs);
	for (ct = 1; ct <= cs; ct++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d%d", &x[i].a, &x[i].b);
			x[i].s = 0;
		}
		sort(x, x + n, cmp);

		star = 0;
		game = 0;
		do {
			next = false;
			for (i = 0; i < n; i++)
			if (x[i].s < 2 && star >= x[i].b) {
				game++;
				star += 2 - x[i].s;
				x[i].s = 2;
				next = true;
				break;
			}
			if (next) continue;
			for (i = 0; i < n; i++)
			if (x[i].s < 1 && star >= x[i].a) {
				game++;
				star += 1- x[i].s;
				x[i].s = 1;
				next = true;
				break;
			}
			if (next) continue;
		} while (next);
		
		if (star == n * 2) {
			printf("Case #%d: %d\n", ct, game);
		}
		else printf("Case #%d: Too Bad\n", ct);
	}
	return 0;
}
