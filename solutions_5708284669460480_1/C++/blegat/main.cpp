#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

#define ABS(x) (((x) < 0) ? (-(x)) : (x))
#define MIN(a,b) (((a) < (b)) ? (a) : (x))
#define MAX(a,b) (((a) > (b)) ? (a) : (x))

int L[100];
int nK[26];

int main (void) {
  int Te;
  scanf("%d", &Te);
  for (int currentcase = 1; currentcase <= Te; ++currentcase) {
    int k, l, s;
    scanf("%d %d %d", &k, &l, &s);
    char c;
    for (int i = 0; i < 26; i++) nK[i] = 0;
    for (int i = 0; i < k; i++) {
      c = getchar();
      while (c < 'A' || c > 'Z') {
        c = getchar();
      }
      nK[c-'A']++;
    }
    for (int i = 0; i < l; i++) {
      while ((c = getchar()) < 'A' || c > 'Z');
      L[i] = c-'A';
    }
    int start;
    for (start = 1; start < l; start++) {
      bool ok = true;
      for (int i = start; i < l; i++) {
        if (L[i] != L[i-start]) {
          ok = false;
          break;
        }
      }
      if (ok) break;
    }
    int Max = 0;
    if (l <= s) {
      Max++;
      Max += (s-l) / start;
    }
    double exp1 = 1;
    bool poss = true;
    for (int i = 0; i < l; i++) {
      if (nK[L[i]] == 0) poss = false;
      exp1 *= ((double)nK[L[i]]) / k;
    }
    exp1 *= (s-l+1);
    double exp = Max - exp1;
    if (!poss) exp = 0;
    printf("Case #%d: %.8f\n", currentcase, exp);
  }
  return 0;
}
