#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int dx[] = {0, 1,0, -1}, dy[] = {-1, 0, 1, 0};

int N, M, K, X, n, m;

void dfs(vector<vector<int>> &a, int i, int j) {
  a[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int ni = i + dy[k], nj = j + dx[k];
    if (0 <= ni && ni < n && 0 <= nj && nj < m && a[ni][nj] == 0) {
      dfs(a, ni, nj);
    } 
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    cin >> N >> M >> K;
    X = N * M;
    n = N + 2;
    m = M + 2;
    int r = 1 << 28;
    for (int k = 0; k < (1 << X); k++) {
      int t = k;
      vector<vector<int>> a(n, vector<int>(m));
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          a[i + 1][j + 1] = t & 1;
          t >>= 1;
        }
      }
      dfs(a, 0, 0);
      int ct = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           ct += 1 - a[i][j];
        }
      }
      if (ct + __builtin_popcount(k) == K) {
        r = min(r, __builtin_popcount(k));
      }
    }
    cout << r << endl;
  }
}