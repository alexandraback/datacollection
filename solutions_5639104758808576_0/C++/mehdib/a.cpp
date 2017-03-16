#include<cstdio>

char nbS[1010];

int main() {

  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {

    int Smax, friends = 0, audience = 0;
    scanf("%d%s", &Smax, nbS);

    for (int s = 0; s <= Smax; s++) {
      int nb = nbS[s] - '0';
      if (audience < s) {
        friends += s - audience;
        audience = s;
      }
      audience += nb;
    }

    printf("Case #%d: %d\n", t, friends);
  }

  return 0;
}
