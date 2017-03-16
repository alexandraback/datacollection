#define y1 JulioCortasar
#define y2 GabrielGarsiaMarkes
#include <bits/stdc++.h>
#undef y1
#undef y2

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define pb push_back
#define mp make_pair
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef double lf;

const ll inf = 1e9 + 100500;

#define TASK_NAME "INSERT_TASK_NAME_HERE"
#define TASK_LETTER "a"

#define STANDART_INPUT

#ifdef LOCAL
void initrand()
{
    ll seed;
    asm("rdtsc":"=A"(seed));
    srand(seed);
}
#endif

ll flip(ll x)
{
    ll ans = 0;
    for (; x; ans = ans * 10 + x % 10, x /= 10);
    return ans;
}

ll getans(ll x)
{
    if (x == 1) return 1;
    ll p = 10;
    while (p * p <= x) p *= 10;
    ll q = flip(x);
    if (x % p == 1 && q < x)
        return getans(flip(x)) + 1;
    if (x % p == 1 && q >= x)
        return getans(x - 1) + 1;
    if (x % p == 0)
        return getans(x - 1) + 1;
    return getans(x - (x % p - 1)) + (x % p - 1);
}

void solve()
{
    ll x;
    cin >> x;
    cout << getans(x) << endl;
}

int main()
{
#ifdef LOCAL
    freopen(TASK_LETTER ".in", "r", stdin);
#else
#ifndef STANDART_INPUT
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif
#endif
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
#ifdef LOCAL
    cerr << "Time = " << clock() / 1000 << " ms." << endl;
#endif
	return 0;
}
