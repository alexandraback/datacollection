#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef double lf;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

void solve()
{
    ll a, b;
    scanf("%lld/%lld\n", &a, &b);
    ll g = gcd(a, b);
    a /= g, b /= g;
    if ((b & (b - 1)) != 0) printf("impossible\n");
    else
    {
        ll x = b, cnt = 0;
        while (x > a) x /= 2, ++cnt;
        printf("%lld\n", cnt);
    }
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }
	return 0;
}
