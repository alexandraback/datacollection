#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int D_MAX = 2000;
const int P_MAX = 2000;
int D;
int P[D_MAX];

void init() {
  cin >> D;
  for (int i = 0; i < D; i++)
    cin >> P[i];
}

void solve_case(int t) {
  init();

  int minutes_needed = P_MAX;
  for (int threshold = 1; threshold < P_MAX; threshold++) {
    int splits = 0;
    for (int i = 0; i < D; i++) {
      splits += (P[i] - 1) / threshold;
    }
    minutes_needed = min(minutes_needed, threshold + splits);
  }
  cout << "Case #" << t << ": " << minutes_needed << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
