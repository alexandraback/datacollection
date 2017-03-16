#include <bits/stdc++.h>

using namespace std;

int n, a[1000];
vector<int> e[1000];

int max_depth(int u, int p) {
  int d = 0;
  for (int i = 0; i < (int)e[u].size(); ++i) {
    int v = e[u][i];
    if (v == p) {
      continue;
    }
    d = max(d, 1 + max_depth(v, u));
  }
  return d;
}

int main() {
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);

  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      e[a[i]].push_back(i);
    }
    int ans0 = 0;
    for (int i = 0; i < n; ++i) {
      int j = a[i];
      if (a[j] == i) {
        ans0 += 2 + max_depth(i, j) + max_depth(j, i);
      }
    }
    ans0 /= 2;
    int ans1 = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i, k = 1; k <= n + 1; j = a[j], ++k) {
        if (j == i && k != 1) {
          ans1 = max(ans1, k - 1);
          break;
        }
      }
    }
    cout << "Case #" << test << ": " << max(ans0, ans1) << endl;
  }
  return 0;
}
