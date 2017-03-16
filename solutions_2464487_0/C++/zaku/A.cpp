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
  LL k = 0;
  do {
    if (T < 2*R + 4*k + 1) break;
    T -= (2*R + 4*k + 1);
    ++k;
  } while(1);

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
