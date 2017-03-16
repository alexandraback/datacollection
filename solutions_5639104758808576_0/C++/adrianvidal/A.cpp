#include<bits/stdc++.h>
using namespace std;
char s[1010];

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int n; scanf("%d",&n);
      scanf("%s",s);
      
      int curr = 0;
      int extra = 0;
      for(int i=0; i<=n; i++){
         if (curr < i){
            extra += i - curr;
            curr += i - curr;
         }
         curr += s[i] - '0';
      }
      printf("Case #%d: %d\n",cs+1,extra);
   }
}