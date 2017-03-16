#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
int x[110][110];
int main()
{
 freopen("b.in","r",stdin);
 freopen("b.out","w",stdout);
 int p,t;scanf("%d",&t);
 for(p=1;p<=t;p++)
 {printf("Case #%d: ",p);
  bool otv=1;int n,m,i,f,g;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++){for(f=0;f<m;f++){scanf("%d",&x[i][f]);}}
  for(i=0;i<n;i++)
  {
   for(f=0;f<m;f++)
   {bool log;
    log=1;for(g=0;g<n;g++){if(x[g][f]>x[i][f]){log=0;break;}}if(log){continue;}
    log=1;for(g=0;g<m;g++){if(x[i][g]>x[i][f]){log=0;break;}}if(log){continue;}
    otv=0;
   }
  }
  if(otv){printf("YES\n");}else{printf("NO\n");}
 }
}