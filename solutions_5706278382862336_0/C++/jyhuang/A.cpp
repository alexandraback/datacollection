#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	while (a) { long long tmp = b % a; b = a; a = tmp; }
	return b;
}

int main(int argc, char *argv[])
{
	int T;

	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		char s[128];
		cin >> s;
		long long p, q, x;
		sscanf(s, "%lld/%lld", &p, &q);
		x = gcd(p, q);
		p /= x; q /= x;
		bool yes = false;
		int ans = 0;
		for (long long t = 1; t <= q; t *= 2, ans++)
			if (t == q) {
				yes = true;
				break;
			}

		if (yes) {
			for (long long t = p; t > 1; t >>= 1)
				ans--;
			printf("Case #%d: %d\n", ti, ans);
		} else {
			printf("Case #%d: impossible\n", ti);
		}
	}

	return 0;
}
