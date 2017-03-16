#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int N, M, K;

#define BLACK(n, m) (1 << (n * M + m))
#define IS_BLACK(layout, n, m) (layout & BLACK(n, m))

void fill_layout(int &layout, int n, int m) {
  if (IS_BLACK(layout, n, m))
    return;
  layout |= BLACK(n, m);
  if (n > 0)
    fill_layout(layout, n-1, m);
  if (n + 1 < N)
    fill_layout(layout, n+1, m);
  if (m > 0)
    fill_layout(layout, n, m-1);
  if (m + 1 < M)
    fill_layout(layout, n, m+1);
}

int count_layout(int layout) {
  for (int n = 0; n < N; n++) {
    fill_layout(layout, n, 0);
    fill_layout(layout, n, M-1);
  }
  for (int m = 0; m < M; m++) {
    fill_layout(layout, 0, m);
    fill_layout(layout, N-1, m);
  }
  return M * N - __builtin_popcount(layout);
}

int main() {
  int T;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    cin >> N >> M >> K;
    int res = 0;
    if (K > 0) {
      int total = 1 << (N * M);
      int cur_min = K;
      for (unsigned int layout = 1; layout < total; layout++) {
        int count_black = __builtin_popcount(layout);
        if (count_black >= cur_min)
          continue;
        if (count_black + count_layout(layout) >= K)
          cur_min = min(cur_min, count_black);
      }
      res = cur_min;
    }
    cout << "Case #" << CASE << ": " << res << endl;
  }
  return 0;
}
