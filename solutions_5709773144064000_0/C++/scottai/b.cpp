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

double c,f,x;

double check(int i)
{
   double s=0;
   for (int j=0;j<i;j++)
      s+=c/(2+j*f);
   s+=x/(2+i*f);
   return s;
}

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int q;
   cin>>q;
   for (int t=1;t<=q;t++)
   {
      double ans=oo;
      int l=0,r=2000000;
      cin>>c>>f>>x;
      while (l<r-5)
      {
         int mid=(l+r)>>1;
         if (check(mid)>check(mid+1))
            l=mid;
         else
            r=mid+1;
      }
      for (int i=l;i<=r;i++)
         ans=min(ans,check(i));
      printf("Case #%d: %.7lf\n",t,ans);
   }
   return 0;
}
