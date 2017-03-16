#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <map>
#define pb push_back
#define MAXN 1001
#define MAXM 1
#define INF (1<<30)
#define PI 3.1415926535898
#define esp 10e-6
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
using namespace std;
int tot,ans,sum,N;
bool v1[MAXN],v2[MAXN];
class Point
{
      public:
             int x;
             int y;
}g[MAXN];


int a[1001],b[1001],n,v[1001];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while (T--)
    {
          int i,j,k,t;
          scanf("%d",&n);
          for (i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
          int s=0,ans=0;
          memset(v,0,sizeof(v));
          while (s<2*n)
          {
              k=-1;
              for (j=1;j<=n;j++)
                  if (v[j]==0 && s>=b[j])
                     k=j,t=1;
              if (k==-1)
              for (j=1;j<=n;j++)
                  if (v[j]==1 && s>=b[j])
                     k=j,t=2;
              if (k==-1)
              for (j=1;j<=n;j++)
                  if (v[j]==0 && s>=a[j])
                  {
                     t=3;
                     if (k==-1) k=j;
                     else if (b[j]>b[k]) k=j;
                  }
              if (k==-1) break;
              ans++;
              if (t==1 || t==2) v[k]=2;
              else v[k]=1;
              if (t==1) s+=2;
              else s++;
              //printf("s=%d k=%d t=%d\n",s,k,t);
          }
          printf("Case #%d: ",++cas);
          if (s<2*n) printf("Too Bad\n");
          else printf("%d\n",ans);
    }
    //system("pause");
}

