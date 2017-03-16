#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
  ll t;
  while (b) {
    t = a % b;
    a = b;
    b = t;
  }
  return a;
}


int main()
{
  int T;

  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  //freopen("input.txt", "r", stdin);

  scanf("%d", &T);

  for (int cn = 1; cn <= T; cn++) {
    ll P, Q;
    scanf("%I64d/%I64d", &P, &Q);

    ll C = gcd(P, Q);
    P = P / C;
    Q = Q / C;

    ll x = Q;

    int ans = -1;

    for (int i = 1; i <= 40; i++) {
      if (x % 2 != 0) {
        break;
      }
      x /= 2;
      if (P >= x) {
        ll y = x;
        while (y % 2 == 0) {
          y /= 2;
        }
        if (y == 1) {
          ans = i;
          break;
        }
      }

    }
    
    printf("Case #%d: ", cn);
    if (ans == -1) {
      printf("impossible\n");
    } else {
      printf("%d\n", ans);
    }
  }

  return 0;
}
