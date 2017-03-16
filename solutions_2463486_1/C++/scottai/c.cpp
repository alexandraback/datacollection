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

long long a[10000001];

bool check(long long x)
{
   long long y=0,t=x;
   while (t)
   {
      y=y*10+t%10;
      t/=10;
   }
   return x==y;
}

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int o=0;
   for (int i=1;i<=10000000;i++)
      if (check(1LL*i*i)&&check(i))
         a[++o]=1LL*i*i;
   int q;
   cin>>q;
   for (int tt=1;tt<=q;tt++)
   {
      long long l,r;
      int ans=0;
      cin>>l>>r;
      for (int i=1;i<=o;i++)
         if (a[i]>=l&&a[i]<=r)
            ans++;
      printf("Case #%d: %d\n",tt,ans);
   }
   return 0;
}
