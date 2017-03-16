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

char mat[55][55];

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int q;
   cin>>q;
   for (int t=1;t<=q;t++)
   {
      printf("Case #%d:\n",t);
      int n,m,x;
      cin>>n>>m>>x;
      memset(mat,0,sizeof(mat));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            mat[i][j]='*';
      x=n*m-x;
      if (x>1)
         if (min(n,m)>2)
         {
            if (x==2||x==3||x==5||x==7)
            {
               printf("Impossible\n");
               goto end;
            }
            int s=4;
            mat[1][1]=mat[1][2]=mat[2][1]=mat[2][2]='.';
            if (x==4)
               goto out;
            mat[3][1]=mat[3][2]='.';
            if (x==6)
               goto out;
            mat[1][3]=mat[2][3]='.';
            x-=8;
            for (int i=4;i<=n&&x-2>=0;i++)
            {
               x-=2;
               mat[i][1]=mat[i][2]='.';
            }
            for (int i=4;i<=m&&x-2>=0;i++)
            {
               x-=2;
               mat[1][i]=mat[2][i]='.';
            }
            for (int i=3;i<=n&&x-1>=0;i++)
               for (int j=3;j<=m&&x-1>=0;j++)
               {
                  x--;
                  mat[i][j]='.';
               }
         }
         else if (n==1)
            for (int i=1;i<=x;i++)
               mat[1][i]='.';
         else if (m==1)
            for (int i=1;i<=x;i++)
               mat[i][1]='.';
         else if (n==2)
         {
            if (x==2||x%2==1)
            {
               printf("Impossible\n");
               goto end;
            }
            for (int i=1;i*2<=x;i++)
               mat[1][i]=mat[2][i]='.';
         }
         else
         {
            if (x==2||x%2==1)
            {
               printf("Impossible\n");
               goto end;
            }
            for (int i=1;i*2<=x;i++)
               mat[i][1]=mat[i][2]='.';
         }
      out:
      mat[1][1]='c';
      for (int i=1;i<=n;i++)
         puts(mat[i]+1);
      end:;
   }
   return 0;
}
