#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int num, n, t, tt = 0;
long long q[1000];

bool check(long long x) {
     int a[100], t = 0;
     while (x) { a[++t] = x % 10; x /= 10; }
     for (int i = 1; i <= t / 2; i++)
     if (a[i] != a[t - i + 1]) return false;
     return true;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    for (long long i = 1; i <= 2200000; i++)
    if (check(i) && check(i * i)) q[++tt] = i * i;
    cin >> t;
    while (t--) {
          long long l, r; int ans = 0;
          cin >> l >> r;
          for (int i = 1; i <= tt; i++)
          if (q[i] >= l && q[i] <= r) ans++;
          cout << "Case #" << ++num << ": " << ans << endl;
    }
}
