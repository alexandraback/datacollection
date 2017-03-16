#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#define forup(i,a,b) for (int i=a;i<=b;i++)
#define fordown(i,a,b) for (int i=a;i>=b;--i)

using namespace std;

int T,n,m,a[101][101];

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&T);
    forup(uu,1,T)
    {
        printf("Case #%d: ",uu);
        scanf("%d%d",&n,&m);
        forup(i,1,n)
           forup(j,1,m) scanf("%d",&a[i][j]);
        bool ok=true;
        forup(i,1,n)
        {
           if (ok)
           forup(j,1,m)
           {
               bool can=true;
               forup(k,1,n) 
                  if (a[k][j]>a[i][j]) 
                  {
                     can=false;
                     break;
                  }
               if (can) continue;
               can=true;
               forup(k,1,m)
                  if (a[i][k]>a[i][j]) 
                  {
                     can=false;
                     break;
                  }
               if (can) continue;
               ok=false;
               break;
           }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
}
