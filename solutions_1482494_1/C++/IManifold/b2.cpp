#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Level {
  int i, a, b;
};

const int INF = 1000000000;
const int MAX = 1010;
Level levels[MAX];
bool solved[MAX][2];
int n, tt;

Level sorta[MAX], sortb[MAX];

int compa(const void *p, const void *q) {
  Level *l1 = (Level *)p;
  Level *l2 = (Level *)q;
  
  if (l1->a != l2->a) {
    return l1->a - l2->a;
  }
  return l2->b - l1->b;
}

int compb(const void *p, const void *q) {
  Level *l1 = (Level *)p;
  Level *l2 = (Level *)q;
  
  if (l1->b != l2->b) {
    return l1->b - l2->b;
  }
  return l1->a - l2->a;
}

int solve() {
  for (int i = 0; i < n; i++) {
    sorta[i] = sortb[i] = levels[i];
    solved[i][0] = solved[i][1] = false;
  }
  qsort(sorta, n, sizeof(Level), compa);
  qsort(sortb, n, sizeof(Level), compb);
  //for (int i = 0; i < n; i++) printf("%d ", sorta[i].i+1); printf("\n");
  //for (int i = 0; i < n; i++) printf("%d ", sortb[i].i+1); printf("\n");
  
  int indexa = 0, indexb = 0;
  int plays = 0, stars = 0;
  while (indexb < n) {
    if (sortb[indexb].b <= stars) {
      if (!solved[sortb[indexb].i][0]) {
        solved[sortb[indexb].i][0] = true;
        stars++;
      }
      solved[sortb[indexb].i][1] = true;
      stars++;
      indexb++;
/*    } else if (sorta[indexa].a <= stars) {
      if (!solved[sorta[indexa].i][0]) {
        solved[sorta[indexa].i][0] = true;
        stars++;
      }
      indexa++;
    } else {
      plays = INF;
      break;
    }*/
    } else {
      // find a that I can do that b is the highest
      int maxb = -1, maxi = -1;
      for (int i = 0; i < n; i++) {
        if (levels[i].a <= stars && !solved[i][0]) {
          if (levels[i].b > maxb) {
            maxb = levels[i].b;
            maxi = i;
          }
        }
      }
      if (maxi < 0) {
        plays = INF;
        break;
      }
      solved[maxi][0] = true;
      stars++;
    }
    plays++;
  }
  
  return plays;
}

int main () {
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &levels[i].a, &levels[i].b);
      levels[i].i = i;
    }
    printf("Case #%d: ", t);
    int sol = solve();
    if (sol >= INF) printf("Too Bad\n");
    else printf("%d\n", sol);
  }

  return 0;
}
