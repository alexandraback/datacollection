#include<stdio.h>

char pancake[10000];

void solve(int t) {
  int i, ans = 0;
  char c = '*';
  scanf("%s",pancake);
  
  for(i=0;pancake[i];i++) {
    if(c != pancake[i]) ans++;
    c = pancake[i];
  }
  ans -= c == '+';
  printf("Case #%d: %d\n",t,ans);
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}
