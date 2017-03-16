#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 1000;
bool mark[N];
int a[N], d[N], b[N];

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int n = ri();
    fill_n(mark, n, false);
    fill_n(d, n, 0);
    fill_n(b, n, 0);
    REP(i, n)
      d[a[i] = ri()-1]++;
    int top = -1;
    REP(i, n)
      if (! d[i])
        d[i] = top, top = i;
    while (~ top) {
      int x = top;
      top = d[top];
      mark[x] = true;
      b[a[x]] = max(b[a[x]], b[x]+1);
      if (! --d[a[x]])
        d[a[x]] = top, top = a[x];
    }
    int s = 0, t = 0;
    REP(i, n)
      if (! mark[i]) {
        int c = 1, x = a[i];
        mark[i] = true;
        for (; x != i; x = a[x])
          c++, mark[x] = true;
        if (c == 2)
          s += b[i]+b[a[i]]+c;
        t = max(t, c);
      }
    printf("Case #%d: %d\n", cc, max(s, t));
  }
}
