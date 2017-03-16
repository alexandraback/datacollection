#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
//#define _LARGE_
#define _SMALL_
const int maxn = 1000010;
int f[maxn];
ll p[100];

ll reverse(ll a)
{
    ll ans = 0;
    while (a > 0)
    {
        ans = ans * 10 + a % 10;
        a /= 10;
    }

    return ans;
}

void update(int & a, int b)
{
    if (a == -1)
    {
        a = b;
    }
    else
        a = min(a, b);
}

ll solve(ll n)
{
    if (n <= 1000000)
        return (long long)f[n];

    ll ans = 0;
    int i = 0, j = 0;
    for (; p[i] < n; ++i)
    ;

    --i;

    if (n / p[i] > 1)
    {
        if (n % 10 == 0)
            return 1 + solve(n - 1);
        else
            return n % 10 - 1 + solve(reverse(n / 10 * 10 + 1));
    }
    else
    {
        j++;
        i--;
        //for (; i > j; i--, j++)
        //    if (n / p[i] % 10)
        return 0;
    }
    return 0;
}

int main()
{
    #ifdef _LARGE_
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    #endif

    #ifdef _SMALL_
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    #endif

    memset(f, -1, sizeof(f));
    f[1] = 1;
    for (int i = 2; i < maxn; ++i)
    {
        update(f[i], f[i-1] + 1);
        if (i % 10)
        {
            ll tmp = reverse((ll)i);
            if (tmp > i && tmp < maxn)
                update(f[tmp], f[i] + 1);
        }
    }

    p[0] = 1;
    for (int i = 1; i < 100; ++i)
        p[i] = p[i - 1] * 10;

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas)
    {
        ll n;
        cin >> n;
        printf("Case #%d: %lld\n", cas, solve(n));
    }
    return 0;
}
