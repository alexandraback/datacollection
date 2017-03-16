#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    int n, s, p, points;
    scanf("%d %d %d", &n, &s, &p);
    int result = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &points);

      int d = points / 3;
      int surprise = 0, nosurprise = 0;
      if (points % 3 == 0) {
        nosurprise = d;
        if (d > 0 && d < 10)
          surprise = d + 1;
        else
          surprise = nosurprise;
      } else if (points % 3 == 1) {
        nosurprise = d + 1;
        if (d > 0 && d < 10)
          surprise = d + 1;
        else
          surprise = nosurprise;
      } else { // % 3 == 2
        nosurprise = d + 1;
        if (d < 9)
          surprise = d + 2;
        else
          surprise = nosurprise;
      }
      if (nosurprise > 10) nosurprise = 10;
      if (surprise > 10) surprise = 10;
      if (nosurprise >= p) {
        result++;
      } else if (surprise >= p && s > 0) {
        result++;
        s--;
      }
    }
    printf("Case #%d: %d\n", t, result);
  }

  return 0;
}
