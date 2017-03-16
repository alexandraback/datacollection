#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int64_t Divisor(int64_t N) {
  for (int64_t i = 2; i * i <= N; ++i) {
    if (N % i == 0) {
      return i;
    }
  }
  return -1;
}

void Solve() {
  const int N = 16;
  const int J = 500;

  vector<int64_t> divisors;
  vector<int> digits(N);
  int cnt = 0;
  set<uint32_t> used;

  while (cnt < J) {
    divisors.clear();

    uint32_t number = 1;
    digits[0] = 1;
    digits[N - 1] = 1;
    for (int i = 1; i < N - 1; ++i) {
      if (rand() & 1) {
        digits[i] = 1;
      } else {
        digits[i] = 0;
      }
      number *= 2;
      number += digits[i];
    }
    number *= 2;
    ++number;

    if (used.count(number)) {
      continue;
    }
    used.insert(number);

    bool ok = true;
    for (int base = 2; base <= 10; ++base) {
      int64_t value = 0;
      for (int i = 0; i < N; ++i) {
        value *= base;
        value += digits[i];
      }

      int64_t divisor = Divisor(value);
      if (divisor == -1) {
        ok = false;
        break;
      } else {
        divisors.push_back(divisor);
      }
    }

    if (!ok) {
      continue;
    }

    ++cnt;
    for (int d : digits) {
      cout << d;
    }
    for (int d : digits) {
      cout << d;
    }
    for (int d : divisors) {
      cout << ' ' << d;
    }
    cout << endl;
  }
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/input.in", "rb", stdin);
  freopen("../Console/output.out", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    cout << "Case #" << tc + 1 << ":";
    cout << endl;
    Solve();
    // cout << endl;
  }

  return 0;
}
