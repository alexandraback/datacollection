#include <bits/stdc++.h>

using namespace std;

template<class T> inline T sqr(const T& a) {
  return a * a;
}

template<class T> inline T middle(const T &a, const T &b) {
  return (a + b) / 2;
}

template<class T> inline int len(const T &c) {
  return static_cast<int>(c.size());
}

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 100;

void HandleCase() {
  int b;
  li m;
  cin >> b >> m;
  li limit = 1ll << (b - 2);
  cerr << "limit " << limit << ", m " << m << endl;
  if (m > limit) {
    puts("IMPOSSIBLE");
    return;
  }
  vector<vector<int>> g(b);
  if (m == limit) {
    g[0].push_back(b - 1);
    --m;
  }
  for (int i = b - 2; i > 0; --i) {
    for (int j = i + 1; j < b; ++j) {
      g[i].push_back(j);
    }
    li add = 1ll << (b - 2 - i);
    if (m & add) {
      g[0].push_back(i);
    }
  }
  puts("POSSIBLE");
  for (int i = 0; i < b; ++i) {
    auto &cur = g[i];
    sort(cur.begin(), cur.end());
    int pos = 0;
    for (int j = 0; j < b; ++j) {
      if (pos < len(cur) && cur[pos] == j) {
        printf("1");
        ++pos;
      } else {
        printf("0");
      }
    }
    puts("");
  }
}

int main() {
  int tests;
  scanf("%d", &tests);
  for (int test = 1; test <= tests; ++test) {
    printf("Case #%d: ", test);
    HandleCase();
  }
  return 0;
}
