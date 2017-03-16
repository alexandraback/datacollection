#include <bits/stdc++.h>
using namespace std;

int main() {
  int TT;
  cin >> TT;
  for (int tt = 0; tt < TT; ++tt) {
    int n;
    cin >> n;
    vector<int> next(n);
    for (int i = 0; i < n; ++i) {
      cin >> next[i];
      --next[i];
    }
    vector<int> pathy(n, 0);
    int best = 0;
    for (int start = 0; start < n; ++start) {
      int u = start;
      vector<int> visited(n, 0);
      int steps = 0;
      while (!visited[u]) {
        visited[u] = 1;
        u = next[u];
        ++steps;
      }
      if (u == start)
        best = max(best, steps);
      pathy[u] = max(pathy[u], steps - 1);
    }
    int alt = 0;
    for (int i = 0; i < n; ++i)
      if (next[next[i]] == i)
        alt += pathy[i];
    best = max(best, alt);
    cout << "Case #" << tt + 1 << ": " << best << endl;
  }
}
