#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;
const int MAXN = 1100;
typedef vector<int> VI;
VI adj[MAXN];
int memo[MAXN];
int dest;
int doit(int u)
{

   int &ret = memo[u];

   if(u==dest) return 1;
   if(ret!=-1) return ret;
   ret = 0;
   for(int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      ret+=doit(v);
      if(ret >= 2) {
         ret=2;
         break;
      }
   }
   return ret;
}
int main()
{
   freopen("A-small-attempt0.in","r",stdin);
   freopen("A.out","w",stdout);
   int T;

   scanf("%d",&T);
   for(int tc = 1; tc <= T; tc++) {

int N;
       scanf("%d",&N);

       for(int i = 1; i <= N; i++) {
           adj[i].clear();
       }

       for(int i = 1; i <= N; i++) {
         int m;
         scanf("%d",&m);
         for(int j = 0; j < m; j++) {
            int v;
            scanf("%d",&v);
            adj[i].push_back(v);
         }
       }
       int ok = 0;
       for(int  i = 1; i <= N && ok == 0; i++) {
         memset(memo,-1,sizeof(memo));
         dest = i;
         int ret = 0;
         for(int j = 1; j <= N; j++) {
            int cur = doit(j);
            if(cur>=2) {
               //ret = 2;
               ok=1;
            }
         }
       }
       printf("Case #%d: ",tc);
       if(ok) {
         printf("Yes");
       }
       else printf("No");
       printf("\n");




   }

   return 0;
}
