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
  int answer;
  char s[7][7];


  bool check(char X) {
    REP(i, 4) {
      bool good[2] = {true, true};
      REP(j, 4) {
        if (s[i][j] != X && s[i][j] != 'T') good[0] = false;
        if (s[j][i] != X && s[j][i] != 'T') good[1] = false;
      }
      if (good[0] || good[1]) return true;
    }

    bool diag[2] = {true, true};
    REP(i, 4) {
      if (s[i][i] != X && s[i][i] != 'T') diag[0] = false;
      if (s[3 - i][i] != X && s[3 - i][i] != 'T') diag[1] = false;
    }
    return diag[0] || diag[1];
  }

  void solve() {
    if (check('X')) {
      answer = 0;
      return;
    }
    if (check('O')) {
      answer = 1;
      return;
    }

    int count = 0;
    REP(i, 4) {
      REP(j, 4) {
        if (s[i][j] != '.') ++count;
      }
    }

    if (count == 16) {
      answer = 2;
      return;
    } else {
      answer = 3;
      return;
    }
  }

  void read() {
    REP(i, 4) {
      scanf("%s", s[i]);
    }
  }

  void print(int testNumber) {
    printf("Case #%d: ", testNumber);
    switch(answer) {
      case 0:
        printf("X won");
        break;
      case 1:
        printf("O won");
        break;
      case 2:
        printf("Draw");
        break;
      case 3:
        printf("Game has not completed");
        break;
    }
    printf("\n");
  }
};

int main() {
//#undef CENADAR_DEBUG
#ifdef    CENADAR_DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else  // CENADAR_DEBUG
  freopen("~/downloads/.txt", "r", stdin);
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
