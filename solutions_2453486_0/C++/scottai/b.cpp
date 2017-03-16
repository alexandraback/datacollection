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

string a[4];

bool ok1(int x,int y)
{
   return a[x][y]=='X'||a[x][y]=='T';
}

bool ok2(int x,int y)
{
   return a[x][y]=='O'||a[x][y]=='T';
}

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int q;
   cin>>q;
   for (int tt=1;tt<=q;tt++)
   {
      bool f1=0,f2=0;
      int s=0;
      for (int i=0;i<4;i++)
      {
         cin>>a[i];
         for (int j=0;j<4;j++)
            s+=(a[i][j]!='.');
      }
      for (int i=0;i<4;i++)
      {
         if (ok1(i,0)&&ok1(i,1)&&ok1(i,2)&&ok1(i,3)||ok1(0,i)&&ok1(1,i)&&ok1(2,i)&&ok1(3,i))
            f1=1;
         if (ok2(i,0)&&ok2(i,1)&&ok2(i,2)&&ok2(i,3)||ok2(0,i)&&ok2(1,i)&&ok2(2,i)&&ok2(3,i))
            f2=1;
      }
      if (ok1(0,0)&&ok1(1,1)&&ok1(2,2)&&ok1(3,3)||ok1(0,3)&&ok1(1,2)&&ok1(2,1)&&ok1(3,0))
         f1=1;
      if (ok2(0,0)&&ok2(1,1)&&ok2(2,2)&&ok2(3,3)||ok2(0,3)&&ok2(1,2)&&ok2(2,1)&&ok2(3,0))
         f2=1;
      if (f1)
         printf("Case #%d: X won\n",tt);
      else if (f2)
         printf("Case #%d: O won\n",tt);
      else if (s==16)
         printf("Case #%d: Draw\n",tt);
      else
         printf("Case #%d: Game has not completed\n",tt);
   }
   return 0;
}
