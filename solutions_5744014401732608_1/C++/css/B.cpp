#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll m, t;
int T, b;

int main()
{
  freopen("B-large.in", "r", stdin);
  freopen("output.out", "w", stdout);

  scanf("%d", &T);
  for (int cou = 1; cou <= T; cou++) {
    scanf("%d%lld", &b, &m);
    printf("Case #%d:", cou); 

    int i = 2;
    for (t = 1; i < b && t < m; t <<= 1) i++;

    if (t >= m) {
      printf(" POSSIBLE\n");
      for (int i = 1; i <= b; i++) { 
        for (int j = 1; j < b; j++) printf("%d", i < j ? 1 : 0);
        if (i == 1) {
          if (t == m) {
            printf("1");
            m--;
          } else
            printf("0");
        } else {
          printf("%d", (m & 1) > 0 ? 1 : 0);
          m >>= 1;
        }
        printf("\n");
      }
    } else {
      printf(" IMPOSSIBLE\n");
    }
  }

  fclose(stdin);
  fclose(stdout);
}
