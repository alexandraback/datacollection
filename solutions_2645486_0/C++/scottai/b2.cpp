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

int f[101][101],v[101];

int main()
{
   freopen("b2.in","r",stdin);
   freopen("b2.out","w",stdout);
   int q;
   cin>>q;
   for (int tt=1;tt<=q;tt++)
   {
      int e,r,n;
      cin>>e>>r>>n;
      for (int i=1;i<=n;i++)
         cin>>v[i];
      for (int i=1;i<=n+1;i++)
         for (int j=0;j<=e;j++)
            f[i][j]=0;
      for (int i=n;i;i--)
         for (int j=0;j<=e;j++)
            for (int k=0;k<=j;k++)
               f[i][j]=max(f[i][j],f[i+1][min(j-k+r,e)]+k*v[i]);
      printf("Case #%d: %d\n",tt,f[1][e]);
   }
   return 0;
}
