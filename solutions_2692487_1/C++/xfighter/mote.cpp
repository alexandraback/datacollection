#include <iostream>
#include <algorithm>
#include <cassert>

#define INF 100000000

using namespace std;

int M[101];
int WT;

int steps (int x, int N) {
  WT = x;
  if (N < x) return 0;
  if (x == 1) return INF;
  int st = 0;
  while (x <= N) {
    x += (x - 1);
    ++st;
  }
  WT = x;
  return st;
}

int main () {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int A, N;
    cin >> A >> N;
    for (int i = 0; i < N; ++i) {
      cin >> M[i];
    }

    sort(M, M + N);

    int start_idx = 0;
    int ans = N;

    int count = 0;
    int wt = A;
    for (int j = 0; j < N; ++j) {
      if (M[j] < wt) {
        wt += M[j];
        ans = std::min(ans, count + N - j - 1);
        continue;
      }
      int st = steps(wt, M[j]);
      count += st;
      wt = WT + M[j];
      ans = std::min(ans, count + N - j - 1);
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
