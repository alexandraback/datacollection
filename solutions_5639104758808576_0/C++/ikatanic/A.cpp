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

char s[1111];

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp) {
    int N;
    scanf("%d", &N);
    scanf("%s", s);
    
    int ans = 0, cnt = 0;
    REP(i, N + 1) {
      int x = s[i] - '0';
      ans += max(0, i - cnt);
      cnt = max(cnt, i);
      cnt += x;
    }

    printf("Case #%d: ", tp);
    fprintf(stderr, "Case #%d: ", tp);
    
    printf("%d\n", ans);
    fprintf(stderr, "%d\n", ans);
  }
  return 0;
}
