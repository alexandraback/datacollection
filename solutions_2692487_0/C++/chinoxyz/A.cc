#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int T;
int A, N;
int m;
vector <int> v;
int s[109][10000];
int dp(int k, int a){
  //printf("%d %d\n", k,a);
  if(k >=  N) return 0;
  int res = 0;
  if(s[k][a] != -1) return s[k][a];
  if(a > v[k]){ 
    res = dp(k+1, a+ v[k]);
  }else{
    if(a <= 1){
      res = dp(k+1, a) +1;
    }else{
      res = min(dp(k+1, a)+1, dp(k, a+ a-1)+1);
    }
  }
  s[k][a] = res;
  return res;
}

int main(){
  scanf("%d", &T);
  for(int t = 0; t < T; t++){
    scanf("%d %d", &A, &N);
    memset(s, -1, sizeof(s));
    v.clear();
    for(int i = 0; i < N; i++){
      scanf("%d", &m);
      v.push_back(m);
    }
    sort(v.begin(), v.end());
    printf("Case #%d: %d\n", t+1, dp(0, A));
  
  }
}
