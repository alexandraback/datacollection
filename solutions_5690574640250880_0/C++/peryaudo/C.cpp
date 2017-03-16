#include <cstdio>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solver {
 public:
  int r_, c_, m_;
  vector<int> res_; // res.size() <= r_

  Solver(int r, int c, int m) : r_(r), c_(c), m_(m) {}

  //void d() {
  //  for (int i = 0; i < res_.size(); ++i) {
  //    printf("%d ", res_[i]);
  //  }printf("\n");
  //  return;
  //}
  bool search(int max_len, int rem) {
    if (res_.size() >= r_) return false;
    if (rem > max_len) {
      for (int i = max_len; 1 <= i; --i) {
      //printf("res_.size(): %ld max_len: %d i:%d rem: %d\n", res_.size(), max_len, i, rem);

        res_.push_back(i);
        if (search(i, rem - i)) {
          return true;
        }
        res_.pop_back();
      }
      return false;
    } else {
      //printf("c_: %d res_.size(): %d rem: %d\n", c_, (int)res_.size(), rem);
      if (c_ >= 2 && res_.size() >= 1 ? 2 <= rem : true) {
        res_.push_back(rem);

        if (r_ >= 2 && res_.size() == 1 && res_[0] != 1) {
          res_.pop_back();
          return false;
        }
        if (res_.size() > 1 && res_[0] > res_[1]) {
          res_.pop_back();
          return false;
        }

        dump();

        return true;
      } else {
        return false;
      }
    }
  }

  void dump() {
    vector<string> res_str(r_, string(c_, '*'));
    for (int i = 0; i < res_.size(); ++i) {
      for (int j = 0; j < res_[i]; ++j) {
        res_str[i][j] = '.';
      }
    }
    res_str[0][0] = 'c';
    for (int i = 0; i < res_str.size(); ++i) {
      printf("%s\n", res_str[i].c_str());
    }
    return;
  }

  void solve() {
    for (int ic = c_; 1 <= ic; --ic) {
      if (search(ic, r_ * c_ - m_)) return;
    }

    printf("Impossible\n");

    return;
  }
};

int main() {
  int t;
  scanf("%d\n", &t);

  for (int i = 0; i < t; ++i) {
    int r, c, m;
    scanf("%d %d %d\n", &r, &c, &m);

    printf("Case #%d:\n", i + 1);
    Solver solver(r, c, m);
    solver.solve();
  }
}
