#include<stdio.h>

int A[1000000];
void solve(int t) {
  int i, h, N;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",A+i);
  
  int num = 0, best = 100000000;
  
  for(h=1;h<=1000;h++) {
    num = h;
    for(i=0;i<N;i++) num += (A[i]-1)/h;
    if(num < best) best = num;
  }
  printf("Case #%d: %d\n",t,best);
}

int main() {
  int t,T;
  //freopen("/Users/sushi/Downloads/C-small-attempt1.in","r",stdin);
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}
