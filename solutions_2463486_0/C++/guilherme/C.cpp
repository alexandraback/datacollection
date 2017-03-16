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
typedef long long int huge;
huge todos[99];
int qte;
inline int calc(huge a, huge b){
  return (a/b)%10;
}
inline bool is_pal(huge a)
{
  huge pot =1;
  huge r = 1;
  while(pot<=a)pot*=10;
  pot/=10;
  while(pot>0){
    if(calc(a,r) != calc(a,pot))return false;
    pot/=10;
    r*=10;
  }

  return true;
}
int main ()
{
  int tt;
  scanf("%d",&tt);
  for(huge i=1;i<=20000000;i++)
    {
      if(is_pal(i) && is_pal(i*i)){todos[qte++]=i*i;}
      
    }

  for(int pp=1;pp<=tt;pp++)
    {
      huge a,b;
      scanf("%lld %lld",&a,&b);
      int ret = 0;
      for(int i=0;i<qte;i++)
	if(todos[i]>=a && todos[i]<=b)ret++;
      printf("Case #%d: %d\n",pp,ret);
    }
  return 0;
}
