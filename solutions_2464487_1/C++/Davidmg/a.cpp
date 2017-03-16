#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long r, t;

bool check(long long k)
{
    long long x = t + k;
    if (k * 2 > x / k) return false;
    x -= k * k * 2;
    return k * 2 <= x / r;
}


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    int T;
    long long left, right, mid;
    
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%lld%lld", &r, &t);
        left = 1, right = 707106781;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (check(mid)) left = mid + 1;
            else right = mid;
        }
        printf("Case #%d: %lld\n", cas, right - 1);
    }
    return 0;
}
