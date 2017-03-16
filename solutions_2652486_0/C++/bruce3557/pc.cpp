#include <stdio.h>
#include <string.h>

int R, N, M, K;
int v[20];
int tmp[20];
int ans[20];
bool choose[20][20];

bool fit(int now, int round) {
  if(round >= K) {
    return true;
  }
  if(now >= N) {
    int product = 1;
    for(int i=0;i<N;++i)
      if( choose[round][i] )
        product *= tmp[i];
    if(product != v[round])  return false;
    return fit(0, round+1);
  }
  choose[round][now] = true;
  if( fit(now+1, round) ) return true;
  choose[round][now] = false;
  if( fit(now+1, round) ) return true;
  return false;
}

bool go(int now) {
  if(now >= N) {
    memset(choose, 0, sizeof(choose));
    if( fit(0, 0) ) {
      for(int i=0;i<N;++i)
        ans[i] = tmp[i];
      return true;
    }
    return false;
  }
  for(int i=2;i<=M;++i) {
    tmp[now] = i;
    if( go(now + 1) ) return true;
  }
  return false;
}

int main() {
  int t, kas=0;

  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d%d", &R, &N, &M, &K);
    
    printf("Case #%d:\n", ++kas);
    while(R--) {
      for(int i=0;i<K;++i)
        scanf("%d", v+i);
      bool yes = go(0);
      if(yes) {
        for(int i=0;i<N;++i)
          printf("%d", ans[i]);
        puts("");
      } else {
        for(int i=0;i<N;++i)
          printf("2");
        puts("");
      }
    }
  }

  return 0;
}

