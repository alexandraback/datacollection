#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
  int t, b;
  long long m;
  cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    int join[50] = {0};
    int ones = 0;
    cin >> b >> m;
    cout << "Case #" << case_num << ": ";
    for (int bi = 1; bi < b - 1; ++bi) {
      join[bi] = m % 2;
      ones += m % 2;
      m /= 2;
    }
    if (ones == 0 and m == 1) {
      for (int bi = 0; bi < b - 1; ++bi) {
        join[bi] = 1;
      }
      m = 0;
    }
    if (m == 0) {
      cout << "POSSIBLE" << endl;
      for (int bi = 0; bi < b; ++bi) {
        cout << join[b - 1 - bi];
      }
      cout << endl;
      for (int bi = 1; bi < b; ++bi) {
        for (int bj = 0; bj < b; ++bj) {
          cout << (bi < bj? 1: 0);
        }
        cout << endl;
      }
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}

