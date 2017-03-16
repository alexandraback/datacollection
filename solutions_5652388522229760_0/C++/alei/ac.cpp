#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int main(){
   freopen("ac.in","r",stdin);
   freopen("ac.out","w",stdout);
   int t;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
      uli n;
      scanf("%lld",&n);
      if(n==0){
         printf("Case #%d: INSOMNIA\n",tt);
         continue;
      }
      int b=0;
      uli x=0;
      while(b!=(1<<10)-1){         
         x+=n;
         assert(x<(1e15));
         for(uli y=x;y!=0;y/=10){
            uli dig=y%10;
            b|=(1<<dig);
         }
      }
      printf("Case #%d: %lld\n",tt,x);
   }
   return 0;
}

