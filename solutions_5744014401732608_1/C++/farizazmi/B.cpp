#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int vis[N][N];
long long a[N];

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    long long m;
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    a[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      a[i] = 0;
      for (int j = i + 1; j < n; j++)
        if (m >= a[i] + a[j])
          a[i] += a[j], vis[i][j] = 1;
    }
    cout << "Case #" << tc << ": " << (a[0] == m ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    if (a[0] == m) {
      for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
          cout << vis[i][j] << (j == n - 1 ? "\n" : "");
    }
  }
  return 0;
}
