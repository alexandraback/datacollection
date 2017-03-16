#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXD 1100

int d, p[MAXD];

int main () {
  int teste;
  scanf ("%d", &teste);
  for (int t = 0; t < teste; t++) {
    int ret = MAXD*MAXD;
    scanf ("%d", &d);
    int maxp = 0;
    for (int i = 0; i < d; i++) {
      scanf ("%d", &p[i]);
      maxp = max (maxp, p[i]);
    }
    for (int i = 1; i <= maxp; i++) {
      int cand = 0;
      for (int j = 0; j < d; j++) {
	int now = (int)(ceil (((double)p[j])/i)) - 1;
	now = max (now, 0);
	//printf ("i = %d, p = %d, now = %d\n", i, p[j], now);
	cand += now;
      }
      cand += i;
      //printf ("cand = %d\n", cand);
      ret = min (ret, cand);
    }
    printf ("Case #%d: %d\n", t + 1, ret);
  }
  return 0;
}
