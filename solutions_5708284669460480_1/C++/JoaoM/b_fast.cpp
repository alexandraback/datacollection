#include <bits/stdc++.h>
#define MAX_N 7300
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;

int T, k, l, s;
char keys[MAX_N], target[MAX_N];
double ans, xp;
int mx, cr;
bool u[MAX_N][MAX_N];
double dp[MAX_N][MAX_N];
pii pre[MAX_N][MAX_N];
char suf[MAX_N];

int max_occurs(){ 
  for(int i = 0; i < l; i ++){
    bool ck = false;
    for(int j = 0; j < k; j ++)
      if(target[i] == keys[j])
        ck = true;
    if(!ck)
      return 0;
  }
  
  for(int i = 1; i < l; i ++){
    bool ck = true;
    for(int j = 0; i + j < l; j ++)
      if(target[i + j] != target[j])
        ck = false;
    if(ck){
      cr = l - i;
      return (1 + ((s - l) / i));
    }
  }

  cr = 0;
  return (s / l);
}

double exp_occurs(int px, int mt){
  if(px == s) return 0.0;
  if(!u[px][mt]){
    dp[px][mt] = 0.0;
    u[px][mt] = true;
    for(int i = 0; i < k; i ++){
      pii tr = pre[mt][i];      
      dp[px][mt] += (1.0 / k) * (tr.X + exp_occurs(px + 1, tr.Y));
    }
  }
  return dp[px][mt];
}

void precalc(){
  for(int i = 0; i < l; i ++){
    for(int j = 0; j < k; j ++){
      int po = (i == l - 1 && target[i] == keys[j]) ? 1 : 0;
      int nxt = 0;
      if(target[i] == keys[j]){
        nxt = i + 1;
        if(nxt == l)
          nxt = cr;
      }
      else{
        suf[i + 1] = 0;
        for(int r = 0; r < i; r ++)
          suf[r] = target[r];
        suf[i] = keys[j];
        
        for(int r = 1; r < i + 1; r ++){
          bool ck = true;
          for(int q = 0; r + q < i + 1; q ++)
            if(suf[r + q] != target[q])
              ck = false;
          if(ck){
            nxt = i - r + 1;
            break;
          }
        }
      }
      pre[i][j] = pii(po, nxt);
    }
  }
}

int main(){

  scanf("%d", &T);
  for(int ct = 1; ct <= T; ct ++){
    scanf("%d %d %d", &k, &l, &s); 
    scanf(" %s", keys);
    scanf(" %s", target);

    mx = max_occurs();

    memset(u, 0, sizeof u);
    precalc();
    xp = (mx == 0) ? 0.0 : exp_occurs(0, 0);

    ans = mx - xp;

    printf("Case #%d: %.17lf\n", ct, ans);
  }
  
  return 0;
}
