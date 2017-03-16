#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int num = 0, x, y, n, h, z;
double f[5001][5001];

void solve() {
     num++; scanf("%d %d %d", &n, &x, &y);
     if (x < 0) x = -x;
     int l = 1, r = 5000;
     while (l != r) {
           int mid = (l + r) / 2, k = 2 * mid - 1;
           if (k * (k + 1) / 2 >= n) r = mid; else l = mid + 1;
     }
     int tmp = l, now = 2 * l - 1;
//     cout << tmp << " " << now << endl;
     if (now * (now + 1) / 2 == n) {
             if (x + y < now) printf("Case #%d: %.8lf\n", num, 1.0);
             else printf("Case #%d: %.8lf\n", num, 0.0);
             return;
     }
     else if (x == 0 && y == now - 1) {
          printf("Case #%d: %.8lf\n", num, 0.0);
          return;
     }
     if (x + y > now) {
           printf("Case #%d: %.8lf\n", num, 0.0);
           return;
     }
     if (x + y < now - 2) {
           printf("Case #%d: %.8lf\n", num, 1.0);
           return;
     }
     memset(f, 0, sizeof(f));
     int last = n - (now - 2) * (now - 1) / 2;
//     cout << tmp << " " << now << " " << last << " " << y << endl;
     n = now; f[0][0] = 1;
     for (int i = 0; i < n; i++)
     for (int j = 0; j < n; j++) {
         if (j == n - 1) f[i + 1][j] += f[i][j]; 
         else if (i == n - 1) f[i][j + 1] += f[i][j];
         else {
              f[i + 1][j] += f[i][j] / 2.0;
              f[i][j + 1] += f[i][j] / 2.0;
         }
     }
     double ans = 1;
     for (int i = 0; i <= min(last, y); i++) ans -= f[i][last - i];
//     printf("Case #%d: %.6lf\n", num, ans1);
     printf("Case #%d: %.8lf\n", num, ans);
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t; cin >> t; while (t--) solve();
}
