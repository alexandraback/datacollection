#include <iostream>
#include <string>
#include <map>
#include <vector>

std::map<std::string, int> fst, snd;
int mark1, mark2;
std::vector<int> vec1[1001];
int sel1[1001], sel2[1001];
bool visit[1001];

int max(int a, int b){ return a > b ? a : b; }

bool dfs(int now){
   for(int i=0, n=vec1[now].size(); i<n; ++i){
      int nxt = vec1[now][i];
      if(!visit[nxt]){
         visit[nxt] = true;
         if(sel2[nxt] == -1 || dfs(sel2[nxt])){
            sel1[now] = nxt;
            sel2[nxt] = now;
            return true;
         }
      }
   }
   return false;  
}

int match(int n, int m){
   int ret = 0;
   for(int i=0; i<n; ++i)
      sel1[i] = -1;
   for(int i=0; i<m; ++i)
      sel2[i] = -1;
   for(int i=0; i<n; ++i){
      for(int j=0; j<m; ++j)
         visit[j] = false;
      if(dfs(i))
         ret += 1;
   }
   return ret;
}

int main(){
   int T, n, ans;
   int val1, val2;
   std::string s1, s2;
   std::cin >> T;
   for(int t=1; t<=T; ++t){
      std::cout << "Case #" << t << ": ";
      std::cin >> n;
      fst.clear();
      snd.clear();
      mark1 = mark2 = 0;
      for(int i=0; i<1001; ++i)
         vec1[i].clear();
      for(int i=0; i<n; ++i){
         std::cin >> s1 >> s2;
         if(fst.find(s1) != fst.end())
            val1 = fst[s1];
         else
            val1 = fst[s1] = mark1++;
         if(snd.find(s2) != snd.end())
            val2 = snd[s2];
         else
            val2 = snd[s2] = mark2++;
         vec1[val1].push_back(val2);
      }
      std::cout << n - mark1 - mark2 + match(mark1, mark2) << std::endl;
   }

   return 0;
}
