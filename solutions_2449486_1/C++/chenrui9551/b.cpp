#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int num, n, m, t, a[120][120], h[120], z[120];

void solve(int x) {
     cin >> n >> m;
     for (int i = 1; i <= n; i++) h[i] = -100;
     for (int i = 1; i <= m; i++) z[i] = -100;
     for (int i = 1; i <= n; i++)
         for (int j = 1; j <= m; j++) {
             cin >> a[i][j];
             h[i] = max(h[i], a[i][j]);
             z[j] = max(z[j], a[i][j]);
         }
     bool flag = true;
     for (int i = 1; i <= n; i++)
         for (int j = 1; j <= m; j++)
             if (a[i][j] != min(h[i], z[j])) flag = false;
     cout << "Case #" << x << ": ";
     if (flag) cout << "YES\n";
     else cout << "NO\n";
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t; while (t--) solve(++num);
}
