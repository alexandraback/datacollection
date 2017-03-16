#include <cstdio>

int wh(int w, int h){
  return w * h + w + w + h + h;
}
int nu(int w, int h){ return w + w + h + h; }

int main(){
  for(int TT, T = (scanf("%d", &TT), 1); T <= TT; T++){
    printf("Case #%d: ", T);
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int ans = 99999;
    for(int w = 0; w <= N; w++){
      for(int h = 0; h <= M; h++){
        if(w + 2 <= N && h + 2 <= M){
          if(wh(w, h) >= K){
            if(nu(w, h) < ans){
              ans = nu(w, h);
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
