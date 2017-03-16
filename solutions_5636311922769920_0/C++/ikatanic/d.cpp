#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

vector<llint> solve(int K, int C, int S) {
  if (C * S < K) return {};
  
  vector<llint> ans;
  int cur = 0;
  while (cur < K) {
    int F = min(C, (K-cur));
    assert(F > 0);

    llint x = 0;
    REP(i, F) x = x * K + (cur++);
    REP(i, C-F) x = x * K;
    ans.push_back(x);
  }
  return ans;
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int K, C, S;
    scanf("%d %d %d", &K, &C, &S);

    auto ans = solve(K, C, S);

    printf("Case #%d: ", tp);
    if (ans.size() == 0) {
      puts("IMPOSSIBLE");
    } else {
      for (llint x: ans) printf("%lld ", x+1);
      printf("\n");
    }
  }
  return 0;
}
