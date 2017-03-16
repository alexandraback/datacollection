#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

int solve(const vector<vector<int> >& E, int u) {
  int res = 1;
  for (int v : E[u]) {
    res = max(res, 1 + solve(E, v));
  }
  return res;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;

    vector<vector<int> > E(N);
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      A[i]--;
      E[A[i]].push_back(i);
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
      if (i == A[A[i]]) {
        int len = 1;
        for (int v : E[i]) {
          if (v != A[i]) {
            len = max(len, 1 + solve(E, v));
          }
        }
        result += len;
      }
    }

    int timer = 0;
    vector<int> vis(N, -1);
    for (int i = 0; i < N; i++) {
      if (vis[i] != -1) continue;

      int x = i;
      int start_timer = timer;
      while (vis[x] == -1) {
        vis[x] = timer++;
        x = A[x];
      }

      if (vis[x] >= start_timer) {
        result = max(result, timer - vis[x]);
      }
    }
    
    cout << "Case #" << t << ": " << result << endl;
  }
  return 0;
}
