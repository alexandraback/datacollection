#include <cstdio>
main()
{
	int t, x, r, c, g;
	scanf("%d", &t);
	for (int cs = 1 ; cs <= t ; ++cs) {
		printf("Case #%d: ", cs);
		scanf("%d%d%d", &x, &r, &c);
		if (x == 1) puts("GABRIEL");
		else if (x == 2 && (r * c) % 2 == 0) puts("GABRIEL");
		else if (x == 3 && (r * c) % 3 == 0 && (r + c) > 4) puts("GABRIEL");
		else if (x == 4 && (r + c) > 6) puts("GABRIEL");
		else puts("RICHARD");
	}
}