#include <stdio.h>

int main(){
  int jcase;
  long long r, t;
  long long ans;
  
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  //freopen("A-large.in", "r", stdin);
  scanf("%d", &jcase);
  
  for(int icase=0; icase<jcase; icase++){
    scanf("%lld %lld", &r, &t);
    r *= 2;
    r++;
    
    ans = 0;
    while(t >= r){
      ans++;
      t -= r;
      r += 4;
    }
    
    printf("Case #%d: %lld\n", icase+1, ans);
  }
  return 0;
}
