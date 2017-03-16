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

size_t solve_hard(vi bff) {
  size_t n = bff.size();
  vector<pii> couples;
  size_t max_cycle_len = 0;
  vector<bool> in_cycle(n);
  for (size_t i = 0; i < n; ++i) {
    if (in_cycle[i]) {
      continue;
    }
    vector<bool> used(n, false);
    size_t x = i;
    size_t len = 0;
    while (!used[x]) {
      used[x] = true;
      x = bff[x];
      ++len;
    }
    if (x == i) {
      max_cycle_len = max(len, max_cycle_len);
      for (size_t k = 0; k < len; ++k) {
        in_cycle[x] = true;
        x = bff[x];
      }
      if (len == 2) {
        couples.push_back(pii(i, bff[i]));
        assert(bff[bff[i]] == i);
      }
    }
  }
  assert(0 < max_cycle_len);
  assert(max_cycle_len <= n);

  size_t total_longest_chains_sum = 0;
  vii t_al(n);
  for (size_t i = 0; i < n; ++i) {
    t_al[bff[i]].push_back((int)i);
  }
  for (auto couple : couples) {
    for (size_t k = 0; k < 2; ++k) {
      size_t origin = k == 0 ? couple.first : couple.second;
      size_t another = k == 1 ? couple.first : couple.second;
      vector<bool> used(n, false);
      queue<size_t> Q;
      vector<int> dist(n, -1);
      dist[origin] = 0;
      used[origin] = 1;
      used[another] = 1;
      Q.push(origin);
      while (!Q.empty()) {
        size_t v = Q.front();
        Q.pop();
        for (size_t v2 : t_al[v]) {
          if (used[v2]) {
            continue;
          }
          used[v2] = true;
          dist[v2] = dist[v] + 1;
          Q.push(v2);
        }
      }
      int max_dist = 0;
      for (size_t i = 0; i < n; ++i) {
        max_dist = max(max_dist, dist[i]);
      }
      total_longest_chains_sum += max_dist;
    }
    total_longest_chains_sum += 2;
  }
  return max(max_cycle_len, total_longest_chains_sum);
}

size_t solve_easy(vi bbf) {
  size_t n = bbf.size();
  vi perm;
  for (size_t i = 0; i < n; ++i) {
    perm.push_back(static_cast<int>(i));
  }
  size_t ans = 0;
  do {
    for (size_t len = 1; len <= n; ++len) {
      bool ok = true;
      for (size_t i = 0; i < len; ++i) {
        size_t a = (i + len - 1) % len;
        size_t b = (i + 1) % len;
        ok = ok && (bbf[perm[i]] == perm[a] || bbf[perm[i]] == perm[b]);
      }
      if (ok) {
        ans = max(ans, len);
      }
    }
  } while (next_permutation(all(perm)));
  return ans;
}

void solve_test() {
  int n;
  cin >> n;
  vi bbf(n);
  for (int i = 0; i < n; ++i) {
    cin >> bbf[i];
    --bbf[i];
  }
  cout << solve_hard(bbf);
  // assert(solve_easy(bbf) == solve_hard(bbf));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  size_t tests;
  cin >> tests;
  for (size_t test_id = 0; test_id < tests; ++test_id) {
    cout << "Case #" << test_id + 1 << ": ";
    solve_test();
    cout << "\n";

    double passed = double(clock()) / CLOCKS_PER_SEC;
    cerr << (test_id + 1) << "/" << tests << ". "
         << "Passed: " << passed << "\t estimated: "
         << passed / static_cast<double>(test_id + 1) *
                static_cast<double>(tests)
         << "\n";
  }

  return 0;
}
