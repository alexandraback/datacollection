#include<cstdio>
#define eps 0.00000001

using namespace std;

int main()
{
  int t, i, j;
  double rez, c, f, x, timpf, sum;
  scanf("%d", &t);
  for(i = 1; i <= t; ++ i)
  {
    scanf("%lf%lf%lf", &c, &f, &x);
    rez = x * 0.5;
    timpf = 0.0;
    sum = 2.0;
    for(j = 1; ; ++ j)
    {
      timpf = timpf + c / sum;
      sum += f;
      if(timpf - x > -eps)
        break;
      if(timpf + x / sum - rez < eps)
        rez = timpf + x / sum;
      else
        break;
    }
    printf("Case #%d: %lf\n", i, rez);
  }
  return 0;
}
