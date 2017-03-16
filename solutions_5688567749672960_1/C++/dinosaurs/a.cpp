#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int d = 0;

int T;
long long N;

long long reverse(long long x) {
    long long rev = 0;
    while (x) {
        rev = 10 * rev + x % 10;
        x /= 10;
    }
    return rev;
}

long long solve(long long n) {
    if (d) cout << n << endl;

    if (n <= 19) {
        return n;
    }

    if (n % 10 == 0) {
        return 1 + solve(n - 1);
    }

    long long ten = 1;
    while (10 * ten <= n) {
        ten *= 10;
    }

    long long best = n - ten + 1;
    // goal: get to (ten-1)
    for (long long ten2 = 1; ten2 <= n; ten2 *= 10) {
        long long target = (n / ten2) * ten2 + 1;
        if (target > n) {
            continue;
        }
        if (d) cout << "target: " << target << " " << (n-target+1+reverse(target)%ten+1) << endl;
        best = min(best, n - target + 1 + reverse(target) % ten + 1);
    }
    if (d) cout << "best = " << best << endl;
    return best + solve(ten - 1);
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%lld", &N);

        printf("Case #%d: %lld\n", t, solve(N));
    }

    return 0;
}
