#include <cstdio>

int main() {
	freopen("A_small.out", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);

	for (nowCase = 1; nowCase <= numCase; nowCase++) {
		int n;
		scanf("%d", &n);

		char data[1020];
		scanf("%s", data);

		int i, current = 0, ans = 0;
		for (i = 0; data[i]; i++) {
			int num = data[i]-'0';

			if (current < i) {
				ans += i-current;
				current = i;
			}

			current += num;
		}

		printf("Case #%d: %d\n", nowCase, ans);
	}

	return 0;
}