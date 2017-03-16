#include <cstdio>
using namespace std;

typedef long long ll;

ll div[17];
int T, n, j;

ll base(ll x, int t) {
  ll ans = 0, m = 1;
  for (; x; x >>= 1)
    ans += m * (x & 1), m *= t;
  return ans;
}

bool pass(ll x) {
  for (int i = 2; i <= 10; i++) {
    ll u = base(x, i);

    div[i] = -1;
    for (ll v = 2; v * v <= u; v++)
      if (u % v == 0) {
        div[i] = v;
        break;
      }

    if (div[i] < 0) return false;
  }

  printf("%lld", base(x, 10));
  for (int i = 2; i <= 10; i++) printf(" %lld", div[i]);
  printf("\n");

  return true;
}

int main()
{
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);

  scanf("%d", &T);
  for (int cou = 1; cou <= T; cou++) {
    scanf("%d%d", &n, &j);

    printf("Case #%d:\n", cou);
    for (ll u = 0; j && u < (1LL << (n - 2)); u++)
      if (pass((1LL << (n - 1)) + (u << 1) + 1)) j--; 
  }

  fclose(stdin);
  fclose(stdout);
}
