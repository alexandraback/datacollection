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
   freopen("B-small-attempt0.in","r",stdin);
   freopen("B-small-attempt0.out","w",stdout);
   int t,q;
   cin>>q;
   for (int t=1;t<=q;t++)
   {
      int n,s,p,a1=0,a2=0;
      cin>>n>>s>>p;
      for (int i=1;i<=n;i++)
      {
         int a,x,y;
         cin>>a;
         if (a%3==0)
         {
            x=a/3;
            y=a/3+(a>0);
         }
         else if (a%3==1)
            x=y=a/3+1;
         else
         {
            x=a/3+1;
            y=a/3+2;
         }
         if (x>=p)
            a1++;
         else if (y>=p)
            a2++;
      }
      printf("Case #%d: %d\n",t,a1+min(a2,s));
   }
   return 0;
}
