#include <stdio.h>
#include <iostream>
#include <string>

std::string s, ans, tmp;

int main(){
   int T;
   std::string ans, t1, t2;
   int n;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      printf("Case #%d: ", t);
      std::cin >> s;
      n = s.size();
      ans = "";
      ans += s[0];
      for(int i=1; i<n; ++i){
         t1 = ans + s[i];
         t2 = s[i] + ans;
         if(t1 > t2)
            ans = t1;
         else
            ans = t2;
      }
      std::cout << ans << std::endl;
   }

   return 0;
}
