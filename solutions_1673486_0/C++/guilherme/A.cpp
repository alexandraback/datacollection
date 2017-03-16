#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<functional>
#include<sstream>
#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

#define DEBUG(x...) printf(x)
#define allv(v) (v).begin(),(v).end()
#define rall(v) (v).begin(),(v).rend()
#define _foreach(it,b,e) for(__typeof__(b); it!=(e);++it)
#define foreach(x...) _foreach(x)

typedef long long int huge;

const int inf = 0x3f3f3f3f;
const huge hugeinf = 0x3f3f3f3f3f3f3f3fll;//dois L's
const double eps = 1e-9;
const int maxn = 200000;
int a,b;
double prob[maxn];

int main ()
{
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++)
    {
      prob[0]=1;
      scanf("%d %d" ,&a,&b);
      for(int i=1;i<=a;i++){
        scanf("%lf",&prob[i]);
      }
      double best = 1+b+1;
      
      double p = 1;
      for(int i=1;i<=a;i++)
        p*=prob[i];
      
      best = min(best, b-a+1 + (1-p)*(b+1));
      
      p = 1;
      for(int i=0;i<=a;i++){
        p*=prob[i];
        best = min(best, (a-i) + (a-i) + (b-a) + 1 + (1-p)*(b+1));
      }
      printf("Case #%d: %lf\n",pp,best);
    }
  return 0;
}
