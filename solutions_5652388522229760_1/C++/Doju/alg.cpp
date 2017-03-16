#include <cstdio>

const int MAXN = 1000000;

bool vs[10];

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    printf("Case #%d: ", tt);

    int N; scanf("%d", &N);

    if(N == 0){ puts("INSOMNIA"); continue; }

    for(int i = 0; i < 10; i++) vs[i] = false;

    int ans = -1, vc = 0;
    for(int n = N; ; n += N){
      for(int n_ = n; n_ > 0; n_ /= 10){
        if(!vs[n_ % 10]){ vs[n_ % 10] = true; vc++; }
      }
      if(vc == 10){ ans = n; break; }
    }

    printf("%d\n", ans);
  }
  return 0;
}
