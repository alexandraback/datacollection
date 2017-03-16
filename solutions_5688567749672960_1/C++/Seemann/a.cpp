#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e5;

char buf[20];

ll reverse(ll x) {
    sprintf(buf, "%lld", x);
    string s = buf;
    reverse(s.begin(), s.end());
    ll a;
    sscanf(s.c_str(), "%lld", &a);
    return a;
}

ll count(int l, ll n) {
    ll st = 1;
    FOR(i, l - 1)
        st *= 10;
    if (n == st)
        return 0;
    ll res = n - st;
    for (ll st1 = 1; st1 < n; st1 *= 10) {
        ll res1 = 1;
        ll front = reverse(n / st1);
        ll tail = n % st1;
        if (tail == 0) {
            front = reverse(n / st1 - 1);
            tail = st1;
        }
        res1 += front + tail - 1;
        res = min(res1, res);
    }
    return res;
}
bool used[1000100];
int d[1000100];
ll bfs(ll n) {
    queue<ll> q;
    clr(used);
    q.push(1);
    d[1] = 1;
    used[1] = true;
    while(!q.empty()) {
        ll cur = q.front();
        if (cur == n)
            return d[cur];
        q.pop();
        ll nx = cur + 1; 
        if (!used[nx]) {
            used[nx] = true;
            d[nx] = d[cur] + 1;
            q.push(nx);
        }
        nx = reverse(cur); 
        if (!used[nx]) {
            used[nx] = true;
            d[nx] = d[cur] + 1;
            q.push(nx);
        }
    }
}

int main() {
//    cerr << reverse(120) << '\n';;
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        ll n;
        cin >> n;
  //      ll ans1 = bfs(n);
//        cerr << ans1 << '\n';
        ll ans = 0;
        ll st = 1;
        int l = 1;
        while (st * 10 <= n) {
            ans += count(l, st * 10 - 1) + 1;
        //    cerr << ans << '\n';
            st *= 10;
            l++;
        }
        ans += count(l, n);
        ans++;
//        cerr << ans1 << '\n' << ans << '\n';
//        assert(ans1 == ans);
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}

