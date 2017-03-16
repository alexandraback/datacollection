#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


const int maxn = 10000000;
ll mem[maxn];
bool used[maxn];

ll rev(ll x)
{
    string s = to_string(x);
    reverse(s.begin(), s.end());
    if (s[0] == '0')
        return -1;
    return stoll(s);
}

void pre()
{
    queue <int> q;
    q.push(1);
    used[1] = true;
    mem[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        used[u] = true;
        int v = u + 1;
        if (v < maxn && !used[v])
        {
            mem[v] = mem[u] + 1;
            used[v] = true;
            q.push(v);
        }
        v = rev(u);
        if (v != -1 && v < maxn && !used[v])
        {
            mem[v] = mem[u] + 1;
            used[v] = true;
            q.push(v);
        }
    }
}
int main()
{
    pre();
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    cin >> tn;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

int test = 1;

ll mid(ll n)
{
    string s = to_string(n);
    s = s.substr(1, sz(s) - 2);
    if (s.empty())
        s.push_back('0');
    return stoll(s);
}

ll calc(ll n)
{
//    cerr << n << '\n';
    if (n < 10)
        return n;
    if (n % 10 == 0)
        return calc(n - 1) + 1;

    if (n % 10 > 1)
        return calc(n - 1) + 1;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    ll ans = 0;
    for (int i = 1, p10 = 10; i < (sz(s) + 1) / 2; ++i, p10 *= 10)
    {
        ans += p10 * (s[i] - '0');
        s[i] = '0';
    }
    reverse(s.begin(), s.end());
    n = stoll(s);
    if (to_string(n)[0] != '1' || mid(n) != 0)
        return calc(rev(n)) + ans + 1;
    return calc(n - 1) + ans + 1;
}

int solve()
{
    ll n;
    cin >> n;
    ll ans = calc(n);
//    assert(mem[n] == ans);
    cout << "Case #" << test++ << ": " << ans << '\n';
    return 0;
}
