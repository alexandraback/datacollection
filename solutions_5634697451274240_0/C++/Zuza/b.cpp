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
    
    static char S[123];
    scanf("%s", S); int len = strlen(S);
    S[len++] = '+';

    int ans = 0;
    for (int i = 0; i < len-1; ++i) {
      if (S[i] != S[i+1]) {
        ++ans;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}   
