#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

int N, J;

void init() {
  cin >> N >> J;
}

void solve_case(int t) {
  init();

  cout << "Case #" << t << ":\n";
  for (int i = 0; i < J; i++) {
    cout << "11";
    for (int j = 0; j < (N - 4) / 2; j++) {
      cout << ((1 << j) & i ? "11" : "00");
    }
    cout << "11";

    for (int j = 2; j <= 10; j++) {
      cout << " " << j + 1;
    }
    cout << "\n";
  }
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
