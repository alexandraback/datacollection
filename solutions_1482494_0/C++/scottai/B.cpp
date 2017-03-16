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

int a[1001],b[1001],hash[1001];

int main()
{
   freopen("b.in","r",stdin);
   freopen("b.out","w",stdout);
   int t,q;
   cin>>q;
   for (int t=1;t<=q;t++)
   {
      int n,s=0,ans=0;
      cin>>n;
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i],&b[i]);
         hash[i]=0;
      }
      printf("Case #%d: ",t);
      while (s<2*n)
      {
         int p=0;
         for (int i=1;i<=n;i++)
            if (hash[i]!=2&&b[i]<=s)
            {
               s+=2-hash[i];
               hash[i]=2;
               ans++;
               goto out;
            }
         for (int i=1;i<=n;i++)
            if (!hash[i]&&a[i]<=s&&(!p||b[i]>b[p]))
               p=i;
         if (!p)
         {
            puts("Too Bad");
            goto end;
         }
         ans++;
         s++;
         hash[p]=1;
         out:;
      }
      cout<<ans<<endl;
      end:;
   }
   return 0;
}
