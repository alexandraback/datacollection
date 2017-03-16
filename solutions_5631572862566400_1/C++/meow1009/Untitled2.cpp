#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1010;
bool g[maxn];
int f[maxn];
int a[maxn];

bool c[maxn];

void cal(int x, int t, int avoid)
{
    g[x] = true;
    if (a[x] == t) {
        f[x] = 1;
        return;
    }
    if (a[x] == avoid) {
        f[x] = -1;
        return;
    }
    if (!g[a[x]]) cal(a[x], t, avoid);
    if (f[a[x]] == -1) {f[x] = -1; return;}
    if (f[a[x]] == 0) {f[x] = 0; return;}
    f[x] = f[a[x]] + 1;
    return;
}

void work()
{
    int t;
    cin >> t;
    for (int l = 0; l < t; ++l)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
                memset(g, 0, sizeof(g));
                memset(f, 0, sizeof(f));
                int tot = 0;
                int p = i;
                while (!g[p])
                {
                                g[p] = true;
                                f[p] = ++ tot;
                                p = a[p];
                }
                if (tot - f[p] + 1 > ans) ans = tot - f[p] + 1;
        }
        
        int ans2 = 0;
        
        memset(c, 0, sizeof(c));
        
        for (int i = 1; i <= n; ++i)
        {
                if (c[i]) continue;
                if (a[a[i]] == i)
                {
                                c[i] = true;
                                c[a[i]] = true;
                                int tmp1 = 0;
                                int tmp2 = 0;
                                memset(g, 0, sizeof(g));
                                memset(f, 0, sizeof(f));
                                for (int j = 1; j <= n; ++j)
                                {
                                    if (g[j] || j == i || j == a[i]) continue;
                                    cal(j, i, a[i]);
                                }
                                
                                
                                for (int j = 1; j <= n; ++j) if (f[j] > tmp1) tmp1 = f[j];
                                memset(g, 0, sizeof(g));
                                memset(f, 0, sizeof(f));
                                for (int j = 1; j <= n; ++j)
                                {
                                    if (g[j] || j == i || j == a[i]) continue;
                                    cal(j, a[i], i);
                                }
                                for (int j = 1; j <= n; ++j) if (f[j] > tmp2) tmp2 = f[j];
                                //cout << tmp1 << " " << tmp2 << " *** " << endl;
                                ans2 += tmp1 + tmp2 + 2;
                }
        }
        
      /*  int pair = 0;
        for (int i = 1; i <= n; ++i)
        {
                if (a[a[i]] == i) pair ++;
        }
        if (pair > ans) ans = pair;*/
        if (ans2 > ans) ans = ans2;
        
        cout << "Case #" << l + 1  << ": " << ans << endl;
    }
}               

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    work();
    return 0;
}
