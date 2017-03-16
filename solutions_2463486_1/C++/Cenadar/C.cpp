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

const int nmax = 10000100;

bool pal[nmax];
int ans[nmax];

struct TestCase {
  int answer;
  LL a, b;

  int get(LL a) {
    LL l = 0, r = INF;
    while(l + 1 < r) {
      LL mid = (l + r) >> 1;
      if (mid*mid <= a) {
        l = mid;
      } else {
        r = mid;
      }
    }

    return ans[l];
  }

  void solve() {
    answer = get(b) - get(a - 1);
  }

  void read() {
    cin >> a >> b;
  }

  void print(int testNumber) {
    printf("Case #%d: ", testNumber);
    printf("%d", answer);
    printf("\n");
  }
};

bool isPal(LL x) {
  string s;
  while(x) {
    s += x % 10 + '0';
    x /= 10;
  }
  return string(s.rbegin(), s.rend()) == s;
}

void precalc() {
  #pragma omp parallel for shared(pal)
  for(int i = 1; i < nmax; ++i) {
    pal[i] = isPal(i) && isPal(LL(i)*i);
  }

  ans[0] = 0;
  for(int i = 1; i < nmax; ++i) {
    ans[i] = ans[i - 1] + pal[i];
  }
}

/*void experiment() {
  int k = 0;
  for(int i = 1; i < 30000000; ++i) {
    if (isPal(i) && isPal(LL(i)*i)) {
      ++k;
      fprintf(stderr, "%10d %4d\n", i, k);
    }
  }
}*/

#define CENADAR_SUBMIT

int main() {
#ifndef CENADAR_SUBMIT
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else
//  freopen("/home/cenadar/downloads/C-small-attempt0.in", "r", stdin);
  freopen("/home/cenadar/downloads/C-large-1.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  const int maxThreads = 2;

  omp_set_dynamic(0);
  omp_set_num_threads(maxThreads);

  precalc();
  //experiment();

  int T;
  scanf("%d", &T);
  vector<TestCase> tests(T);
  for(int i = 0; i < T; ++i) tests[i].read();
  #pragma omp parallel for shared(tests)
  for(int i = 0; i < T; ++i) tests[i].solve();
  for(int i = 0; i < T; ++i) tests[i].print(i + 1);

  return 0;
}
