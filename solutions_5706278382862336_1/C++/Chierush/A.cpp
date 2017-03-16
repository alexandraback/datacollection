#include <cstdio>

typedef long long llint;

llint gcd(llint x, llint y) {
    llint z;
    while (x % y) {
        z = x % y;
        x = y;
        y = z;
    }
    return y;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	llint P, Q;
	int T;
	char c;
	scanf("%d", &T);
	for (int kcase = 1; kcase <= T; ++kcase) {
		scanf("%lld%c%lld", &P, &c, &Q);
		llint g = gcd(P, Q);
		P /= g;
		Q /= g;
		int cnt = 0;
		llint x = 1;
		while (1.0/x > P*1.0/Q) {
            ++cnt;
            x *= 2;
		}
		bool wrong = false;
		while (Q > 1) {
            if (Q & 1) {
                wrong = true;
                break;
            }
            Q >>= 1;
		}
		if (cnt > 40 || wrong) {
			printf("Case #%d: impossible\n", kcase);
		} else {
            printf("Case #%d: %d\n", kcase, cnt);
		}
	}
	return 0;
}
