#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

long long K, C, S;

void init() {
  cin >> K >> C >> S;
}

void solve_case(int t) {
  init();

  if (S * C < K) {
    cout << "Case #" << t << ": IMPOSSIBLE\n";
    return;
  }

  set<long long> to_check;
  long long tile = 0;
  for (int i = 0; i < S * C; i++) {
    tile *= K;
    tile += (i % K);

    if ((i + 1) % C == 0) {
      to_check.insert(tile + 1);
      tile = 0LL;
    }
  }

  cout << "Case #" << t << ":";
  for (long long x : to_check) {
    cout << " " << x;
  }
  cout << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
