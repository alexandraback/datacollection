#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int N, M, K;

int main() {
  int T;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    cin >> N >> M >> K;
    if (N > M)
      swap(N, M);
    int res;
    if (K == 0) {
      res = 0;
    } else if (M <= 2 || N <= 2 || K < 4) {
      res = K;
    } else {
      int count_black, count_cover;
      int cur_min = K;
      for (int m1 = 1; m1 <= M-2; m1++) {
        for (int n1 = 1; n1 <= N-2; n1++) {
          for (int n2 = 1; n2 <= n1 && n1 - n2 <= m1; n2++) {
            count_black = m1 * 2 - (n1 - n2) + n1 * 2;
            if (count_black >= cur_min)
              continue;
            count_cover = n2 * m1 + (2 * m1 - (n1 - n2) - 1) * (n1 - n2) / 2;
            if (count_black + count_cover >= K) {
              cur_min = count_black;
              // cout << cur_min << ": ";
              // cout << m1 << ' ' << m1 - (n1 - n2) << ' ' << n1 << ' ' << n2 << endl;
            } else if (count_black + count_cover + (cur_min - count_black - 1) >= K) {
              cur_min = K - count_cover;
              // cout << cur_min << ": ";
              // cout << m1 << ' ' << m1 - (n1 - n2) << ' ' << n1 << ' ' << n2 << endl;
            }
          }
        }
      }
      res = cur_min;
    }
    cout << "Case #" << CASE << ": " << res << endl;
  }
  return 0;
}
