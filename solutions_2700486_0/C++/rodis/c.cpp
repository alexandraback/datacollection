#include <cstdio>
#include <algorithm>
using namespace std;

// k out of n
long double attsucc(long long k, long long n)
{
//     printf("attsucc %Ld %Ld\n", k, n);
    if (k > n)
        return 0;

    long double res = 0, tmpval = 1;
    // (n,k) + (n,k+1) + ... + (n, n)
    for (long long i = 1; i <= n - k + 1; ++i) {
        res += tmpval;
        tmpval *= (long double) (n-i+1) / (long double) (i);
//         printf("i %2d res %Lf tmpval %Lf\n", i, res, tmpval);
    }
    while (n--)
        res *= 0.5;
    return res;
}

long double solve()
{
    long long k, x, y;
    scanf("%Ld%Ld%Ld", &k, &x, &y);
    x = x < 0 ? -x : x;
    long long n = 1;
    while (k > 2*n - 1) {
        k -= 2*n - 1;
        n += 2;
    }
//     printf("%Ld %Ld\n", n, k);
    // clooose
    if (x + y < n - 1)
        return 1;
    // faaar...
    if (x + y > n - 1)
        return 0;

    // top?
    if (y == n - 1)
        return (k == 2 * n - 1);
    // close?
    if (k >= n + y)
        return 1;

    // x+1 out of k attempts successful
    return attsucc(y + 1, k);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: %Lf\n", i, solve());
    }
}
