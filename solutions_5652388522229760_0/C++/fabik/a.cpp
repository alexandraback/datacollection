#include <cstdio>

using namespace std;

typedef long long ll;

ll calculate(int n)
{
	if (n == 0) {
		return -1;
	}

	ll current = 0;
	bool found[10] = {};
	int foundCount = 0;

	do {
		current += n;

		for (ll x = current; x > 0; x /= 10) {
			ll digit = x % 10;

			if (!found[digit]) {
				found[digit] = true;
				foundCount++;
			}
		}
	} while (foundCount < 10);

	return current;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int n;
		scanf("%d", &n);
		ll ans = calculate(n);
		printf("Case #%d: ", tc);
		if (ans == -1) {
			printf("INSOMNIA\n");
		} else {
			printf("%lld\n", ans);
		}
	}
	return 0;
}
