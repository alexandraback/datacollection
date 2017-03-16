#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

bool possible(long long Q) {
	while (Q != 1) {
		if (Q % 2) {
			return false;
		}
		Q /= 2;
	}
	return true;
}

long long generate(long long P, long long Q) {
	if (Q == 2 || 2*P > Q) {
		return 1;
	}
	Q /= 2;

	return generate(P, Q) + 1;
}

int main() 
{
	freopen("A-large.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T;
	long long P, Q;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%lld/%lld", &P, &Q);
		long long tmp = gcd(P, Q);
		P /= tmp;
		Q /= tmp;

		printf("Case #%d: ", i);
		bool b = possible(Q);
		if (!b) {
			printf("impossible\n");
		} else {
			long long ans = generate(P, Q);
			printf("%lld\n", ans);
		}
	}

	return 0;
}