#include <cstdio>

const int MAXH = 2500;

int cnt[MAXH + 10];

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    printf("Case #%d: ", tt);

    int N; scanf("%d", &N);
    for(int i = 1; i < 2 * N; i++){
      for(int j = 0; j < N; j++){
        int x; scanf("%d", &x);
        cnt[x]++;
      }
    }

    for(int i = 1; i <= MAXH; i++){
      if(cnt[i] % 2 == 1) printf("%d ", i);
      cnt[i] = 0;
    }
    printf("\n");
  }
  return 0;
}
