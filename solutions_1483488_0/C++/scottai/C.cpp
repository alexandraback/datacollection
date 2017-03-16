#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define dis(x1,y1,x2,y2) sqrt(((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const int oo = 1000000000;
const double E = 2.7182818284590452353602874713527;
const double pi = 3.1415926535897932384626433832795;
using namespace std;

int main()
{
   freopen("C-small-attempt0.in","r",stdin);
   freopen("C-small-attempt0.out","w",stdout);
   int q;
   cin>>q;
   for (int t=1;t<=q;t++)
   {
      int a,b,ans=0;
      cin>>a>>b;
      for (int i=a;i<=b;i++)
      {
         int t=i,s=1;
         while (t/10)
         {
            t/=10;
            s*=10;
         }
         t=i;
         while (1)
         {
            t=t/10+t%10*s;
            ans+=(t>i&&t<=b);
            if (t==i)
               break;
         }
      }
      printf("Case #%d: %d\n",t,ans);
   }
   return 0;
}
