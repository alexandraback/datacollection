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
#include <tuple> // new
#include <vector>

using namespace std;

#define OUT(var) ' ' << #var "=" << var


class Task {
 public:
  friend std::istream &operator>> (std::istream &in, Task &t) {
    in >> t.j >> t.p >> t.s >> t.k;

    t.jp.resize(t.j);
    for (auto &row: t.jp) {
      row.resize(t.p);
    }

    t.js.resize(t.j);
    for (auto &row: t.js) {
      row.resize(t.s);
    }

    t.ps.resize(t.p);
    for (auto &row: t.ps) {
      row.resize(t.s);
    }

    return in;
  }

  friend std::ostream &operator<< (std::ostream &out, const Task &t) {
    out << t.list.size();

    for (auto &el: t.list) {
      out << '\n'
          << get<0>(el) + 1 << ' '
          << get<1>(el) + 1 << ' '
          << get<2>(el) + 1;
    }

    return out;
  }

  void solve () {
    for (int j1 = 0; j1 < j; ++j1) {
      for (int p1 = 0; p1 < p; ++p1) {
        for (int s1 = 0; s1 < s; ++s1) {
          if (jp[j1][p1] >= k || js[j1][s1] >= k || ps[p1][s1] >= k) {
            continue;
          }

          jp[j1][p1] += 1;
          js[j1][s1] += 1;
          ps[p1][s1] += 1;

          list.emplace_back(j1, p1, s1);
        }
      }
    }
  }

 private:
  int j, p, s, k;
  vector<tuple<int, int, int>> list;

  vector<vector<int>> jp, js, ps;
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
