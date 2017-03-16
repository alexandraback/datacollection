#include <algorithm>
#include <cassert> // new
#include <cmath>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits> // new
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>


#define OUT(var) ' ' << #var "=" << var


typedef long long score_t;


class Task {
 public:
  friend std::istream &operator>> (std::istream &in, Task &_) {
    in >> _.coders >> _.jammers;
    _.size = _.coders.size();
    return in;
  }

  friend std::ostream &operator<< (std::ostream &out, const Task &_) {
    score_t power = 1, up;
    for (int i = 1; i < _.size; ++i, power *= 10);

    for (up = power; _.coders_opt < up; up /= 10) {
      out << '0';
    }

    if (up) {
      out << _.coders_opt;
    }

    out << ' ';

    for (up = power; _.jammers_opt < up; up /= 10) {
      out << '0';
    }

    if (up) {
      out << _.jammers_opt;
    }
    return out;
  }

  void solve () {
    score_t power = 1;
    score_t cmin{}, cmax{}, jmin{}, jmax{}, copt{}, jopt{};
    score_t diff_opt = 0;

    for (int index = size - 1; index >= 0; --index, power *= 10) {
      char c = coders[index];
      char j = jammers[index];
      score_t copt_new = copt;
      score_t jopt_new = jopt;
      score_t diff;

      if (c == '?' && j == '?') {
        if ((diff = power + jmin - cmax) < diff_opt) {
          diff_opt = diff;
          copt_new = cmax;
          jopt_new = power + jmin;
        }

        if ((diff = power + cmin - jmax) < diff_opt) {
          diff_opt = diff;
          copt_new = power + cmin;
          jopt_new = jmax;
        }

        cmax += 9 * power;
        jmax += 9 * power;
      }
      else if (c == '?') {
        int digit = j - '0';

        copt_new += digit * power;
        jopt_new += digit * power;

        if (digit > 0 && ((diff = power + jmin - cmax) <= diff_opt)) {
          diff_opt = diff;
          copt_new = (digit - 1) * power + cmax;
          jopt_new = digit * power + jmin;
        }

        if (digit < 9 && ((diff = power + cmin - jmax) < diff_opt)) {
          diff_opt = diff;
          copt_new = (digit + 1) * power + cmin;
          jopt_new = digit * power + jmax;
        }

        cmax += 9 * power;
        jmin += digit * power;
        jmax += digit * power;
      }
      else if (j == '?') {
        int digit = c - '0';

        copt_new += digit * power;
        jopt_new += digit * power;

        if (digit > 0 && ((diff = power + cmin - jmax) <= diff_opt)) {
          diff_opt = diff;
          copt_new = digit * power + cmin;
          jopt_new = (digit - 1) * power + jmax;
        }

        if (digit < 9 && ((diff = power + jmin - cmax) < diff_opt)) {
          diff_opt = diff;
          copt_new = digit * power + cmax;
          jopt_new = (digit + 1) * power + jmin;
        }

        cmin += digit * power;
        cmax += digit * power;
        jmax += 9 * power;
      }
      else {
        int cdigit = c - '0';
        int jdigit = j - '0';

        if (c == j) {
          copt_new += cdigit * power;
          jopt_new += jdigit * power;
        }
        else if (c < j) {
          copt_new = cdigit * power + cmax;
          jopt_new = jdigit * power + jmin;
        }
        else {
          copt_new = cdigit * power + cmin;
          jopt_new = jdigit * power + jmax;
        }

        diff_opt = std::abs(copt_new - jopt_new);

        cmin += cdigit * power;
        cmax += cdigit * power;
        jmin += jdigit * power;
        jmax += jdigit * power;
      }

      copt = copt_new;
      jopt = jopt_new;

      std::cerr << '[' << index << ']'
                << OUT(diff_opt)
                << OUT(copt) << OUT(jopt)
                << OUT(cmin) << OUT(cmax)
                << OUT(jmin) << OUT(jmax)
                << '\n';
    }

    coders_opt = copt;
    jammers_opt = jopt;
  }

 private:
  int size;
  std::string coders, jammers;
  score_t coders_opt, jammers_opt;
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
