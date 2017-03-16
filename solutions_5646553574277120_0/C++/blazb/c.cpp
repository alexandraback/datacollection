#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

template <class T>
void splitstr(const string &s, vector<T> &out) {
  istringstream in(s);
  out.clear();
  copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}

void update_values(std::vector<int> & v, int value) {
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] && i + value < v.size()) {
        v[i + value] = 1;
      }
    }
    v[value - 1] = 1;
}

int solve(std::vector<int> const &cdv, std::vector<int> const &denominations) {
  auto c = cdv[0];
  auto d = cdv[1];
  auto v = cdv[2];
  std::vector<int> values(v, 0);

  auto alld = std::vector<int>(v, 0);
  std::iota(alld.begin(), alld.end(), 1);
  std::vector<int> remaining;
  std::set_difference(alld.begin(), alld.end(), denominations.begin(),
                      denominations.end(), std::back_inserter(remaining));

  for (auto e : denominations) {
    update_values(values, e);
  }

  int num_of_new = 0;

  while (accumulate(values.begin(), values.end(), 0) != values.size()) {
    int max_count = accumulate(values.begin(), values.end(), 0);
    int v = 0;

    for (auto e : remaining) {
      auto viter = values;
      update_values(viter, e);
      auto c = accumulate(viter.begin(), viter.end(), 0);
      if (c > max_count) {
        max_count = c;
        v = e;
      }
    }
    update_values(values, v);
    remaining.erase(std::remove(remaining.begin(), remaining.end(), v),
                    remaining.end());
    ++num_of_new;
  }

  return num_of_new;
}

int main() {
  vector<string> src;
  for (string line; getline(std::cin, line);) {
    src.push_back(line);
  }

  auto it = src.begin();
  ++it;
  int idx = 1;
  for (; it != src.end();) {
    std::vector<int> cdv;
    splitstr(*it++, cdv);
    std::vector<int> denominations;
    splitstr(*it++, denominations);
    std::cout << "Case #" << idx++ << ": " << solve(cdv, denominations)
              << std::endl;
  }

  return 0;
}
