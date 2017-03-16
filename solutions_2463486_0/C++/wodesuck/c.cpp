#include <stdio.h>

bool foo(int n)
{
	int len = 0, a[10];
	for (; n; n /= 10) a[len++] = n % 10;
	for (int i = 0; i < len; ++i) if (a[i] != a[len - i - 1]) return false;
	return true;
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int k = 1; k <= dat; ++k) {
		int a, b;
		scanf("%d%d", &a, &b);
		int s = 0;
		for (int i = 1; i * i <= b; ++i) {
			if (i * i >= a && foo(i) && foo(i * i)) {
				// printf("%d\n", i * i);
				++s;
			}
		}
		printf("Case #%d: %d\n", k, s);
	}
}
