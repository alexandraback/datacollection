#include <cstdio>

using namespace std;

bool impossible(long q) {
	while (q > 1) {
		if (q % 2 == 1) return true;
		q /= 2;
	}
	return false;
}

long gcd(long a, long b) {
	if (a < b) {
		long t = a;
		a = b;
		b = t;
	}

	long r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);

	long p, q;

	for (int x = 1; x <= t; x++) {
		scanf("%ld/%ld", &p, &q);
		
		long d = gcd(p, q);
		p /= d;
		q /= d;
		
		if (impossible(q)) {
			printf("Case #%d: impossible\n", x);
			continue;
		}

		int g = 0;
		while (p < q) {
			p <<= 1;
			g++;
		}

		printf("Case #%d: %d\n", x, g);
	}

	return 0;
}