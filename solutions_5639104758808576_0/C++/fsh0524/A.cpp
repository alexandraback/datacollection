#include <cstdio>
#define N 2000
main()
{
	int t, s, sm, ans;
	char a[N];
	scanf("%d", &t);
	for (int cs = 1 ; cs <= t ; ++cs) {
		scanf("%d%s", &sm, a);
		s = ans = 0;
		for (int i = 0 ; i <= sm ; ++i) {
			if (i > s) ans += i - s, s = i;
			s += a[i] - '0';
		}
		printf("Case #%d: %d\n", cs, ans);
	}
}