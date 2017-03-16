#pragma comment (linker, "/STACK:1073741824")
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>

using namespace std;

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second
#define GET_RUNTIME_ERROR *(int*)(NULL) = 1

typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

int solve(vint d, vint s) {
  assert(d.size() == s.size());
  assert(d.size() <= 2);

  if (d.size() == 1) return 0;

  double t1 = (360.0 - d[0])/360.0*s[0];
  double T1 = s[0];
  double t2 = (360.0 - d[1])/360.0*s[1];
  double T2 = s[1];

  double mx = max(t1, t2);
  double mn = min(t1 + T1, t2 + T2);
  if (mx + 1e-9 < mn) return 0;
  return 1;
}

int solve(vint d, vint h, vint m) {
  vint dd, s;

  FE(i, d) {
    REP(j, h[i]) {
      dd.PB(d[i]);
      s.PB(m[i] + j);
    }
  }

  return solve(dd, s);
}

int main() {
#ifdef    CENADAR_DEBUG
  freopen("input.txt", "r", stdin);
  freopen("/home/maksym/Downloads/C-small-1-attempt1.in", "r", stdin);
  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else  // CENADAR_DEBUG
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif // CENADAR_DEBUG

  int T;
  cin >> T;
  REP(test, T) {
    LL n;
    cin >> n;
    vint d(n), h(n), m(n);
    REP(i, n) {
      cin >> d[i] >> h[i] >> m[i];
    }

    int ans = solve(d, h, m);
    printf("Case #%d: %d\n", test + 1, ans);
  }

  return 0;
}
