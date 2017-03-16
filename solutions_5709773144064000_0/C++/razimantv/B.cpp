# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>
# include <map>

using namespace std;

int main()
{
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    double C,F,X;
    scanf("%lf%lf%lf",&C,&F,&X);

    double rate=2,best=X/rate,t0=0;
    while(1)
    {
      double cur=t0+C/rate+X/(rate+F);
      if(cur>best)break;
      best=cur;
      t0+=C/rate;
      rate+=F;
    }
    printf("Case #%d: %.7lf\n",t,best);
  }
  return 0;
}

