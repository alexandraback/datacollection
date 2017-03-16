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

const int MAX = 22;

bool solve(int X, int R, int C) {
  if (R > C) swap(R, C);
  if (X > 6) return true;
  if (X > R && X > C) return true;
  if (R*C % X) return true;
  if (2*R+1 <= X) return true;

  if (2*R == X) {
    REP(i, R) {
      int rem = (R-1)*i;
      bool ok = false;
      for (int j = 0; j+R+1 <= C; ++j) {
        if (rem%X == 0) ok = true;
        rem += R;
      }
      if (!ok) return true;
    }
  }

  return false;
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp) {
    int x, r, c;
    scanf("%d %d %d", &x, &r, &c);

    printf("Case #%d: ", tp);
    fprintf(stderr, "Case #%d: ", tp);
    
    string ans = solve(x, r, c) ? "RICHARD" : "GABRIEL";
    printf("%s\n", ans.c_str());
    fprintf(stderr, "%s\n", ans.c_str());
    
  }
  return 0;
}
