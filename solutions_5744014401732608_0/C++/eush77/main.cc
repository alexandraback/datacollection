#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define OUT(var) ' ' << #var "=" << var


class Task {
 public:
  friend std::istream &operator>> (std::istream &in, Task &t) {
    in >> t.n >> t.m;

    t.g.resize(t.n);

    for (auto &row: t.g) {
      row.resize(t.n);
    }

    return in;
  }

  friend std::ostream &operator<< (std::ostream &out, const Task &t) {
    if (!t.possible) {
      return out << "IMPOSSIBLE";
    }

    out << "POSSIBLE";

    for (int i = 0; i < t.n; ++i) {
      out << '\n';

      for (int c: t.g[i]) {
        out << c;
      }
    }

    return out;
  }

  void solve () {
    possible = true;

    for (int i = 1; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        g[i][j] = 1;
      }
    }

    if (m > ((long long) 1) << n - 2) {
      possible = false;
      return;
    }
    else if (m == ((long long) 1) << n - 2) {
      g[0][n - 1] = 1;
      m -= 1;
    }

    for (int to = n - 2; to > 0; --to) {
      if (m & 1) {
        g[0][to] = 1;
      }

      m >>= 1;
    }
  }

 private:
  int n;
  long long m;
  bool possible;
  vector<vector<int>> g;
};


int main () {
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;

  for (int t = 1; t <= T; ++t) {
    Task task;
    std::cin >> task;

    task.solve();

    std::cout << "Case #" << t << ": " << task << '\n';
  }
}
