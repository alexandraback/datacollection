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
    int N;
    scanf("%d",&N);
    set<double> naomi,ken;

    for(int i=0;i<N;i++)
    {
      double x;
      scanf("%lf",&x);
      naomi.insert(x);
    }

    for(int i=0;i<N;i++)
    {
      double x;
      scanf("%lf",&x);
      ken.insert(x);
    }

    int cnt=0;
    for(set<double>::iterator nsit=naomi.begin(),ksit=ken.begin();nsit!=naomi.end();nsit++,ksit++)
    {
      while((ksit!=ken.end())&&(*ksit<*nsit))ksit++;
      if(ksit==ken.end())break;
      cnt++;
    }
    cnt=N-cnt;

    int cnt2=0;
    for(int i=0;i<N;i++)
    {
      double x=*naomi.begin(),y=*ken.begin(),z=*ken.rbegin();
      naomi.erase(x);
      if(x>y)
      {
        cnt2++;
        ken.erase(y);
      }
      else
      {
        ken.erase(z);
      }
    }

    printf("Case #%d: %d %d\n",t,cnt2,cnt);
  }
  return 0;
}

