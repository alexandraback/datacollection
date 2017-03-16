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

bool pal[2][nmax];
int ans[2][nmax];

struct TestCase {
  int answer;
  LL a, b;

  bool isPal(LL x) {
    string s;
    while(x) {
      s += x % 10 + '0';
      x /= 10;
    }
    return string(s.rbegin(), s.rend()) == s;
  }

  int get(LL a) {
    assert(a <= INF);

    int res = 0;
    for(int i = 1; i*i <= a; ++i) {
      if (isPal(i) && isPal(i*i))
        ++res;
    }
    return res;
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

LL po10[18];
int rev[nmax];

inline bool checkPal(LL x) {
  int len = 0;
  while(x >= po10[len]) ++len;

  return rev[x / po10[(len + 1) >> 1]] == x % po10[len >> 1];
}

void precalc() {
  po10[0] = 1;
  for(int i = 1; i < 18; ++i) po10[i] = po10[i - 1]*10;

  #pragma omp parallel for shared(rev, po10)
  for(int i = 1; i < nmax; ++i) {
  }

  #pragma omp parallel for shared(pal, rev, po10)
  for(int i = 1; i < nmax; ++i) {
  }
}

#define CENADAR_SUBMIT

int main() {
#ifndef CENADAR_SUBMIT
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else
  freopen("/home/cenadar/downloads/C-small-attempt0.in", "r", stdin);
//  freopen("/home/cenadar/downloads/C-large.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  const int maxThreads = 2;

  omp_set_dynamic(0);
  omp_set_num_threads(maxThreads);

  //precalc();

  int T;
  scanf("%d", &T);
  vector<TestCase> tests(T);
  for(int i = 0; i < T; ++i) tests[i].read();
  #pragma omp parallel for shared(tests)
  for(int i = 0; i < T; ++i) tests[i].solve();
  for(int i = 0; i < T; ++i) tests[i].print(i + 1);

  return 0;
}
