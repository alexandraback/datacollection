#include <cstdio>
main()
{
	int t, x, r, c, g;
	bool f;
	scanf("%d", &t);
	for (int cs = 1 ; cs <= t ; ++cs) {
		f = 0;
		printf("Case #%d: ", cs);
		scanf("%d%d%d", &x, &r, &c);
		if (x == 1) f = 1;
		else if (x > 1 && x < 7) {
			for (int i = 2 ; i < 7 ; ++i)
				if (x == i && (r * c) % i == 0 && (r > i - 1 || c > i - 1) && (r >= i - 1 && c >= i - 1)) f = 1;
		}
		puts(f ? "GABRIEL" : "RICHARD");
	}
}