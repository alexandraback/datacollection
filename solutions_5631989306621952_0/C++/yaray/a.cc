#include <cstdio>
#include <cstring>
using namespace std;

#define REP1(i, n) for (int i = 1; i <= (n); i++)

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 2000;
char a[N+1], b[N+1], c[N+1];

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    scanf("%s", a);
    int n;
    for (n = 0; a[n]; n++) {
      b[0] = a[n];
      memcpy(b+1, a, n);
      if (memcmp(a, b, n+1) < 0)
        memcpy(a, b, n+1);
    }
    printf("Case #%d: %s\n", cc, a);
  }
}
