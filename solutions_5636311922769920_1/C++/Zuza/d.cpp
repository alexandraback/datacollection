#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    printf("Case #%d: ", tc+1); fflush(stdout);
    int K, C, S; scanf("%d %d %d", &K, &C, &S);
    if ((K+C-1) / C > S) {
      printf("IMPOSSIBLE\n");
      continue;
    }

    vector<int> V;
    REP(i, K) V.push_back(i);
    while (V.size()%C != 0) {
      V.push_back(0);
    }

    vector<llint> out;
    REP(a, V.size()/C) {
      llint x = 0;
      REP(b, C) {
        x = x*K + V[a*C+b];
      }
      out.push_back(x);
    }

    int sz = out.size();
    REP(i, sz) printf("%lld%c", out[i]+1, i+1==sz ? '\n' : ' ');
  }

  return 0;
}   
