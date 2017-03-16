#include <stdio.h>

long long int menor(long long int a, long long int b) {
  if ( a < b) return a;
  return b;
}

int main() {
  int n;
  long long int r, t;
  scanf(" %d", &n);
  for(int c = 1; c<=n; c++) {
    scanf(" %lld %lld", &r, &t);
    
    long long int a = 0;
    long long int b = menor(1000000000, t/r);
    long long int val, m;
    while(a != b) {
      m = (a + b + 1) / 2;
      val = 2*m*m - m + 2*r*m;
      if(val > t) {
        b = m - 1;
      } else {
        a = m;
      }
    }
    printf("Case #%d: %lld\n", c, a);
  } 
}
