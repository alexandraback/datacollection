#include <cstdio>
#include <algorithm>

using std::min;
using std::max;

long long int gcd(long long int a, long long int b) {
    long long int n = min(a, b), m = max(a, b), tmp;
    while (m % n != 0) {
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int generation(long long int a, long long int b) {
    int t = 0;
    while (b % 2 == 0) {
        t++;
        if (2 * a > b)
            break;
        b /= 2;
    }
    return t;
}

int main()
{
    int T;
    long long int P, Q;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%ld/%ld", &P, &Q);
        long long int g = gcd(P, Q);
        P /= g;
        Q /= g;
        long long int tmp = Q;
        while (tmp % 2 == 0)
            tmp /= 2;
        if (tmp == 1) {
            printf("Case #%d: %ld\n", i, generation(P, Q));
        } else
            printf("Case #%d: impossible\n", i);
    }
    return 0;
}
