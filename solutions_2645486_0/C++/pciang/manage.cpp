#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#define DEBUG printf("TEST\n")

using namespace std;

int TC, itc;
int E, R, N, v[15], i;

int dfs(int n, int e){
   int ans = 0;
   if(n < N){
      for(int i = 0; i <= e; ++i){
         ans = max(ans, dfs(n + 1, min(E, e - i + R)) + v[n + 1] * i);
      }
   }
   return ans;
}

int main(){
   
   scanf("%d", &TC);
   for(itc = 1; itc <= TC; ++itc){
      scanf("%d %d %d", &E, &R, &N);
      for(i = 1; i <= N; ++i) scanf("%d", &v[i]);
      
      printf("Case #%d: %d\n", itc, dfs(0, E));
   }
   
   return 0;
}
