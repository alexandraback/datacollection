#include<bits/stdc++.h>
using namespace std;

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int x,r,c; scanf("%d%d%d",&x,&r,&c);
      if (x == 1){
         printf("Case #%d: GABRIEL\n",cs+1);
      }
      else if (x == 2){
         if ((r*c)%2==0) printf("Case #%d: GABRIEL\n",cs+1);
         else printf("Case #%d: RICHARD\n",cs+1);
      }
      else if (x == 3){
         if ((r*c)%3 != 0) printf("Case #%d: RICHARD\n",cs+1);
         else if (min(r,c) == 1) printf("Case #%d: RICHARD\n",cs+1);
         else printf("Case #%d: GABRIEL\n",cs+1);
      }
      else if (x == 4){
         if ((r*c)%4 != 0) printf("Case #%d: RICHARD\n",cs+1);
         else if (min(r,c) == 1) printf("Case #%d: RICHARD\n",cs+1);
         else if (max(r,c) == 2) printf("Case #%d: RICHARD\n",cs+1);
         else if (min(r,c) == 2 && max(r,c) == 4) printf("Case #%d: RICHARD\n",cs+1);
         else printf("Case #%d: GABRIEL\n",cs+1);
      }
   }
}