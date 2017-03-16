#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solver {
 public:
  void Solve() {
    long long min = 100000000;
    string sc;
    int i_sc;
    string sj;
    int i_sj;
    for (int c = 0; c < 1000; c++) {
      for (int j = 0; j < 1000; j++) {
        string a, b;
        if (Valid(c, j, &a , &b)) {
          if (std::abs(c - j) < min) {
            min = std::abs(c - j);
            sc = a;
            i_sc = c;
            sj = b;
            i_sj = j;
          } else if (std::abs(c - j) == min) {
            if (i_sc > c) {
              sc = a;
              i_sc = c;
              sj = b;
              i_sj = j;
            } else if (i_sc == c) {
              if (i_sj > j) {
                sc = a;
                i_sc = c;
                sj = b;
                i_sj = j;
              }
            }
          }
        }
      }
    }
    cout << sc << " " << sj << endl;
  }

  bool Valid(int c, int j, string* c_str, string* j_str) {
    *c_str = std::to_string(c);
    *j_str = std::to_string(j);
    if (c_str->size() > C.size()) return false;
    if (j_str->size() > J.size()) return false;
    while (c_str->size() < C.size()) {
      *c_str = ('0' + *c_str);
    }
    while (j_str->size() < J.size()) {
      *j_str = ('0' + *j_str);
    }
    for (int i = 0; i < C.size(); ++i) {
      if (C[i] == '?') continue;
      if (C[i] != c_str->at(i)) return false;
    }
    for (int i = 0; i < J.size(); ++i) {
      if (J[i] == '?') continue;
      if (J[i] != j_str->at(i)) return false;
    }
    return true;
  }

  string C;
  string J;
};

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    Solver solver;
    cout << "Case #" << t + 1 << ": ";
    cin >> solver.C;
    cin >> solver.J;
    solver.Solve();
  }
}
