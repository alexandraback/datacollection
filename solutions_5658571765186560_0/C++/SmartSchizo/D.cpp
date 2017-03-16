#include<stdio.h>

void solve(int t) {
  int N, a, b, w = 0;
  scanf("%d %d %d",&N,&a,&b);
  if((a*b)%N == 0) {
    if(N==1) w = 1;
    if(N==2) w = 1;
    if(N==3) w = (a*b >= 6);
    if(N==4) w = (a*b >= 12);
  }
  //printf("%d %d %d %d\n",N,a,b,w);
  if(w) printf("Case #%d: GABRIEL\n",t);
  else printf("Case #%d: RICHARD\n",t);
}

int main() {
  int t,T;
  //freopen("/Users/sushi/Downloads/C-small-attempt1.in","r",stdin);
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}
