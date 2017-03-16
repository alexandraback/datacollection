#include <bits/stdc++.h>
#define MAX_N 7300
using namespace std;

int T, k, l, s;
char keys[MAX_N], target[MAX_N];
double ans;

int cnt[MAX_N], mx, tot;
char cur[MAX_N];

int count_occur(){
  int res = 0;
  for(int i = 0; i + l - 1 < s; i ++){
    bool ck = true;
    for(int j = 0; j < l; j ++)
      if(cur[i + j] != target[j])
        ck = false;
    if(ck)
      res ++;
  }
  return res;
}

void dfs(int px){
  if(px == s){
    int cc = count_occur();
    mx = max(mx, cc);
    cnt[cc] ++;
    tot ++;
    return;
  }
  for(int i = 0; i < k; i ++){
    cur[px] = keys[i];
    dfs(px + 1);
  }
}

int main(){

  scanf("%d", &T);
  for(int ct = 1; ct <= T; ct ++){
    scanf("%d %d %d", &k, &l, &s); 
    scanf(" %s", keys);
    scanf(" %s", target);

    mx = tot = 0;
    cur[s] = 0;
    memset(cnt, 0, sizeof cnt);
    dfs(0);

    double exp = 0.0;
    for(int i = 1; i <= mx; i ++)
      exp += i * (cnt[i] * 1.0 / tot);
    ans = mx - exp;
        
    printf("Case #%d: %lf\n", ct, ans);
  }
  
  return 0;
}
