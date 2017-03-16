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
    printf("Case #%d: ", tc+1);
    llint n; scanf("%lld", &n);
    if (n == 0) { printf("INSOMNIA\n"); continue; }

    int bio[10] = { 0 };
    llint last = n;
    for (; ; last += n) {
      llint tmp = last; for (; tmp; tmp /= 10) bio[tmp%10] = true;
      int s = 0; REP(i, 10) s += bio[i];
      if (s == 10) break;
    }

    printf("%lld\n", last);
    fflush(stdout);
  }

  return 0;
}   
