#include <cstdio>
#include <map>
#include <utility>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define fi first
#define se second

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 50;

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int n = ri();
    map<int, int> c;
    REP(i, n*(2*n-1))
      c[ri()]++;
    printf("Case #%d:", cc);
    for (auto &x: c)
      if (x.se & 1)
        printf(" %d", x.fi);
    puts("");
  }
}
