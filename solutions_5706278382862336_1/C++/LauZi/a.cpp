#include <cstdio>

typedef long long LL;

LL gcd(LL a, LL b) {
    if (a * b == 0) return a + b;
    return gcd(b, a % b);
}

void jizz() {
    LL p, q;
    scanf("%I64d/%I64d", &p, &q);

    int ans = -1; // -1 ~ 40

    LL g = gcd(p, q);
    p /= g, q /= g;

    ans = 0;
    while (p < q) p *= 2, ans += 1;

    if ((q ^ (q & -q)) != 0) ans = -1;

    if (ans > 40) ans = -1;

    if (ans != -1) {
        int chk = 0;
        while ((q /= 2) != 0) chk += 1;
        if (chk > 40) ans = -1;
    }

    if (ans == -1) {
        puts("impossible");
    } else {
        printf("%d\n", ans);
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        jizz();
    }

    return 0;
}
