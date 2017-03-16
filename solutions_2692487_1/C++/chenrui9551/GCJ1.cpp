#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int num = 0, a[101], b[101], n, m;

void solve() {
     num++; scanf("%d %d", &m, &n);
     for (int i = 1; i <= n; i++) scanf("%d", a + i);
     if (m < 2) {
           printf("Case #%d: %d\n", num, n);
           return;
     }
     sort(a + 1, a + n + 1);
     int time = 0;
     long long now = m;
     for (int i = 1; i <= n; i++) {
         while (now <= a[i]) now = now + now - 1, time++;
         now += a[i]; b[i] = time;
     }
     int ans = n;
     for (int i = 1; i <= n; i++) ans = min(ans, n - i + b[i]);
     printf("Case #%d: %d\n", num, ans);
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t; cin >> t; while (t--) solve();
}
