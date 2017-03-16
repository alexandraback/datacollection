#include <cstdio>
#include <algorithm>

using namespace std;

#define DIGITS 17

long long ten[DIGITS], to_ten[DIGITS];

long long flip(long long x) {
    long long ret = 0;
    while (x) {
        ret *= 10;
        ret += (x - x / 10 * 10);
        x /= 10;
    }
    return ret;
}

int digits(long long x) {
    return (int)(upper_bound(ten, ten + DIGITS, x) - ten);
}

long long calc(long long n) {
    int len;
    long long f, first, last;
    f = flip(n);
    len = digits(n);
    first = f - f / ten[len / 2] * ten[len / 2];
    if (first == 1) first--;
    last = n - n / ten[(len + 1) / 2] * ten[(len + 1) / 2];
    if (first != 0 && last == 0) {
        // len2 = digits(first);
        // first -= ten[len2 - 1];
        // last = ten[len - len2];
        // if (first == 1) first--;
        return calc(n - 1) + 1;
    }
    return to_ten[len - 1] + first + last;
}

int main() {
    int T, i;
    long long n;
    ten[0] = 1, ten[1] = 10;
    to_ten[0] = 0;
    for (i = 1; i < DIGITS; i++) {
        ten[i + 1] = ten[i] * 10;
        to_ten[i] = to_ten[i - 1] + ten[(i + 1) / 2] + ten[i / 2] - 1;
    }
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%lld", &n);
        printf("%lld\n", calc(n));
    }
    return 0;
}
