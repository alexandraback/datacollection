#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

#define N 1100
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

struct Event {
  int id;
  int sc, inc;
} sm[N], lg[N], ev[2*N];
    int n;

int comp(const void *a, const void *b)
{
  return ((Event *)a)->sc - ((Event*)b)->sc;
}

int main()
{
  int t;
  scanf("%d", &t);
  for(int idx = 1; idx <= t; idx++) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &sm[i].sc, &lg[i].sc);
      sm[i].id = lg[i].id = i;
    }
    int res = 2*n+1;
    for(int i = 0; i < (1<<n); i++) {
      int m = 0;
      for(int j = 0; j < n; j++) {
        if(i & (1<<j)) {
          ev[m] = sm[j];
          ev[m++].inc = 1;
          ev[m] = lg[j];
          ev[m++].inc = 1;
        } else {
          ev[m] = lg[j];
          ev[m++].inc = 2;
        }
      }
      qsort(ev, m, sizeof(Event), comp);
      int sc = 0;
      bool valid = true;
      for(int j = 0; j < m; j++)
        if(sc < ev[j].sc) {
          valid = false;
          break;
        } else {
          sc += ev[j].inc;
        }
      if(valid && m < res)
        res = m;
    }

    if(res > 2*n)
      printf("Case #%d: Too Bad\n", idx);
    else
      printf("Case #%d: %d\n", idx, res);
  }
  return 0;
}


