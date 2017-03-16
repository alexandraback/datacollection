// Just in case, to avoid any stupid mistake, use long long and sprintf
// Programming while holding you 6 month baby is not easy! :)

#include <stdio.h>
#include <string.h>

#define MAX_ITER 100

int main() {
  int cases, c, j, left;
  long long n, i;
  char v[10], buf[128];
  
  scanf("%d", &cases);
  for (c=1; c<=cases; c++) {
    scanf("%lld", &n);
    memset(v, 0, sizeof(v));
    left = 10;
    for (i=1; i<=MAX_ITER; i++) {
      sprintf(buf, "%lld", i*n);
      for (j=0; buf[j]; j++)
	if (!v[buf[j]-'0']) {
	  v[buf[j]-'0'] = 1;
	  left--;
	}
      if (left==0) break;
    }
    if (i>MAX_ITER) printf("Case #%d: INSOMNIA\n", c);
    else            printf("Case #%d: %lld\n", c, i*n);
  }

  return 0;
}
