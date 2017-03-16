#include <cstdio>

int p[110];

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    printf("Case #%d: ", tt);

    int K, C, S;
    scanf("%d%d%d", &K, &C, &S);

    if(C * S < K){ puts("IMPOSSIBLE"); continue; }

    for(int s = 1; s <= K; s += C){
      for(int i = 0; i < C; i++){
        p[i] = s + i;
        if(p[i] > K) p[i] = 1;
      }

      long long v = 0;
      for(int i = 0; i < C; i++){
        v = v * K + p[i] - 1;
      }
      printf("%lld ", v + 1);
    }
    printf("\n");
  }
  return 0;
}
