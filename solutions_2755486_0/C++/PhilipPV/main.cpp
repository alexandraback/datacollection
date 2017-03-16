#pragma comment(linker, "/STACK:46777216")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned char byte;
typedef pair<int, int> pii;
#define forn(i,n) for (ll i = 0; i < ll(n); ++i)
#define mp make_pair

int tree[10000000];
int get(int i, int j) {
  int m = 1000000000;
  for (int _ = i; _ < j; ++_) {
    m = min(m, tree[_]);
  }
  return m;
}

void add(int i, int j, int v) {
  for (int _ = i; _ < j; ++_) {
    tree[_] = max(tree[_], v);
  }
}

/*
const int maxh = 27;
const unsigned int maxn = (1 << maxh);

unsigned int tree[2 * maxn];

void update(int i) {
  i += maxn;
  for (int h = maxh; h; h--) {
    int j = i >> h;
    int v = tree[j] - min(tree[j + j], tree[j + j + 1]);
    tree[j + j] += v;
    tree[j + j + 1] += v;
  }
}

int get(int i, int j) {
  update(i - 1); update(j);
  int result = 0;
  for (i += maxn - 1, j += maxn; i + 1 != j; i >>= 1, j >>= 1) {
    if (!(i & 1))
      result = min(result, tree[i + 1]);
    if (j & 1)
      result = min(result, tree[j - 1]);
  }

  return result;
}

inline void update_up(int i) {
  for (i >>= 1; i; i >>= 1)
    tree[i] = min(tree[i + i], tree[i + i + 1]);
}

void add(int i, int j, int v) {
  update(i - 1); update(j);
  for (i += maxn - 1, j += maxn; i + 1 != j; v <<= 1) {
    if (!(i & 1))
      tree[i + 1] = max(tree[i + 1], v);
    if (j & 1)
      tree[j - 1] = max(tree[j - 1], v);

    i >>= 1, j >>= 1;
    tree[i] = min(tree[i + i], tree[i + i + 1]);
    tree[j] = min(tree[j + j], tree[j + j + 1]);
  }
  update_up(i);
  update_up(j);
}
*/

struct S {
  int d;

  int n;
  int w, e;
  int s;
  int delta_d;
  int delta_p;
  int delta_s;

  bool operator<(const S& t) const {
    return d > t.d;
  }
};

priority_queue<S> q;

int main() {
  int T;
  cin >> T;
  forn (_, T) {
    cout << "Case #" << (_ + 1) << ": ";
    ll result = 0;

    memset(tree, 0, sizeof(tree));
    int N; cin >> N;
    forn (__, N) {
      S t;
      cin >> t.d >> t.n >> t.w >> t.e >> t.s >> t.delta_d >> t.delta_p >> t.delta_s;
      t.w += 1000000;
      t.e += 1000000;
      //t.w += 1000000 + 100000 * 1000 + 123;
      //t.e += 1000000 + 100000 * 1000 + 123;
      q.push(t);
    }

    std::vector<S> p;
    while (!q.empty()) {
      S t = q.top();
      q.pop();

      int w = t.w;
      int e = t.e;

      bool succ = false;
      if (t.s > 0) {
        int h = get(w, e);
        if (t.s > h) {
          succ = true;
        }
      }

      if (succ) {
        p.push_back(t);
      }
      if (!q.empty() && q.top().d == t.d) {
      } else {
        for (int j = 0; j < p.size(); ++j) {
          add(p[j].w, p[j].e, p[j].s);
        }
        p.clear();
      }

      if (succ) t.s += t.delta_s;
      else t.s -= t.delta_s;
      --t.n;
      t.d += t.delta_d;
      t.e += t.delta_p;
      t.w += t.delta_p;
      
      if (t.n > 0) {
        q.push(t);
      }

      result += int(succ);
    }

    cout << result << endl;
  }


  return 0;
}