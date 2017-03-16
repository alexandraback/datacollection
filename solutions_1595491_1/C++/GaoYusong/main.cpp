#include <cstdio>

using namespace std;

int main()
{
	int T;

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++) {
		int n, m, p;
		scanf("%d%d%d", &n, &m, &p);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			int a = x / 3, b = x % 3;
			if (b == 0) {
				if (a >= p)
					ans++;
				else {
					if (m > 0 && a - 1 >= 0 && a + 1 <= 10 && a + 1 >= p)
						m--, ans++;
				}
			} else if (b == 1) {
				if (a + 1 >= p)
					ans++;
			} else {
				if (a + 1 >= p) {
					ans++;
				} else {
					if (m > 0 && a + 2 <= 10 && a + 2 >= p)
						m--, ans++;
				}
			}
		}
		printf("Case #%d: %d\n", cn, ans);
	}
	return 0;
}
