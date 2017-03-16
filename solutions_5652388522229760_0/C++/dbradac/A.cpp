#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

void Dodaj(ll x, int p[10])
{
  for (; x; x /= 10)
    p[x%10] = 1;
}

int main()
{
  int brt;

  scanf("%d", &brt);

  for (int br=1; br<=brt; br++) {
    int n;
    scanf("%d", &n);
    int p[10];
    memset(p, 0, sizeof p);
    printf("Case #%d: ", br);

    if (!n)
      printf("INSOMNIA\n");
    else {
      for (int i=1; ; i++) {
        Dodaj((ll) i * n, p);
        int da = 1;
        for (int j=0; j<10; j++)
          da &= p[j];

        if (da) {
          printf("%lld\n", (ll) i * n);
          break;
        }
      }
    }
  }

  return 0;
}

