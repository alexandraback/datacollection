#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> vec[101];
int map[101][101];

class CMP{
public:
   CMP(int i): _i(i) {}
   int _i;
   bool operator () (const std::vector<int>& x, const std::vector<int>& y){
      return x[_i] < y[_i];
   }
};

bool check(int s, int n, int missing){
   int idx;
   for(int i=0; i<n; ++i){
      if(((s>>i)&1) == 0) idx = 2*i;
      else idx = 2*i+1;
      if(idx > 2*missing) idx -= 1;
      for(int j=0; j<n; ++j)
         map[i][j] = vec[idx][j];
   }
   for(int i=0; i<n; ++i){
      if(((s>>i)&1) == 1) idx = 2*i;
      else idx = 2*i+1;
      if(idx == 2*missing+1) continue;
      if(idx > 2*missing) idx -= 1;
      for(int j=0; j<n; ++j){
         if(map[j][i] != vec[idx][j])
            return false;
      }
   }
   return true;
}

int main(){
   int T, n;
   int tmp;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      printf("Case #%d:", t);
      scanf("%d", &n);
      for(int i=0; i<2*n-1; ++i){
         vec[i].resize(n);
         for(int j=0; j<n; ++j){
            scanf("%d", &tmp);
            vec[i][j] = tmp;
         }
      }
      int offset = 0, missing = -1;
      for(int i=0; i<n; ++i){
         CMP cmp(i);
         std::sort(vec+offset, vec+2*n-1, cmp);
         if(offset == 2*n-2 || vec[offset][i] != vec[offset+1][i]){
            missing = offset / 2;
            offset += 1;
         }
         else{
            offset += 2;
         }
      }
      for(int s=0; s<(1<<n); ++s){
         if((s>>missing)&1) continue;
         if(check(s, n, missing)){
            for(int i=0; i<n; ++i)
               printf(" %d", map[i][missing]);
            break;
         }
      }
      printf("\n");
   }

   return 0;
}
