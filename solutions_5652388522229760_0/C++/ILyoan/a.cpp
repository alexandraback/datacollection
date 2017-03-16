#include <cstdio>

int solve(int n) {
	int y = n;
	int cnt = 0;
	bool digits[10] = {0};
	while (cnt < 10) {
		int x = y;
		while (x > 0) {
			if (!digits[x % 10]) {
				cnt++;
				digits[x % 10] = true;
			}
			x /= 10;
		}
		y = y + n;
	}
	return y - n;
}

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc) {
		int n;
		scanf("%d", &n);

		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", tc);
		} else {
			printf("Case #%d: %d\n", tc, solve(n));
		}
	}
	return 0;
}

