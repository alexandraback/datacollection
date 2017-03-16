#include <cstdio>

int main() {
  long long t; scanf("%lld", &t);
  for(long long _i=1; _i<=t; _i++) {
    long long b, m; scanf("%lld %lld", &b, &m); // TODO use long longs
    printf("Case #%lld: ", _i);
    if(m<=(1<<(b-2))) {
      printf("POSSIBLE\n");
      for(long long i=0; i<b; i++) {
        for(long long j=0; j<b; j++) {
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
