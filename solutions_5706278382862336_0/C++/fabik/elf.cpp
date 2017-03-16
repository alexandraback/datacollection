#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

struct zlomek_t
{
	ll a, b;
	void zakladni_tvar()
	{
		if (a == 0) {
			a = 0;
			b = 1;
		} else {
			ll gcd = __gcd(a, b);
			a /= gcd;
			b /= gcd;
		}
	}
};

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);

		zlomek_t zlomek;
		scanf("%lld/%lld", &zlomek.a, &zlomek.b);
		zlomek.zakladni_tvar();

		int vysledek = -1;
		for (int i = 1; i <= 40; i++) {
			zlomek.a *= 2;
			zlomek.zakladni_tvar();
			if (zlomek.a >= zlomek.b) {
				zlomek.a -= zlomek.b;
				if (vysledek == -1) {
					vysledek = i;
				}
			}
		}

		if (vysledek != -1 && zlomek.b == 1) {
			printf("%d\n", vysledek);
		} else {
			printf("impossible\n");
		}
	}
	return 0;
}
