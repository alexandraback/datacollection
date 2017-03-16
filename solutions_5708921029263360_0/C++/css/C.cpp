#include <cstdio>
using namespace std;

int T, j, p, s, k;

int main()
{
  freopen("C-small-attempt2.in", "r", stdin);
  freopen("output.out", "w", stdout);

  scanf("%d", &T);
  for (int cou = 1; cou <= T; cou++) {
    scanf("%d%d%d%d", &j, &p, &s, &k);

    if (s < k) k = s;

    printf("Case #%d: %d\n", cou, j * p * k);
    for (int t0 = 0; t0 < j; t0++)
      for (int t1 = 0; t1 < p; t1++)
        for (int i = 0; i < k; i++)
          printf("%d %d %d\n", t0 + 1, t1 + 1, 
                 (((t0 + t1) * k + i) % s) + 1);
  }

  fclose(stdin);
  fclose(stdout);
}
