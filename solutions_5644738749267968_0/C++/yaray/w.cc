#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;

#define FOR(i, a, b) for (__typeof(b) i = (a); i < (b); i++)
#define REP1(i, n) FOR(i, 1, n+1)
#define REP(i, n) FOR(i, 0, n)

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

double rd()
{
  double x;
  scanf("%lf", &x);
  return x;
}

const int N = 1000;
double a[N], b[N];

int main()
{
  int cases = ri();
  REP1(cid, cases) {
    int n = ri();
    REP(i, n) a[i] = rd();
    REP(i, n) b[i] = rd();
    sort(a, a+n);
    sort(b, b+n);

    int ans0 = 0, ans1 = 0;
    for (int j = 0, i = 0; i < n; i++) {
      for (; j < n && a[j] < b[i]; j++);
      if (j < n) {
        ans0++;
        j++;
      }
    }

    for (int j = 0, i = 0; i < n; i++) {
      for (; j < n && b[j] < a[i]; j++);
      if (j == n)
        ans1++;
      else
        j++;
    }

    printf("Case #%d: %d %d\n", cid, ans0, ans1);
  }
}
