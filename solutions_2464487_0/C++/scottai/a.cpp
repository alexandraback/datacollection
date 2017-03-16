#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
#include <vector>
#include <sstream>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dis(x1,y1,x2,y2) (((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const double pi = acos(-1);
const int oo = 1000000000;
const int mod = 1000000007;
const double E = 2.7182818284590452353602874713527;
using namespace std;

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   long long q;
   cin>>q;
   for (int tt=1;tt<=q;tt++)
   {
      long long r,t;
      cin>>r>>t;
      int ll=0,rr=oo;
      while (ll<rr-1)
      {
         int mid=(ll+rr)>>1;
         long double tmp1=2.*r*mid+(1+4.*mid-3)*mid/2;
         if (tmp1>3e18)
         {
            rr=mid;
            continue;
         }
         long long tmp=2*r*mid+(1+4LL*mid-3)*mid/2;
         if (tmp<=t)
            ll=mid;
         else
            rr=mid;
      }
      printf("Case #%d: %d\n",tt,ll);
   }
   return 0;
}
