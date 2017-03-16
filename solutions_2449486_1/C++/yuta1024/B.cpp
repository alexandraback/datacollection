#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int> > lawn(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j)
        cin >> lawn[i][j];
    }

    for (int h = 1; h < 100; ++h) {
      deque<deque<bool> > used(N, deque<bool>(M, false));
      // hor
      for (int i = 0; i < N; ++i) {
        if (count(lawn[i].begin(), lawn[i].end(), h) == M) {
          for (int j = 0; j < M; ++j)
            used[i][j] = true;
        }
      }

      // ver
      for (int i = 0; i < M; ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
          if (lawn[j][i] == h)
            ++cnt;
        }

        if (cnt == N) {
          for (int j = 0; j < N; ++j)
            used[j][i] = true;
        }
      }

      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          if (used[i][j])
            ++lawn[i][j];
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i)
      cnt += count(lawn[i].begin(), lawn[i].end(), 100);

    cout << "Case #" << t+1 << ": ";
    if (cnt == N*M)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
