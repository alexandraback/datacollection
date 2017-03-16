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
#define MAXN 1005
using namespace std;

int n,a[MAXN][MAXN];
int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("a3.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while (T--)
    {
          int x,y,i,j,k;
          scanf("%d",&n);
          memset(a,0,sizeof(a));
          
          for (i=1;i<=n;i++)
          {
              scanf("%d",&x);
		      for(j=1;j<=x;j++)
		      {
              scanf("%d",&y);
		      a[i][y]=1;
		      }
	     }
          x=0;
          for (k=1;k<=n && x==0;k++)
              for (i=1;i<=n && x==0;i++)
                  for (j=1;j<=n && x==0;j++)
                      if (i!=j && i!=k && j!=k)
                      {
                         if (a[i][k] && a[k][j])
        				  {
        					  a[i][j]++;
        					  if (a[i][j]>=2)
        					  {
                                 x=1; 
       						     break;
        					  }
        				  }
                      }
          printf("Case #%d: ",++cas);
          if (x) printf("Yes\n");
          else printf("No\n");
    }
    //system("pause");
}
