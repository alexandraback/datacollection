#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

double a[1010], b[1010];
bool bio[1010];

int main(void) {
  int T;
  scanf("%d", &T);
  for (int tp = 1; tp <= T; ++tp) {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%lf", a+i);
    REP(i, n) scanf("%lf", b+i);

    sort(a, a + n);
    sort(b, b + n);
    
    int war = 0;
    REP(i, n) bio[i] = false;
    REP(i, n) {
      int fg = -1, fl = -1;
      REP(j, n)
        if (!bio[j]) {
          if (fg == -1 && b[j] > a[i]) fg = j;
          if (fl == -1 && b[j] < a[i]) fl = j;
        }
      if (fg != -1) bio[fg] = true; else
        bio[fl] = true, war++;
    }

    int l = 0, r = n-1, dwar = 0;
    REP(i, n)
      if (a[i] > b[l]) dwar++, l++; else
        r--;

    printf("Case #%d: ", tp);
    printf("%d %d\n", dwar, war);
  }
  return 0;
}
