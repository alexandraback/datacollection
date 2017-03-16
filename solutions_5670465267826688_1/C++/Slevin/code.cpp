#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <memory.h>
using namespace std;

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

int ri() {
  static int res;
  scanf("%d", &res);
  return res;
}

template <typename T>
int numbits(T n) {
  return n ? 1 + numbits(n & (n - 1)) : 0;
}

class timer {
public:
  timer() : t_(clock()) {}
  void restart() { t_ = clock(); }
  float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
  clock_t t_;
};

void run();

int main() {
#ifdef LOCAL_HOST
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  timer t;
#endif
  run();
#ifdef LOCAL_HOST
  //printf("\nElapsed time: %.9f\n", t.elapsed());
#endif
  return 0;
}

struct Q {
  int a;
  int b;
  int c;
  int d;

  Q(int aa, int bb, int cc, int dd) {
    a = aa;
    b = bb;
    c = cc;
    d = dd;
  }

  static Q makeQ(char ch) {
    if (ch == 'i') {
      return Q(0, 1, 0, 0);
    }
    if (ch == 'j') {
      return Q(0, 0, 1, 0);
    }
    if (ch == 'k') {
      return Q(0, 0, 0, 1);
    }
    return Q(1, 0, 0, 0);
  }

  Q mult(const Q& that) const {
    int ra = a * that.a - b * that.b - c * that.c - d * that.d;
    int rb = a * that.b + b * that.a + c * that.d - d * that.c;
    int rc = a * that.c - b * that.d + c * that.a + d * that.b;
    int rd = a * that.d + b * that.c - c * that.b + d * that.a;
    return Q(ra, rb, rc, rd);
  }

  Q pow(ll p) const {
    if (!p) {
      return Q(1, 0, 0, 0);
    }
    if (p == 1) {
      return *this;
    }
    Q tmp = this->pow(p >> 1);
    tmp = tmp.mult(tmp);
    if (p & 1) {
      tmp = tmp.mult(*this);
    }
    return tmp;
  }

  void print() const {
    cout << a << " " << b << " " << c << " " << d << endl;
  }
};

void run() {
  int nn; cin >> nn;
  for (int cs = 0; cs < nn; ++cs) {
    ll l, x; cin >> l >> x;
    string s; cin >> s;

    Q q(1, 0, 0, 0);
    for (int i = 0; i < s.size(); ++i) {
      Q t = Q::makeQ(s[i]);
      q = q.mult(t);
    }
    q = q.pow(x);

    if (q.a != -1 || q.b || q.c || q.d) {
      printf("Case #%d: NO\n", cs + 1);
      continue;
    }

    ll dl = 0;
    q = Q(1, 0, 0, 0);
    for (int rr = 0; rr < 10 && !dl; ++rr) {
      for (int i = 0; i < s.size() && !dl; ++i) {
        Q t = Q::makeQ(s[i]);
        q = q.mult(t);
        if (!q.a && q.b == 1 && !q.c && !q.d) {
          dl = rr * s.size() + i + 1;
        }
      }
    }

    ll dr = 0;
    q = Q(1, 0, 0, 0);
    for (int rr = 0; rr < 10 && !dr; ++rr) {
      for (int i = 0; i < s.size() && !dr; ++i) {
        Q t = Q::makeQ(s[s.size() - 1 - i]);
        q = t.mult(q);
        if (!q.a && !q.b && !q.c && q.d == 1) {
          dr = rr * s.size() + i + 1;
        }
      }
    }

    if (!dl || !dr || (dl + dr >= l * x)) {
      printf("Case #%d: NO\n", cs + 1);
      continue;
    }

    printf("Case #%d: YES\n", cs + 1);
  }
}
