#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> fst, snd;
int mark1, mark2;
int val[1001][2];

int max(int a, int b){ return a > b ? a : b; }

int cnt_bit(unsigned s, int n){
   int ret = 0;
   for(int i=0; i<n; ++i){
      if((s>>i)&1) ret += 1;
   }
   return ret;
}

bool check(unsigned s, int n){
   bool rec1[1001] = {0}, rec2[1001] = {0};
   for(int i=0; i<n; ++i){
      if((s>>i)&1){
         rec1[val[i][0]] = true;
         rec2[val[i][1]] = true;
      }
   }
   for(int i=0; i<mark1; ++i)
      if(!rec1[i]) return false;
   for(int i=0; i<mark2; ++i)
      if(!rec2[i]) return false;
   return true;
}

int main(){
   int T, n, ans;
   std::string s1, s2;
   std::cin >> T;
   for(int t=1; t<=T; ++t){
      std::cout << "Case #" << t << ": ";
      std::cin >> n;
      fst.clear();
      snd.clear();
      mark1 = mark2 = 0;
      for(int i=0; i<n; ++i){
         std::cin >> s1 >> s2;
         if(fst.find(s1) != fst.end())
            val[i][0] = fst[s1];
         else
            val[i][0] = fst[s1] = mark1++;
         if(snd.find(s2) != snd.end())
            val[i][1] = snd[s2];
         else
            val[i][1] = snd[s2] = mark2++;
      }
      ans = 0;
      for(unsigned s=0; s<(1<<n); ++s){
         if(check(s, n))
            ans = max(ans, n - cnt_bit(s, n));
      }
      std::cout << ans << std::endl;
   }

   return 0;
}
