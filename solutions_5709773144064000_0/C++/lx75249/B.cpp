#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define see(x) cerr<<#x<<" = " << (x) << endl
using namespace std;
double C,F,X;
double check(int count)
{
  double rate = 2.0;
  double res = 0;
  while(count--)
  {
    res += C/rate;
    rate += F;
  }
  res += X/rate;
  return res;
}
int main()
{
  freopen("B-small-attempt0.in","r",stdin);
  freopen("out1","w",stdout);
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;i++)
  {
    scanf("%lf%lf%lf", &C,&F,&X);
    int left=0, right=X/C+1;
    while(true)
    {
      int lm = (2*left+right)/3;
      int rm = (left+2*right)/3;
      if (lm == left || right == rm)
        break;
      double lmsec = check(lm);
      double rmsec = check(rm);
      if (lmsec > rmsec)
      {
        left = lm;
      }
      else
        right = rm;
    }
    double ans=check(left);
    for(int j=left+1;j<=right;j++)
      ans = min(ans, check(j));
    printf("Case #%d: %.7lf\n", i, ans);
  }
  return 0;
}
