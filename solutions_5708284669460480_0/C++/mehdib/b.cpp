#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int K, L, S;
char kb[103];
char okb[26];
char s[103];

char g[103];

int bananas(int p) {
  if (p+L > S)
    return 0;
  for (int i = 1; i <= L; i++)
    if (strncmp(s, s + i, L - i) == 0)
      return bananas(p + i) + 1;
  return 0;
}

double pay(int p) {
  if (p >= S) {
    int res = 0;
    for (int i = 0; i <= S - L; i++)
      if (strncmp(g + i, s, L) == 0)
        res++;
    return (double)res;
  }
  double res = 0.0;
  for (int k = 0; k < K; k++) {
    g[p] = kb[k];
    res += pay(p+1);
  }
  return res / (double)K;
}


int main(void) {

  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {

    scanf("%d%d%d\n", &K, &L, &S);
    gets(kb);
    gets(s);

    memset(okb, 0, sizeof(okb));

    for (int i = 0; i < K; i++)
      okb[kb[i]-'A']++;

    bool poss = true;

    for (int i = 0; i < L; i++)
      if (!okb[s[i]-'A']) {
        poss = false;
        break;
      }

    double res = 0.0;

    if (poss) {
      // printf("bananas: %d\n", bananas(0));
      // printf("pay: %lf\n", pay(0));
      res = (double)bananas(0) - pay(0);
    }

    printf("Case #%d: %.8lf\n", t, res);
  }

  return 0;
}
