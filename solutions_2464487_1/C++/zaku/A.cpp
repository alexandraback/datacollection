#include <cstdio>

#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define SZ(v) ((int)(v).size())

typedef long long LL;

#ifdef __linux__
#define FMT "%lld"
#else
#define FMT "%I64d"
#endif

LL R, T;

void solve()
{
  // LL k = 0;
  // do {
  //   if (T < 2*R + 4*k + 1) break;
  //   T -= (2*R + 4*k + 1);
  //   ++k;
  // } while(1);

  LL l = 0, r = 1000000000;
  LL t1, t2, k, result = 0;

  while (l <= r) {
    k = (l+r)/2;
    if ((double)T/(k+1) < (2*R+1 + 2*k)) {
      if (l == r) break;
      r = k;
      continue;
    }

    t1 = (2*R+1)*(k+1);
    t2 = 2*k*(k+1);
    if (t1 + t2 <= T) {
      result = k;
      l = k+1;
    } else {
      if (l == r) break;
      r = k;
    }
  }

  printf(FMT "\n", k);
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    scanf(FMT FMT, &R, &T);
    printf("Case #%d: ", l);
    solve();
  }
  return 0;
}
