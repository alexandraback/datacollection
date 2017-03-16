#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cassert>
#include <map>
#include <set>
#include <ctime>
#include <unordered_map>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-10;
const int inf = 1000000000;

const int N = 100005;
const int mo = 1000000000 + 7;

int n, vis[N], f[N], g[N], fa[N];

void work(int __case)
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> fa[i];
        f[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        int j = i, len = 0;
        while (!vis[j]) {
            ++len;
            vis[j] = 1;
            j = fa[j];
        }
        g[i] = j;
        f[j] = max(f[j], len);
    }
    vector<int> a;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (g[i] != i) continue;
        int len = 0, j = i;
        while (1) {
            j = fa[j];
            ++len;
            vis[j] = true;
            if (j == i) break;
        }
        if (len > 2)
            ans = max(ans, len);
        else {
            int t = f[i] + f[fa[i]] - 2;
            assert(f[i] >= 2 && f[fa[i]] >= 2);
            a.pb(t);
            ans = max(ans, t);
        }
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if (sz(a) > 0) {
        int sum = 0;
        for (int i = 0; i < sz(a); ++i)
            sum += a[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL_TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        printf("Case #%d: ", i);
        work(i);
    }
    return 0;
}
