#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int g[55][55];
int main(){
   freopen("bs.in","r",stdin);
   freopen("bs.out","w",stdout);
   int t,b;
   uli m;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
      scanf("%d %lld",&b,&m);
      uli maxi=(1ll<<(b-2));
      if(m>maxi){
         printf("Case #%d: IMPOSSIBLE\n",tt);
         continue;
      }
      memset(g,0,sizeof g);
      int from=1;
      if(m==maxi)from=0;
      for(int i=from;i<b;i++){
         for(int j=i+1;j<b;j++){
            g[i][j]=1;
         }
      }
      if(m<maxi){
         for(int x=0;x<55;x++){
            if(m&(1ll<<x)){
               g[0][b-2-x]=1;
            }
         }
      }
      printf("Case #%d: POSSIBLE\n",tt);      
      for(int i=0;i<b;i++){
         for(int j=0;j<b;j++){
            printf("%d",g[i][j]);
         }
         printf("\n");
      }
   }
   return 0;
}
