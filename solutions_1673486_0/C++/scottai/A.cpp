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
#include <deque>
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

double a[100001],s[100001];

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int t,q;
   cin>>q;
   for (int t=1;t<=q;t++)
   {
      int n,m;
      double ans;
      cin>>n>>m;
      s[0]=1;
      for (int i=1;i<=n;i++)
      {
         scanf("%lf",&a[i]);
         s[i]=s[i-1]*a[i];
      }
      ans=m+2;
      for (int i=0;i<=n;i++)
         ans=min(ans,s[i]*(m-i+1)+(1-s[i])*(m-i+1+m+1)+n-i);
      printf("Case #%d: %.12lf\n",t,ans);
   }
   return 0;
}
