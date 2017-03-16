#include <stdio.h>
#define MAX_OUTFIT 1011
#define MAX_2COMBO 111

int main() {
  int T, J, P, S, K;
  int valid_outfit[MAX_OUTFIT][3];
  int jp_count[MAX_2COMBO], ps_count[MAX_2COMBO], js_count[MAX_2COMBO];
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d %d %d %d", &J, &P, &S, &K);
    int m = 0;

    for (int i = 0; i < MAX_2COMBO; i++) {
      jp_count[i] = ps_count[i] = js_count[i] = 0;
    }

    for (int j = 0; j < J; j++) {
      for (int p = 0; p < P; p++) {
        for (int s = 0; s < S; s++) {
          int jp = j*10 + p, ps = p*10 + s, js = j*10 + s;
          if (jp_count[jp] < K && ps_count[ps] < K && js_count[js] < K) {
            ++jp_count[jp];
            ++ps_count[ps];
            ++js_count[js];
            valid_outfit[m][0] = j;
            valid_outfit[m][1] = p;
            valid_outfit[m][2] = s;
            ++m;
          }
        }
      }
    }

    printf("Case #%d: %d\n", t, m);
    for (int i = 0; i < m; i++) {
      printf("%d %d %d\n", valid_outfit[i][0] + 1, valid_outfit[i][1] + 1, valid_outfit[i][2] + 1);
    }
  }
  return 0;
}