
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int round_div(int dividend, int divisor) {
  return (dividend + (divisor - 1)) / divisor;
}

int main() {
  int T;
  cin >> T;

  vector<int> plates;

  for (int test = 1; test <= T; test++) {
    int D;
    cin >> D;

    plates.resize(D);

    int m = 0;
    for (auto &p : plates) {
      cin >> p;
      m = max(m, p);
    }

    int min_total = INT_MAX;

    for (int i = 1; i <= m ; i++) {
      int moves = 0;

      for (auto p : plates) {
        if (p > i) {
          // move!
          moves += round_div(p, i) - 1;
        }

        // no move
      }

      min_total = min(moves + i, min_total);
    }

    printf("Case #%d: %d\n", test, min_total);
  }
}