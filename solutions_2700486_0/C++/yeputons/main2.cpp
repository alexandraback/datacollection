#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

double fac(int x) {
  double res = 1;
  for (int i = 1; i <= x; i++)
    res *= i;
  return res;
}

double getSum(int n, int maxk) {
  vector<double> c(maxk + 1, 0);
  c[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int a = maxk; a >= 0; a--) {
      c[a] /= 2;
      if (a + 1 <= maxk)
        c[a + 1] += c[a];
    }
  }
  double sum = 0;
  for (int i = 0; i <= maxk; i++)
    sum += c[i];
  eprintf("getSum(%d, %d)=%.18lf\n",n,maxk,sum);
  return sum;
}

void solve() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  int lay = abs(x) + y;
  assert(lay % 2 == 0);
  lay /= 2;

  int curcnt = 1;
  int maxy = 0;
  for (int i = 0; i < lay; i++) {
    n -= curcnt;
    if (n < 0) {
      printf("0\n");
      return;
    }
    curcnt += 4;
    maxy += 2;
  }
  if (n >= curcnt) {
    printf("1\n");
    return;
  }
  if (x == 0) {
    printf("0\n");
    return;
  }
  assert(maxy > 0);
  if (y + 1 > n || y >= maxy) {
    printf("0\n");            	
    return;
  }

  int maxCnt = min(n, maxy);
  vector<vector<long double> > dyn(maxCnt + 1, vector<long double>(maxCnt + 1, 0));
  dyn[0][0] = 1;
  long double sum = 0;
  for (int a = 0; a <= maxCnt; a++)
  for (int b = 0; b <= maxCnt && a + b <= n; b++) {
    long double v = dyn[a][b];
    if (a + b == n) {
      if (b > y)
        sum += v;
      continue;
    }
    if (a < maxCnt && b < maxCnt) v /= 2;
    if (a < maxCnt) dyn[a + 1][b] += v;
    if (b < maxCnt) dyn[a][b + 1] += v;
  }
  printf("%.18lf\n", (double)sum);
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Catched exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
