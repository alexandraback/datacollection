#include <cstdio>
#include <algorithm>

using namespace std;

int table[2000001];

long solve(long n)
{
	return 0;
}

int reverse_digit(int x)
{
	if (x == 0) return 0;
	if (x < 10) return x;
	int t = 0;
	while (x > 0) {
		t = t * 10 + (x % 10);
		x /= 10;
	}
	return t;
}

int main()
{
	int t_max;
	table[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		table[i] = 9999999;
	}

	for (int i = 2; i <= 1000000; i++) {
		int r = reverse_digit(i);
		table[i] = min(table[i], table[i - 1] + 1);
		if (r > i && r <= 1000000) {
			table[r] = min(table[r], table[i] + 1);
		}
	}
	scanf("%d", &t_max);
	for (int t = 1; t <= t_max; t++) {
		long n;
		scanf("%ld", &n);
		printf("Case #%d: %d\n", t, table[n]);
	}
}