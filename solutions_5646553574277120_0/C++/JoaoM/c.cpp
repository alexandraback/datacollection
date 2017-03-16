#include <bits/stdc++.h>
using namespace std;

int T, c, d, v;
int k[105], ans;
bool u[105];
int cnt;

int main(){

  scanf("%d", &T);
  for(int ct = 1; ct <= T; ct ++){
    scanf("%d %d %d", &c, &d, &v); 
    for(int i = 0; i < d; i ++)
      scanf("%d", &k[i]);

    memset(u, 0, sizeof u);
    u[0] = true;
    for(int i = 0; i < d; i ++)
      for(int j = v - k[i]; j >= 0; j --)
        if(u[j])
          u[j + k[i]] = true;

    cnt = 0;
    for(int i = 1; i <= v; i ++)
      if(u[i])
        cnt ++;

    ans = 0;
    while(cnt < v){
      ans ++;
      int mn = -1;
      for(int i = 1; i <= v; i ++)
        if(!u[i]){
          mn = i;
          break;
        }
      for(int j = v - mn; j >= 0; j --)
        if(u[j])
          u[j + mn] = true;

      cnt = 0;
      for(int i = 1; i <= v; i ++)
        if(u[i])
          cnt ++;
    }
    
    printf("Case #%d: %d\n", ct, ans);
  }
  
  return 0;
}
