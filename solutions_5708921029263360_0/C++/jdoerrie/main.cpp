
/* Includes {{{ */
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif
/* }}} Includes */

/* Defines {{{ */
#define DBG(x) std::cerr << #x << " = " << x << std::endl
/* }}} Defines */

/* Typedefs {{{ */
using namespace std;

template <typename T> using V = vector<T>;
template <typename T> using VV = vector<vector<T>>;
template <typename T, size_t N> using A = array<T, N>;
template <typename T, size_t M, size_t N = M> using AA = array<array<T, N>, M>;
template <typename T> using uset = unordered_set<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename T> using mset = multiset<T>;
template <typename K, typename V> using mmap = multimap<K, V>;
template <typename T> using umset = unordered_multiset<T>;
template <typename K, typename V> using ummap = unordered_multimap<K, V>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using max_heap = priority_queue<T, vector<T>, less<T>>;
using i8 = int_fast8_t;
using i16 = int_fast16_t;
using i32 = int_fast32_t;
using i64 = int_fast64_t;
// using i128 = __int128_t;
using u8 = uint_fast8_t;
using u16 = uint_fast16_t;
using u32 = uint_fast32_t;
using u64 = uint_fast64_t;
// using u128 = __uint128_t;
using f32 = float;
using f64 = double;
using f128 = long double;
/* }}} Typedefs */

using triple = tuple<int, int, int>;

void worst_case(int K) {
  if (K == 1) {
    cout << 9 << endl;
    cout << "1 1 2\n";
    cout << "1 2 1\n";
    cout << "1 3 3\n";
    cout << "2 1 1\n";
    cout << "2 2 3\n";
    cout << "2 3 2\n";
    cout << "3 1 3\n";
    cout << "3 2 2\n";
    cout << "3 3 1\n";
  } else if (K == 2) {
    cout << 18 << endl;
    cout << "1 1 1\n";
    cout << "1 1 3\n";
    cout << "1 2 1\n";
    cout << "1 2 2\n";
    cout << "1 3 2\n";
    cout << "1 3 3\n";
    cout << "2 1 1\n";
    cout << "2 1 2\n";
    cout << "2 2 2\n";
    cout << "2 2 3\n";
    cout << "2 3 1\n";
    cout << "2 3 3\n";
    cout << "3 1 2\n";
    cout << "3 1 3\n";
    cout << "3 2 1\n";
    cout << "3 2 3\n";
    cout << "3 3 1\n";
    cout << "3 3 2\n";
  } else {
    cout << 27 << endl;
    cout << "1 1 1\n";
    cout << "1 1 2\n";
    cout << "1 1 3\n";
    cout << "1 2 1\n";
    cout << "1 2 2\n";
    cout << "1 2 3\n";
    cout << "1 3 1\n";
    cout << "1 3 2\n";
    cout << "1 3 3\n";
    cout << "2 1 1\n";
    cout << "2 1 2\n";
    cout << "2 1 3\n";
    cout << "2 2 1\n";
    cout << "2 2 2\n";
    cout << "2 2 3\n";
    cout << "2 3 1\n";
    cout << "2 3 2\n";
    cout << "2 3 3\n";
    cout << "3 1 1\n";
    cout << "3 1 2\n";
    cout << "3 1 3\n";
    cout << "3 2 1\n";
    cout << "3 2 2\n";
    cout << "3 2 3\n";
    cout << "3 3 1\n";
    cout << "3 3 2\n";
    cout << "3 3 3\n";
  }
}

void solve() {
  int J, P, S, K;
  cin >> J >> P >> S >> K;

  if (J == 3 && P == 3 && S == 3) {
    worst_case(K);
    return;
  }

  vector<triple> triples;
  for (int j = 0; j < J; ++j) {
    for (int p = 0; p < P; ++p) {
      for (int s = 0; s < S; ++s) {
        triples.emplace_back(j, p, s);
      }
    }
  }

  int best = 0;
  int best_mask = 0;
  for (size_t mask = 0; mask < (1 << triples.size()); ++mask) {
    vector<int> jp_counts(9);
    vector<int> js_counts(9);
    vector<int> ps_counts(9);
    bool possible = true;
    for (size_t bit = 0; bit < triples.size(); ++bit) {
      if (mask & (1 << bit)) {
        auto &curr = triples[bit];
        if (K < ++jp_counts[3 * get<0>(curr) + get<1>(curr)]) {
          possible = false;
          break;
        }

        if (K < ++js_counts[3 * get<0>(curr) + get<2>(curr)]) {
          possible = false;
          break;
        }

        if (K < ++ps_counts[3 * get<1>(curr) + get<2>(curr)]) {
          possible = false;
          break;
        }
      }
    }

    if (!possible) {
      continue;
    }

    bool is_valid = true;
    for (int i = 0; i < 9; ++i) {
      is_valid &= (jp_counts[i] <= K && js_counts[i] <= K && ps_counts[i] <= K);
    }

    if (is_valid) {
      int curr_bit = __builtin_popcount(mask);
      if (best < curr_bit) {
        best = curr_bit;
        best_mask = mask;
      }
    }
  }

  cout << best << endl;
  for (size_t bit = 0; bit < triples.size(); ++bit) {
    if (best_mask & (1 << bit)) {
      auto &curr = triples[bit];
      cout
        << get<0>(curr) + 1 << " "
        << get<1>(curr) + 1 << " "
        << get<2>(curr) + 1 << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cout << "Case #" << t + 1 << ": ";
    solve();
  }

  return 0;
}
