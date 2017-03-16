#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

double P[MAXN];
int A, B;

void solve()
{
  double res = B+2;

  double pro = 1.0;
  for (int i = 0; i < A; ++i) pro *= P[i];
  res = min(res, pro*(B-A+1) + (1.0-pro)*(B-A+1 + B+1));
  
  pro = 1.0;
  for (int i = 0; i < A; ++i) {
    int ext = (A-i)+ (B-i) + 1;
    double cur = pro*ext + 
      (1.0-pro)*(ext + B + 1);

    pro *= P[i];
    res = min(res, cur);
  }

  printf("%.6f\n", res);
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    printf("Case #%d: ", l);
    scanf("%d%d", &A, &B);
    for (int i = 0; i < A; ++i) scanf("%lf", P + i);
    solve();
  }
  return 0;
}
