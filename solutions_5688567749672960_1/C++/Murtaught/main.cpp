#include <bits/stdc++.h>
using namespace std;
#define print_out(x) cout << "print_out: " << #x << " == " << x << endl;
#define sz(x) int((x).size())
#define pb(x) push_back(x)
#define mkp(a, b) make_pair(a, b)
#define F first
#define S second
#define whole(a) a.begin(), a.end()
#define FOR(i, S, N) for (int i = S; i < N; ++i)
#define contains(C, key) (C.find(key) != C.end())
typedef vector<int> VInt;
typedef vector<VInt> VVInt;
typedef pair<int, int> PII;
typedef long long int int64;
typedef unsigned int uint;


inline int64 reverse64(int64 num)
{
    VInt digits;
    while (num > 0)
    {
        digits.pb(num % 10);
        num /= 10;
    }

    FOR (i, 0, sz(digits))
    {
        num *= 10;
        num += digits[i];
    }

    return num;
}

inline int reverse(int num)
{
    VInt digits;
    while (num > 0)
    {
        digits.pb(num % 10);
        num /= 10;
    }

    FOR (i, 0, sz(digits))
    {
        num *= 10;
        num += digits[i];
    }

    return num;
}

map<int, int> cache; //, prv;

int f(int n)
{
    if (!contains(cache, n))
    {
        int ans = f(n - 1) + 1;
        int n_rev = reverse(n);

        if (n_rev < n && reverse(n_rev) == n)
        {
            if (f(n_rev) + 1 < ans)
            {
                ans = f(n_rev) + 1;
                //prv[n] = n_rev;
                //cout << n << ": prev = " << prv[n] << "  | ans = " << ans << endl;
            }
        }

        cache[n] = ans;
    }
    return cache[n];
}

int64 g(int64 n)
{
    int64 ans = 0;

    while (n > 99999)
    {
        int back3 = n % 1000;
        if (back3 >= 1)
        {
            ans += back3 - 1;
            n = (n / 1000) * 1000 + 1;
        }
        else
        {
            ans += 999;
            n -= 999;
        }

        int64 rev_n = reverse64(n);
        if (rev_n < n)
            n = rev_n;
        else
            --n;
        ++ans;
    }

    ans += f((int) n);

    return ans;
}

void solve()
{
    int64 n; cin >> n;
    cout << g(n) << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    cache[0] = 0;
    FOR(i, 1, 100007)
    {
        f(i);
    }

    int T; cin >> T;
    for (int tt = 1; tt <= T; ++tt)
    {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}
