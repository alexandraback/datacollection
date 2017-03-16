#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, j;
  scanf("%d %d", &n, &j);
  bool thirtytwo = n == 32;
  if (thirtytwo) n = 16;
  long long lim = 1LL << (n / 2);
  vector<vector<long long> > m;
  for (long long i = (1LL << (n - 1)) + 1; m.size() <= 500u && i < (1LL << n); i += 2) {
    bool ok = true;
    vector<long long> w;
    w.push_back(i);
    for (int j = 2; ok && j <= 10; j++) {
      long long x = i;
      long long v = 0;
      long long t = 1;
      for (int k = 0; k < n; k++) {
        v += t * (x & 1);
        t *= j;
        x /= 2;
      }
      bool ok2 = false;
      for (long long d = 2; d * d * d <= v; d++) {
        if (v % d == 0) {
          w.push_back(d);
          ok2 = true;
          break;
        }
      }
      ok &= ok2;
    }
    if (ok) {
      m.push_back(w);
    }
  }
  for (int i = 0; i < j; i++) {
    long long t = m[i][0];
    deque<int> st;
    while (t) {
      st.push_front(t & 1);
      t /= 2;
    }
    for (auto x : st) {
      printf("%d", x);
    }
    if (thirtytwo) {
      for (auto x : st) {
        printf("%d", x);
      }
    }
    for (int j = 1; j <= 9; j++) {
      printf(" %lld", m[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d:\n", t);
    solve();
  }
  return 0;
}

