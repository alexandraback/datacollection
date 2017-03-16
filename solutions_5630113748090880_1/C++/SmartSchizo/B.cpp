#include<stdio.h>

int usd[ 100000 ];

void solve(int t) {
  int i, a, N;
  scanf("%d",&N);
  for(i=N;i<2*N*N;i++) {
    scanf("%d",&a); 
    if(usd[a] == t) usd[a] = 0;
    else usd[a] = t;
  }
  
  printf("Case #%d:",t);
  for(i=1;i<=2500;i++) {
    if(usd[i] == t)
    printf(" %d",i);
  }
  printf("\n");
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}
