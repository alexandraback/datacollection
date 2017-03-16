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

struct case1
{
   double l,r;
}rec[51][51];
struct case2
{
   int a,b,f;
   double t;
}p[1001];
bool f[101][65],va[51][51];
char a[51][5];
int s[51],pos[51];

bool cmp(case2 a,case2 b)
{
   return a.t<b.t||zero(a.t-b.t)&&a.f<b.f;
}

int main()
{
   freopen("c.in","r",stdin);
   freopen("c.out","w",stdout);
   int t,q;
   cin>>q;
   for (int t=1;t<=q;t++)
   {
      int n,tmp=0,o=0;
      double ans=oo;
      cin>>n;
      for (int i=1;i<=n;i++)
      {
         scanf("%s%d%d",a[i],&s[i],&pos[i]);
         if (a[i][0]=='R')
            tmp+=(1<<i-1);
      }
      memset(f,0,sizeof(f));
      f[0][tmp]=1;
      for (int i=1;i<n;i++)
         for (int j=i+1;j<=n;j++)
         {
            va[i][j]=va[j][i]=(pos[i]>pos[j]-5&&pos[i]<pos[j]+5);
            if (s[i]==s[j])
               continue;
            if (s[i]>s[j])
               rec[i][j]=(case1){1.*(pos[i]-pos[j]+5)/(s[j]-s[i]),1.*(pos[j]-pos[i]+5)/(s[i]-s[j])};
            else
               rec[i][j]=(case1){1.*(pos[j]-pos[i]+5)/(s[i]-s[j]),1.*(pos[i]-pos[j]+5)/(s[j]-s[i])};
            if (rec[i][j].l<rec[i][j].r-eps)
            {
               if (rec[i][j].l>-eps)
                  p[++o]=(case2){i,j,1,rec[i][j].l};
               if (rec[i][j].r>-eps)
                  p[++o]=(case2){i,j,0,rec[i][j].r};
            }
         }
      sort(p+1,p+o+1,cmp);
      for (int i=1;i<=o+1;i++)
      {
         int ss=0;
         tmp=0;
         for (int j=0;j<(1<<n);j++)
         {
            for (int k=1;k<n;k++)
               for (int l=k+1;l<=n;l++)
                  if (va[k][l]&&!(j&(1<<k-1))==!(j&(1<<l-1)))
                     f[i-1][j]=0;
            ss+=f[i-1][j];
         }
         if (!ss)
         {
            ans=p[i-1].t;
            goto end;
         }
         for (int j=1;j<=n;j++)
         {
            tmp+=(1<<j-1);
            for (int k=1;k<=n;k++)
               if (va[j][k])
               {
                  tmp-=(1<<j-1);
                  break;
               }
         }
         for (int j=0;j<(1<<n);j++)
            for (int k=tmp;;k=((k-1)&tmp))
            {
               f[i][j^k]|=f[i-1][j];
               if (!k)
                  break;
            }
         va[p[i].a][p[i].b]=va[p[i].b][p[i].a]=p[i].f;
      }
      end:
      printf("Case #%d: ",t);
      if (ans>oo/2)
         puts("Possible");
      else
         printf("%.12lf\n",ans);
   }
   return 0;
}
