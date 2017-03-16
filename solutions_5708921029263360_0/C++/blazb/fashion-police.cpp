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

int combinations[10001] = {0};
int outfits[10001] = {0};

int max_len = -1;
int best_combo[100000] = {-1};
int cur_combo[100000] = {-1};

int dp[1001][1001] = {0};

int h(int j, int p, int s) { return j + 10 * p + 100 * s; }

bool valid(int j, int p, int s, int k) {
  auto exists = outfits[h(j + 1, p + 1, s + 1)];

  auto combo_valid = combinations[h(0, p + 1, s + 1)] < k &&
                     combinations[h(j + 1, 0, s + 1)] < k &&
                     combinations[h(j + 1, p + 1, 0)] < k;

  return combo_valid && !exists;
}

void add(int j, int p, int s, int len) {
  cur_combo[len - 1] = h(j + 1, p + 1, s + 1);
  if (len > max_len) {
    memcpy(best_combo, cur_combo, len + 1);
    max_len = len;
  }

  outfits[h(j + 1, p + 1, s + 1)] = 1;

  combinations[h(0, p + 1, s + 1)] += 1;
  combinations[h(j + 1, 0, s + 1)] += 1;
  combinations[h(j + 1, p + 1, 0)] += 1;
  dp[len][h(j, p, s)] = 1;
}

void remove(int j, int p, int s) {
  outfits[h(j + 1, p + 1, s + 1)] = 0;

  combinations[h(0, p + 1, s + 1)] -= 1;
  combinations[h(j + 1, 0, s + 1)] -= 1;
  combinations[h(j + 1, p + 1, 0)] -= 1;
}

void solve(int J, int P, int S, int K, int js, int ps, int ss, int len) {
  for (int j = js; j < J; ++j) {
    for (int p = ps; p < P; ++p) {
      for (int s = ss; s < S; ++s) {
        if (valid(j, p, s, K)) {
          add(j, p, s, len + 1);
          solve(J, P, S, K, js, ps, ss + 1, len + 1);
          remove(j, p, s);
        }
      }
    }
  }
}

int main() {
  deque<string> src;
  for (string line; getline(std::cin, line);) {
    src.push_back(line);
  }

  src.pop_front();

  for (int i = 0; i < src.size(); ++i) {
    std::vector<int> a;
    splitstr(src[i], a);

    max_len = -1;
    solve(a[0], a[1], a[2], a[3], 0,0,0, 0);
    cout << "Case #" << i + 1 << ": " <<max_len << endl;
    for (int i = 0; i < max_len; ++i) {
      int c = cur_combo[i];
      int j = c % 10;
      c /= 10;
      int p = c % 10;
      c /= 10;
      int s = c % 10;
      cout << j << " " << p << " " << s << "\n";
    }
  }

  return 0;
}
