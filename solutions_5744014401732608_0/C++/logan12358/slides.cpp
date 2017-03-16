#include <cstdio>

int main() {
  int t; scanf("%d", &t);
  for(int _i=1; _i<=t; _i++) {
    int b, m; scanf("%d %d", &b, &m); // TODO use long longs
    printf("Case #%d: ", _i);
    if(m<=(1<<(b-2))) {
      printf("POSSIBLE\n");
      for(int i=0; i<b; i++) {
        for(int j=0; j<b; j++) {
          if(i==b-1) {
            printf("0");
          } else if(i<j and j!=b-1) {
            printf("1");
          } else if(j==b-1 and (m==(1<<(b-2)) or m&(1<<(i-1)))) {
            printf("1");
          } else {
            printf("0");
          }
        }
        printf("\n");
      }
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
}
