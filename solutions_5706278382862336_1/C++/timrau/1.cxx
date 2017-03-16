#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool isPowerOf2(unsigned long long x)
{
    while(x > 1 && x%2 == 0)
        x >>= 1;
    return x == 1;
}

int check(unsigned long long a, unsigned long long b)
{
    if (!isPowerOf2(b))
        return -1;
    int ans = 0;
    while (a < b)
    {
        b /= 2;
        ++ans;
    }
    return ans;
}

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    if (x < y)
        return gcd(y, x);
    if (y == 0)
        return x;
    return gcd(y, x%y);
}

int main(void)
{
    unsigned long long a, b;
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i)
    {
        printf("Case #%d: ", i);
        scanf("%llu/%llu", &a, &b);
        unsigned long long cd = gcd(a, b);
        a /= cd;
        b /= cd;
        int ans = check(a, b);
        if (ans < 0)
            printf("impossible\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
