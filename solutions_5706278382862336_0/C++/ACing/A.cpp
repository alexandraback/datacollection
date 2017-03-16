#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define LL long long

LL mask = 1ll << 40;

LL gcd(LL a, LL b) {
    return b ? gcd(b, a%b) : a;
}

int higheast_bit(LL x) {
    for (int i = 40; i >= 0; --i) if ((x >> i)&1) return 40-i;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        LL P, Q;
        char c;
        cin >> P >> c >> Q;
    //cout << P << " " << Q;
        LL d = gcd(P, Q);
        P /= d, Q /= d;
        if (P > Q || mask % Q != 0) printf("Case #%d: impossible\n", cas);
        else printf("Case #%d: %d\n", cas, higheast_bit(mask / Q * P));
    }
    return 0;
}
