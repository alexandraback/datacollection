#include <iostream>
using namespace std;

long long combination(int n, int m) {
  long long ns = 1;
  long long ms = 1;
  for (int i = n; i >= n - m + 1; i--) ns *= i;
  for (int i = m; i >= 1; i--) ms *= i;
  return ns / ms;
}

int main(void) {
  int T;
  cin >> T;

  for (int cases = 1; cases <= T; cases++) {
    int N, X, Y;
    cin >> N >> X >> Y;
    if (X < 0) X *= -1;

    int rank = (X+Y)/2 + 1;
    int rank_diamonds = 2*(rank*rank)-rank;
    int pre_rank_diamonds = 2*((rank-1)*(rank-1))-(rank-1);
    if (rank_diamonds <= N) {
      cout << "Case #" << cases << ": 1.0" << endl;
    } else if (pre_rank_diamonds < N && N < rank_diamonds) {
      int top_Y = 2*(rank-1)+1;
      int left = N - pre_rank_diamonds;
      if (left - (top_Y - 1) > Y) {
        cout << "Case #" << cases << ": 1.0" << endl;
      } else {
        long long cnt = 0;
        for (int i = 0; i <= left; i++) {
          int r = i, l = left - i;
          if (l >= top_Y-1) {
            r += l - (top_Y-1);
            l = top_Y-1;
          }
          if (r >= top_Y-1) {
            l += r - (top_Y-1);
            r = top_Y-1;
          }
          if (r > Y) cnt += combination(left, i);
        }
        cout << "Case #" << cases << ": " << ((long double)cnt)/((long double)(1LL << left)) << endl;
      }
    } else {
      cout << "Case #" << cases << ": 0.0" << endl;
    }
  }
}
