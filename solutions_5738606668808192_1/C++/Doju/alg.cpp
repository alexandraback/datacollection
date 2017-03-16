#include <cstdio>

int b[40];

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    printf("Case #%d:\n", tt);

    int N, J; scanf("%d%d", &N, &J);

    int ansc = 0;
    for(unsigned int n = (1 << (N - 1)) + 1; ansc < J; n += 2){
      int m = 0, l = 0;
      for(unsigned int n_ = n; n_ > 0; n_ /= 2, l++){
        b[l] = n_ % 2;
        if(l % 2 == 0) m += b[l];
        else m -= b[l];
      }

      if(m == 0){
        ansc++;
        for(int i = l - 1; i >= 0; i--) printf("%d", b[i]);
        for(int i = 2; i <= 10; i++) printf(" %d", i + 1);
        printf("\n");
      }
    }
  }
  return 0;
}
