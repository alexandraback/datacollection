#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <iostream>
#include <cstring>
#include <cmath>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

using namespace std;

template<class T> inline void umax(T &a,T b){if(a < b) a = b;}
template<class T> inline void umin(T &a,T b){if(a > b) a = b;}
template<class T> inline T abs(T a){return a > 0 ? a : -a;}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

struct data{
  ll f, va, vb;
};

const int N = 22;

ll pw10[N];
data f[N][2];

inline data prepend(data D, int rot, int i, int da, int db) {
  D.f += pw10[i] * (rot? db - da : da - db);
  D.va += pw10[i] * da;
  D.vb += pw10[i] * db;
  return D;
}

void update(data &D, data other) {
  if (D.f < other.f)
    return;
  if (D.f != other.f) {
    D = other;
    return;
  }
  
  if (D.va < other.va)
    return;
  if (D.va != other.va) {
    D = other;
    return;
  }

  if (D.vb > other.vb) {
    D = other;
  }
}

void out(ll x, int n) {
  string res;
  while (x > 0) {
    res += char(x % 10 + '0');
    x /= 10;
  }
  while (res.size() < n)
    res += "0";
  reverse(all(res));
  printf("%s", res.c_str());
}

void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  assert(b.size() == n);

  data ans = {longinf, longinf, longinf};
  for (int rot = 0; rot < 2; rot++) {
    f[n][0] = {0, 0, 0};
    f[n][1] = {0, 0, 0};
    for (int i = n - 1; i >= 0; i--) {
      for (int eq = 0; eq < 2; eq++) {
        f[i][eq] = {longinf, longinf, longinf};
        for (int da = 0; da < 10; da++) {
          if (a[i] != '?' && a[i] - '0' != da)
            continue;
          for (int db = 0; db < 10; db++) {
            if (b[i] != '?' && b[i] - '0' != db)
              continue;
            if (eq) {
              if (rot == 0) {
                if (da < db)
                  continue;
              } else {
                if (da > db)
                  continue;
              }
            }
            int neq = eq && (da == db);
            update(f[i][eq], prepend(f[i + 1][neq], rot, n - i - 1, da, db));
          }
        }
      }
    }
    update(ans, f[0][1]);
  }
  eprintf("%lld\n", ans.f);
  out(ans.va, n);
  printf(" "); 
  out(ans.vb, n);
  printf("\n");
}

int main() {
  pw10[0] = 1;
  for (int i = 1; i < N; i++) {
    pw10[i] = pw10[i - 1] * 10ll;
  }

  int t = read();
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
    eprintf("Done with %d..\n", i);
    fflush(stdout);
  }
  return 0; 
}