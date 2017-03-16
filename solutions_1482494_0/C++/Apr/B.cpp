#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>

using namespace std;

int T;
int N;
struct s {
  int a, b;
  bool operator<(const struct s &s) const {
    return b > s.b || (b == s.b && a > s.a);
  }
};
struct s ss[1000];

int main()
{
  scanf("%d\n", &T);
  for(int t = 1; t <= T; t++) {
    scanf("%d", &N);
    int done[1000];
    for (int i = 0; i < N; i++) {
      done[i] = 0;
      scanf("%d%d", &ss[i].a, &ss[i].b);
      //printf("%d %d\n", ss[i].a, ss[i].b);
    }

    sort(ss, ss+N);
    int level = 0;
    bool valid = false;
    int i;
    for(i = 0; i < 2*N; i++) {
      int old = level;

      for (int j = 0; j < N; j++) {
       // printf("2: %d >= %d? done: %d\n", level, s2[j], done[j]);
        if(level >= ss[j].b && done[j] < 2) {
          level += 2 - done[j];
          done[j] = 2;
          j = N;
        }
      }
      if(old == level) {
        for (int j = 0; j < N; j++) {
          //printf("1: %d >= %d? done: %d\n", level, s1[j], done[j]);
          if(level >= ss[j].a && done[j] < 1) {
            level += 1;
            done[j] = 1;
            j = N;
          }
        }
        if( old == level ) {
          break;
        }
      }
    }

    valid = true;
    for (int j = 0; j < N; j++) {
      valid = (valid && (done[j] == 2));
    }
    printf("Case #%d: ", t);
    if(valid) printf("%d\n", i);
    else printf("Too Bad\n");
  }
  return 0;
}
