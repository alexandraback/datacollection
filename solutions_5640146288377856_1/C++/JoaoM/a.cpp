#include <bits/stdc++.h>
using namespace std;

int T, r, c, w;
int ans;

int solve_f(){
  return (c / w);
}

int solve_t(){
  int res = c / w;
  res += w - 1;
  if(w > 1 && (c % w) != 0)
    res ++;
  return res;
}

int main(){

  scanf("%d", &T);
  for(int ct = 1; ct <= T; ct ++){
    scanf("%d %d %d", &r, &c, &w); 
    ans = solve_f() * (r - 1) + solve_t();
    //printf("t: %d %d\n", solve_f(), solve_t());
    printf("Case #%d: %d\n", ct, ans);
  }
  
  return 0;
}
