
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
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
/* }}} Includes */

/* Defines {{{ */
#define DBG(x) std::cerr << #x << " = " << x << std::endl
/* }}} Defines */

/* Typedefs {{{ */
using namespace std;

template<typename T>
using V = vector<T>;
template<typename T>
using VV = vector<vector<T>>;
template<typename T, size_t N>
using A = array<T,N>;
template<typename T, size_t M, size_t N = M>
using AA = array<array<T,N>,M>;
template<typename T>
using uset = unordered_set<T>;
template<typename K, typename V>
using umap = unordered_map<K,V>;
template<typename T>
using mset = multiset<T>;
template<typename K, typename V>
using mmap = multimap<K,V>;
template<typename T>
using umset = unordered_multiset<T>;
template<typename K, typename V>
using ummap = unordered_multimap<K,V>;
template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;
using i8   = int_fast8_t;
using i16  = int_fast16_t;
using i32  = int_fast32_t;
using i64  = int_fast64_t;
// using i128 = __int128_t;
using u8   = uint_fast8_t;
using u16  = uint_fast16_t;
using u32  = uint_fast32_t;
using u64  = uint_fast64_t;
// using u128 = __uint128_t;
using f32  = float;
using f64  = double;
using f128 = long double;
/* }}} Typedefs */

string flip(const string &str) {
  string res;
  for (size_t i = 0; i < str.size(); ++i) {
    int j = str.size() - 1 - i;
    res += (str[j] == '-' ? '+' : '-');
  }

  return res;
}

int solve(string s) {
  while (!s.empty() && s.back() == '+') {
    s.pop_back();
  }

  if (s.empty()) {
    return 0;
  }

  int minus = s.find('-');
  if (minus == 0) {
    // s starts with minuses, hence we should flip
    return 1 + solve(flip(s));
  } else {
    return 1 + solve(flip(s.substr(0, minus)) + s.substr(minus));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    string S;
    cin >> S;

    cout << "Case #" << i + 1 << ": " << solve(S) << '\n';
  }

  return 0;
}
