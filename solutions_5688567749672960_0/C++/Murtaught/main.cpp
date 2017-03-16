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

map<int, int> cache;

int f(int n)
{
    if (!contains(cache, n))
    {
        int ans = f(n - 1) + 1;
        int rev_n = reverse(n);
        if (rev_n < n && reverse(rev_n) == n)
            ans = min(ans, f(rev_n) + 1);

        cache[n] = ans;
    }
    return cache[n];
}

void solve()
{
    int n;
    cin >> n;

    cout << f(n) << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    cache[0] = 0;

    FOR(i, 1, 1000000)
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
