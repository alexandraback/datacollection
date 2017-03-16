#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxN = 100 + 7;

ll a[maxN];
int T, k, c, s;

int main()
{
  freopen("D-large.in", "r", stdin);
  freopen("output.out", "w", stdout);

  scanf("%d", &T);
  for (int cou = 1; cou <= T; cou++) {
    scanf("%d%d%d", &k, &c, &s);

    bool st = true;
    ll up = 1;
    for (int i = 0; i < c; i++) up *= k;

    for (int i = 0; i < s; i++) a[i] = 0;
    for (int i = 0; i < k; i++) {
      a[0] = a[0] * k + i;
      if (a[0] >= up) {
        st = false;
        break;
      }
      sort(a, a + s);
    }

    printf("Case #%d: ", cou); 

    if (st && k <= s * c) {
      printf("%lld", a[0] + 1);
      for (int i = 1; i < s; i++)
        if (a[i] > a[i - 1]) printf(" %lld", a[i] + 1);
      printf("\n");
    } else {
      printf("IMPOSSIBLE\n");
    }
  }

  fclose(stdin);
  fclose(stdout);
}
