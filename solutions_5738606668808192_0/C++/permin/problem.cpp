#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

#if GCC_VERSION > 40900
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#endif
using namespace std;

#ifdef LOCAL_RUN
#define debug(x) cerr << #x << ": " << (x) << "\n";
#else
#define debug(x) ;
#endif

#define all(v) (v).begin(), (v).end()
#define MP make_pair

template <class T>
class IsIterable__ {
  static void f(...);
  template <class U>
  static typename U::const_iterator f(const U &);

 public:
  const static bool value =
      !std::is_same<void, decltype(f(std::declval<T>()))>::value;
};

template <class F, class S>
ostream &operator<<(ostream &o, const pair<F, S> &p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

template <class C>
void O__(ostream &o, const C &c) {
  bool f = 1;
  for (const auto &x : c) {
    if (!f) {
      o << ", ";
    }
    if (IsIterable__<decltype(x)>::value) {
      o << "\n";
    }
    f = 0;
    o << x;
  }
}

template <class T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  O__(o, v);
  o << "]";
  return o;
}

template <class T, class V>
ostream &operator<<(ostream &o, const map<T, V> &v) {
  o << "{";
  O__(o, v);
  o << "}";
  return o;
}

template <class T>
ostream &operator<<(ostream &o, const set<T> &v) {
  o << "{";
  O__(o, v);
  o << "}";
  return o;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = std::numeric_limits<int>::max();
const long long LLINF = std::numeric_limits<ll>::max();

#if GCC_VERSION > 40900
// supports find_by_order(int) and order_of_key(Key)
template <class Key, class Value>
using MapWithOrderStatistics =
    tree<Key, Value, std::less<Key>, rb_tree_tag /*splay_tree_tag*/,
         tree_order_statistics_node_update>;
#endif

int main() {
  std::ios_base::sync_with_stdio(false);
  int N = 16;
  size_t J = 50;
  int t;
  cin >> t >> N >> J;
  cout << "Case #1:\n";

  vi primes;
  for (int i = 2; primes.size() < 100; ++i) {
    bool ok = true;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        ok = false;
      }
    }
    if (ok) {
      primes.push_back(i);
    }
  }

  viii d_pow_n_mod_prime_i(11, vii(32, vi(primes.size(), -1)));
  for (int d = 2; d <= 10; ++d) {
    for (int n = 0; n < 32; ++n) {
      for (size_t i = 0; i < primes.size(); ++i) {
        if (n == 0) {
          d_pow_n_mod_prime_i[d][n][i] = 1;
        } else {
          d_pow_n_mod_prime_i[d][n][i] =
              (d_pow_n_mod_prime_i[d][n - 1][i] * d) % primes[i];
        }
      }
    }
  }

  vii res;
  vii factors;
  while (res.size() < J) {
    debug(res.size());
    vi ans(N);
    vii d___mod_prime_i(11, vi(primes.size()));
    for (size_t i = 0; i < ans.size(); ++i) {
      if (i == 0 || i + 1 == ans.size()) {
        ans[i] = 1;
      } else {
        ans[i] = rand() % 2;
      }
    }
    for (size_t i = 0; i < ans.size(); ++i) {
      if (ans[i]) {
        for (size_t j = 0; j < primes.size(); ++j) {
          for (int d = 2; d < 11; ++d) {
            d___mod_prime_i[d][j] += d_pow_n_mod_prime_i[d][i][j];
            d___mod_prime_i[d][j] %= primes[j];
          }
        }
      }
    }
    vi cur_factors(11, -1);
    bool ok = true;
    for (int d = 2; d < 11; ++d) {
      bool found = false;
      for (size_t j = 0; j < primes.size(); ++j) {
        if (d___mod_prime_i[d][j] == 0) {
          found = 1;
          cur_factors[d] = primes[j];
        }
      }
      if (!found) {
        ok = false;
      }
    }
    if (ok) {
      reverse(all(ans));
      if (count(all(res), ans)) {
        continue;
      }
      res.push_back(ans);
      factors.push_back(cur_factors);
    }
  }
  for (size_t i = 0; i < res.size(); ++i) {
    for (int x : res[i]) {
      cout << x;
    }
    cout << " ";
    for (int d = 2; d <= 10; ++d) {
      cout << factors[i][d] << " ";
    }
    cout << "\n";
  }

  return 0;
}
