
#include <cstdio>


int main(int argc, char** argv) {

  int T;
  scanf("%d",&T);

  for (int t=1; t<=T; t++) {
    printf("Case #%d: ", t);

    int N, S, P;
    int R = 0;
    scanf("%d%d%d", &N, &S, &P);

    for (int i = 0; i < N; i++) {

      int s;
      scanf("%d",&s);

      int score = s / 3;
      int mode = s % 3;

      if (mode > 0) score++;

      if (score >= P) R++;
      else if (score > 0 && score+1 >= P && mode != 1 && S > 0) {R++; S--;}
    }

    printf("%d\n", R);
  }

  return 0;
}
