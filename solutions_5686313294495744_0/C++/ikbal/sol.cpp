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

const int N = 20;

string a[N][2];
int f[N][1 << N];

bool test(int msk, int x) {
  return (msk >> x) & 1;
}
/*
int stupid(int n) {
  vi p(n, 0);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  do {
    for (int i = 0; i < n; i++) {
      int f0 = 0, f1 = 0;
      for (int j = 0; j < i; j++) {
        if ()
      }
    }
  } while(next_permutation(p, p + n));
}
*/

void solve() {
  int n = read();
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  memset(f, -1, sizeof f);
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) if(f[i][mask] != -1) {
      for (int x = 0; x < n; x++) {
        if (!test(mask, x)) {
          int f0 = 0, f1 = 0;
          for (int y = 0; y < n; y++) {
            if (test(mask, y)) {
              if (a[y][0] == a[x][0])
                f0 = 1;
              if (a[y][1] == a[x][1])
                f1 = 1;
            }
          }
          umax(f[i + 1][mask | (1 << x)], f[i][mask] + (f0 * f1));
        }
      }
    }
  }
  printf("%d\n", f[n][(1 << n) - 1]);
}

int main() {

  int t = read();
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
    eprintf("Done with %d..\n", i);
    fflush(stdout);
  }
  return 0; 
}