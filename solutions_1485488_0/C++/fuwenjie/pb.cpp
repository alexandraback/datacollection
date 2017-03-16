#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
#include <iomanip>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

int n, m, h;
int hc[10000];
int hf[10000];
int early[10000];
bool explored[10000];

inline void path(int s, int e) {
  if (explored[e]) {
    return;
  }
  int c = min(hc[s], hc[e]);
  int f = max(hf[s], hf[e]);
  if (c - f < 50) {
    return;
  }
  int t = early[s];
  int fnow = max(f, h - t);
  int tpass = t;
  if (c - fnow >= 50) {
    if (t == 0) {
      early[e] = 0;
      return;
    }
  } else {
    int fpass = c - 50;
    tpass = h - fpass;
  }
  int tarrive;
  if (h - tpass >= hf[s] + 20) {
    tarrive = tpass + 10;
  } else {
    tarrive = tpass + 100;
  }
  if (early[e] < 0 || early[e] > tarrive) {
    early[e] = tarrive;
  }
}

int solve() {
  int target = n * m - 1;
  mset(explored, 0);
  mset(early, 255);
  early[0] = 0;
  int nm = n * m;
  int lasttime = 0;
  while (1) {
    int k = -1;
    for (int i = 0; i < nm; ++i) {
      if (!explored[i] && early[i] >= 0 && (k < 0 || early[i] < early[k])) {
        k = i;
        if (early[k] == lasttime) {
          break;
        }
      }
    }
    if (k < 0) {
      cerr << "no solution" << endl;
      return -1;
    }
    if (k == target) {
      return early[target];
    }
    lasttime = early[k];
    explored[k] = true;

    //explore(k);
    int x = k % m;
    int y = k / m;
    if (x < m - 1) {
      path(k, k + 1);
    }
    if (y < n - 1) {
      path(k, k + m);
    }
    if (x > 0) {
      path(k, k - 1);
    }
    if (y > 0) {
      path(k, k - m);
    }
  }
}

int main()
{
  int tcase = 0;
  cin >> tcase;
  for (int tind = 1; tind <= tcase; tind++) {
    int i,j;
    //istringstream strin();
    cin >> h >> n >> m;
    for (i = 0; i < n * m; ++i) {
      cin >> hc[i];
    }
    for (i = 0; i < n * m; ++i) {
      cin >> hf[i];
    }

    int ans = solve();
    cout << "Case #" << tind << ": " << ans / 10.0 << endl;
  }
  return 0;
}
