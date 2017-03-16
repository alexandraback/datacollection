#include <stdio.h>
#include <math.h>



int main() {

  int i = 1;
  unsigned long long T;
  scanf("%llu", &T);
  while (T-- > 0) {
    unsigned long long num = 0;
    long long r, t, R;
    scanf("%lld %lld", &r, &t);
    r = r + r+1;
 
    
    while (t>=0) {
      t -= r;
      r+=4;
      num++;
    }
    num--;
    

        printf("Case #%d: %llu\n",i, num );
    i++;
  }


}
