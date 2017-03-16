#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define INF (1<<30)
#define MAXN 2005
using namespace std;

int T,cas=0;
int N,A;
double x[MAXN],t[MAXN],a[MAXN],d,v[MAXN];
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d",&T);
    while (T--)
    {
          int i,j;
          scanf("%lf%d%d",&d,&N,&A);
          printf("Case #%d:\n",++cas);
          x[0]=t[0]=0;
          for (i=1;i<=N;i++) scanf("%lf%lf",&t[i],&x[i]) , v[i]=(x[i]-x[i-1])/(t[i]-t[i-1]);
          for (i=1;i<=A;i++)
          {
              scanf("%lf",&a[i]);
              double v0=0,ans=0,s=0,tt;
              for (j=1;j<=N;j++)
              {
                  double l,r,mid;
                  l=0;r=t[i];
                  for (int yy=1;yy<=100;yy++)
                  {
                      mid=(l+r)/2;
                      if ( s+v0*mid+0.5*a[i]*mid*mid<=x[j-1]+v[j]*mid && x[j-1]+v[j]*mid>=d)
                         l=mid , tt=mid;
                      else
                         r=mid , tt=mid;
                  }
                  v0=v0+a[i]*tt;
                  ans+=tt;
                  s=s+v0*mid+0.5*a[i]*mid*mid;
              }
              printf("%.6lf\n",ans);
          }
    }
    //system("pause");
}
