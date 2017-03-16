#include <stdio.h>

int s[1000];

int main(void) {
  int T, N, i, cas, sum;
  double answer;
  scanf("%d", &T);
  for(cas=1; cas<=T; cas++) {
    sum=0;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
      scanf("%d", s+i);
      sum += s[i];
    }
    printf("Case #%d:", cas);
    for(i=0; i<N; i++) {
      answer = 100.f * (2.f / (double)N - (double)s[i]/(double)sum);
      if(answer < 0.f) answer = 0.f;
      printf(" %f", answer);
    }
    printf("\n");
  }
  return 0;
}
