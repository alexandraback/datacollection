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
   freopen("c.in","r",stdin);
   freopen("c.out","w",stdout);
   int q,r,n,m,k,count=0;
   cin>>q;
   cout<<"Case #1:"<<endl;
   cin>>r>>n>>m>>k;
   for (int i=1;i<=r;i++)
   {
      int a,n2=0,n3=0,n4=0,n5=0;
      if (i==15)
         i=15;
      for (int j=1;j<=k;j++)
      {
         cin>>a;
         if (a%125==0)
            n5=max(n5,3);
         else if (a%25==0)
            n5=max(n5,2);
         else if (a%5==0)
            n5=max(n5,1);
         if (a%27==0)
            n3=max(n3,3);
         else if (a%9==0)
            n3=max(n3,2);
         else if (a%3==0)
            n3=max(n3,1);
         if (a%64==0)
            n4=max(n4,3);
         else if (a%32==0)
         {
            n4=max(n4,2);
            n2=max(n2,1);
         }
         else if (a%16==0)
            n4=max(n4,1);
         else if (a%8==0)
            n2=max(n2,1);
         else if (a%4==0);
         else if (a%2==0)
            n2=max(n2,1);
      }
   /*   double tmp=1.*n2/(n2+n3),tt=oo;
      int rec;
      for (int j=0;j<=5;j++)
         if (abs(j/5.-tmp)<tt)
         {
            tt=abs(j/5.-tmp);
            rec=j;
         }
      n2=rec;
      n3=m-n2;*/
      if (n2+n3+n4+n5!=n)
         count++;
      n4=n-n3-n2-n5;
      for (int j=1;j<=n2;j++)
         cout<<2;
      for (int j=1;j<=n3;j++)
         cout<<3;
      for (int j=1;j<=n4;j++)
         cout<<4;
      for (int j=1;j<=n5;j++)
         cout<<5;
      cout<<endl;
   }
   return 0;
}
