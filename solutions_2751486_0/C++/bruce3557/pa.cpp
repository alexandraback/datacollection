#include <stdio.h>
#include <string.h>

char str[1000010];
long long cons[1000010];

bool check(char x) {
  return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

int main() {
  int t, kas=0;

  scanf("%d", &t);
  while(t--) {
    long long L, N;
    scanf("%s %lld", str+1, &N);
    L = strlen(str+1);
    for(int i=1;i<=L;++i) {
      if( check(str[i]) ) {
        cons[i] = 0;
      } else {
        cons[i] = 1;
      }
    }
    
    cons[0] = 0;
    for(int i=1;i<=L;++i)
      if(cons[i])
        cons[i] += cons[i-1];
    long long sum = 0;
    long long pre = 0;
    for(int i=1;i<=L;++i) {
      if(cons[i] >= N) {
        pre = i - N + 1;
        if(pre >= 0)  sum += pre;
      } else {
        sum += pre;
      }
    }
    printf("Case #%d: %lld\n", ++kas, sum);
  }

  return 0;
}

