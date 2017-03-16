#include <stdio.h>
#include <string.h>

int E, R, N;
int v[20];
int maximum;

void go(int now, int energy, int sum) {
  if(now >= N) {
    if(sum > maximum) maximum = sum;
    return;
  }
  for(int i=0;i<=energy;++i) {
    int nextEgy = energy - i + R;
    if(nextEgy > E) nextEgy = E;
    go(now + 1, nextEgy, sum + i * v[now]);
  }
}

int main() {
  int t, kas=0;
  
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d", &E, &R, &N);
    for(int i=0;i<N;++i)
      scanf("%d", v+i);
    
    maximum = 0;
    go(0, E, 0);
    printf("Case #%d: %d\n", ++kas, maximum);
  }

  return 0;
}

