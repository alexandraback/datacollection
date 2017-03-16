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


int main()
{
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

ll rev(ll x)
{
    string s = to_string(x);
    reverse(s.begin(), s.end());
    if (s[0] == '0')
        return -1;
    return stoll(s);
}

const int maxn = 10000000;
ll mem[maxn];
bool used[maxn];

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

ll calc(ll n)
{
    return mem[n];
//    if (n < 10)
//        return n;
//    ll ans = 0;
//    while (n % 10 > 1)
//    {
//        ans++;
//        n--;
//    }
//    if (to_string(n)[0] > 1)
//    {
//        
//    }
}

int solve()
{
    ll n;
    cin >> n;
    pre();
    ll ans = calc(n);
    cout << "Case #" << test++ << ": " << ans << '\n';
    return 0;
}
