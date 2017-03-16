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

const int nmax = 20;
const int kmax = 210;

int k[1 << nmax];

struct TestCase {
  vector<int> answer;
  int n, m;
  vector<int> dp;
  vector<bool> opt;
  vector<int> begin;
  vector<int> need;
  vector<int> v[nmax + 1];
  vector<vector<int> > add;

  void makeBits() {
    for(int i = 1 << n; i--; ) v[k[i]].PB(i);
  }

  void solve() {
    makeBits();
    dp.assign(1 << n, -1);

    int start = (1 << n) - 1;
    for(int I = n; I > 0; --I) {
      FE(J, v[I]) {
        int mask = v[I][J];
        if (dp[mask] == -1 && mask != start) continue;
        REP(i, n) if (mask & (1 << i)) {
          int nmask = mask ^ (1 << i);

          vector<int> have = begin;
          REP(j, n) {
            if ((1 << j) & nmask) {
              --have[need[j]];
              FE(idx, add[j]) ++have[add[j][idx]];
            }
          }
          --have[need[i]];
          bool good = true;
          FE(j, have) {
            if (have[j] < 0) good = false;
          }

          if (good)
            if (dp[nmask] == -1 || dp[nmask] > i) dp[nmask] = i;
        }
      }
    }

    int end = (1 << n) - 1;
    int cur = 0;
    if (dp[cur] != -1) {
      while(cur != end) {
        answer.PB(dp[cur] + 1);
        cur ^= 1 << dp[cur];
      }
    }

    //dp.clear();
    /*vector<int> tmp;
    dp.swap(tmp);
    REP(i, 21) {
      vector<int> tmp2;
      v[i].swap(tmp2);
    }/**/
  }

  void read() {
    scanf("%d%d", &m, &n);
    begin.assign(kmax, 0);
    REP(i, m) {
      int x;
      scanf("%d", &x);
      ++begin[--x];
    }
    REP(i, n) {
      int x, kAdd;
      scanf("%d%d", &x, &kAdd);
      need.PB(--x);

      vector<int> tmp;
      REP(j, kAdd) {
        int val;
        scanf("%d", &val);
        tmp.PB(--val);
      }
      add.PB(tmp);
    }
  }

  void print(int testNumber) {
    printf("Case #%d: ", testNumber);
    if (answer.empty()) {
      printf("IMPOSSIBLE\n");
    } else {
      for(int i = 0; i < answer.size(); ++i) printf("%d%c", answer[i], i + 1 == answer.size() ? '\n' : ' ');
    }
  }
};

void precalc() {
  k[0] = 0;
  for(int i = 1; i < (1 << nmax); ++i) {
    k[i] = k[i >> 1] + (i & 1);
  }
}


#define CENADAR_SUBMIT

int main() {
#ifndef CENADAR_SUBMIT
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else
  freopen("/home/cenadar/downloads/D-small-attempt0.in", "r", stdin);
//  freopen("/home/cenadar/downloads/D-large.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  const int maxThreads = 2;

  omp_set_dynamic(0);
  omp_set_num_threads(maxThreads);

  precalc();

  int T;
  scanf("%d", &T);
  vector<TestCase> tests(T);
  for(int i = 0; i < T; ++i) tests[i].read();
  //#pragma omp parallel for shared(tests)
  for(int i = 0; i < T; ++i) {
    fprintf(stderr, "%d started\n", i);
    tests[i].solve();
  }
  for(int i = 0; i < T; ++i) tests[i].print(i + 1);

  return 0;
}
