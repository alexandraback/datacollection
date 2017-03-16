#include<cstdio>

typedef long long ll;

char s[10010];

int p[8][8] = {
  { 0, 1, 2, 3, 4, 5, 6, 7 },
  { 1, 4, 3, 6, 5, 0, 7, 2 },
  { 2, 7, 4, 1, 6, 3, 0, 5 },
  { 3, 2, 5, 4, 7, 6, 1, 0 },
  { 4, 5, 6, 7, 0, 1, 2, 3 },
  { 5, 0, 7, 2, 1, 4, 3, 6 },
  { 6, 3, 0, 5, 2, 7, 4, 1 },
  { 7, 6, 1, 0, 3, 2, 5, 4 }};

int main() {

  int T;

  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {

    int L;
    ll X;
    
    scanf("%d%lld\n%s", &L, &X, s);

    if (X > 11)
      X = 8 + (X % 4);
    for (int i = 0; i < L; i++)
      s[i] -= 'h';
    
    int LL = L * X;
    
    int P = 0;
    for (int i = 0; i < LL; i++)
      P = p[P][(int)s[i % L]];

    printf("Case #%d: ", t);

    if (P == 4) {
      int l = 0;
      int i = 0;
      for (; i < LL; i++)
        if ((l = p[l][(int)s[i % L]]) == 1)
          break;
      if (i < LL) {
        int r = 0;
        int j = LL - 1;
        for (; j > 0; j--)
          if ((r = p[(int)s[j % L]][r]) == 3)
            break;
        if (j > 0 && i < j) {
          puts("YES");
          continue;
        }
      }
    }
    puts("NO");

  }

  return 0;
}
