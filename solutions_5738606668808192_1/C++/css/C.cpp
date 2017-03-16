#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

int T, n, j;
vector<int> ans;

int sum(ll x) {
  int ans = 0;
  for (; x; x &= x - 1) ans++;
  return ans;
}

int main()
{
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);

  scanf("%d", &T);
  for (int cou = 1; cou <= T; cou++) {
    scanf("%d%d", &n, &j);

    printf("Case #%d:\n", cou);

    for (ll u = 0; u < (1 << 15); u++)
      if (sum(u) == 8) ans.push_back(u);
    
    for (int i = 0; i < j; i++) {
      for (int p = 0; p < 32; p++) {
        if (p == 0 || p == 31) {
          printf("1");
          continue;
        }
        if (p & 1) {
          printf("%d", 1 & (ans[i] >> (p >> 1)));
        } else {
          if (p <= 10) printf("1"); else printf("0"); 
        }
      }
      
      for (int i = 2; i <= 10; i++) printf(" %d", (i & 1) ? 2 : (i == 6 ? 5 : 3));
      printf("\n");
    }
  }

  fclose(stdin);
  fclose(stdout);
}
