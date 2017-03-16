#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

#define ABS(x) (((x) < 0) ? (-(x)) : (x))
#define MIN(a,b) (((a) < (b)) ? (a) : (x))
#define MAX(a,b) (((a) > (b)) ? (a) : (x))

char K[7], L[7], S[7];

int main (void) {
  int Te;
  scanf("%d", &Te);
  for (int currentcase = 1; currentcase <= Te; ++currentcase) {
    int k, l, s;
    scanf("%d %d %d", &k, &l, &s);
    char c;
    for (int i = 0; i < k; i++) {
      c = getchar();
      while (c < 'A' || c > 'Z') {
        c = getchar();
      }
      K[i] = c;
    }
    for (int i = 0; i < l; i++) {
      while ((c = getchar()) < 'A' || c > 'Z');
      L[i] = c;
    }
    int max = 1;
    for (int i = 0; i < s; i++) {
      max *= k;
    }
    int Max = 0, sum = 0;
    for (int i = 0; i < max; i++) {
      int cpy = i;
      for (int j = 0; j < s; j++) {
        S[j] = K[cpy % k];
        cpy /= k;
      }
      int count = 0;
      for (int j = 0; j+l <= s; j++) {
        bool ok = true;
        for (int J = j; J < j + l; J++) {
          if (L[J-j] != S[J]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          count++;
        }
      }
      if (count > Max) {
        Max = count;
      }
      sum += count;
    }
    double exp = Max - (((double) sum) / ((double) max));
    printf("Case #%d: %.8f\n", currentcase, exp);
  }
  return 0;
}
