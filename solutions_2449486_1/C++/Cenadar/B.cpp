#pragma comment (linker, "/STACK:1073741824")
#define _USE_MATH_DEFINES
#include <omp.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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

typedef vector<int> vint;
typedef vector<long long> vLL;
typedef long double dbl;
typedef vector<pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

struct TestCase {
  bool answer;
  vector<vector<int> > a;
  vector<bool> r, c;
  int n, m;

  bool checkRow(int i, int cur) {
    REP(j, m)
      if (c[j] && a[i][j] != cur)
        return false;

    r[i] = false;
    return true;
  }

  bool checkCol(int j, int cur) {
    REP(i, n)
      if (r[i] && a[i][j] != cur)
        return false;

    c[j] = false;
    return true;
  }

  void solve() {
    r.assign(n, true);
    c.assign(m, true);
    int k = n + m;

    FOR(cur, 1, 101) {
      REP(i, n) if (r[i])
        if (checkRow(i, cur))
          --k;

      REP(j, m) if (c[j])
        if (checkCol(j, cur))
          --k;
    }

    assert((r == vector<bool>(n, false)) == (k == 0));
    assert((c == vector<bool>(m, false)) == (k == 0));
    answer = k == 0;
  }

  void read() {
    scanf("%d%d", &n, &m);
    a.assign(n, vector<int>(m));

    REP(i, n) {
      REP(j, m) {
        scanf("%d", &a[i][j]);
      }
    }
  }

  void print(int testNumber) {
    printf("Case #%d: ", testNumber);
    printf(answer ? "YES" : "NO");
    printf("\n");
  }
};

int main() {
//#undef CENADAR_DEBUG
#ifdef    CENADAR_DEBUG
//  freopen("input.txt", "r", stdin);
//  freopen("/home/cenadar/downloads/B-small-attempt0.in", "r", stdin);
  freopen("/home/cenadar/downloads/B-large.in", "r", stdin);
  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else  // CENADAR_DEBUG
  freopen("/home/cenadar/downloads/.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // CENADAR_DEBUG

  const int maxThreads = 2;

  omp_set_dynamic(0);
  omp_set_num_threads(maxThreads);

  int T;
  scanf("%d", &T);
  vector<TestCase> tests(T);
  for(int i = 0; i < T; ++i) tests[i].read();
  #pragma omp parallel for shared(tests)
  for(int i = 0; i < T; ++i) tests[i].solve();
  for(int i = 0; i < T; ++i) tests[i].print(i + 1);

  return 0;
}
