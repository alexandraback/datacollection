#include<cstdio>
#include<algorithm>
#define eps 0.000001

using namespace std;

float naomi[1005], ken[1005];
struct block
{
  float val;
  bool isnaomi;
};

block total[2005];

bool cmp(float a, float b)
{
  if(a - b < eps)
    return 1;
  else
    return 0;
}

bool cmp2(block a, block b)
{
  if(a.val - b.val < eps)
    return 1;
  else
    return 0;
}

int main()
{
  int t, n, i, k, scoredw, contorken, rez;
  scanf("%d", &t);
  for(k = 1; k <= t; ++ k)
  {
    rez = 0;
    scoredw = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; ++ i)
      scanf("%f", &naomi[i]);
    for(i = 1; i <= n; ++ i)
      scanf("%f", &ken[i]);
    sort(naomi + 1, naomi + n + 1, cmp);
    sort(ken + 1, ken + n + 1, cmp);
    for(i = 1; i <= n; ++ i)
    {
      total[i].val = naomi[i];
      total[n + i].val = ken[i];
      total[i].isnaomi = true;
      total[n + i].isnaomi = false;
    }
    sort(total + 1, total + n + n + 1, cmp2);
    contorken = 0;
    rez = 0;
    for(i = n + n; i >= 1; -- i)
    {
      if(total[i].isnaomi == true)
      {
        if(contorken == 0)
          ++ rez;
        else
          -- contorken;
      }
      else
        ++ contorken;
    }
    scoredw = 0;
    contorken = 0;
    for(i = 1; i <= n + n; ++ i)
    {
      if(total[i].isnaomi == true)
      {
        if(contorken != 0)
        {
          ++ scoredw;
          -- contorken;
        }
      }
      else
        ++ contorken;
    }
    printf("Case #%d: %d %d\n", k, scoredw, rez);
  }
  return 0;
}
