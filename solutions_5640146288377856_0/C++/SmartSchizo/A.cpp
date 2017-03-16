#include<stdio.h>

int N,M,W;

void solve(int t) {
  int i, j, c = 0, li, lj;
  scanf("%d %d %d",&N,&M,&W);
  for(i=1;i<=N;i++) {
    for(j=1;j<=M;j++) {
      if( (i+j-1)%W == 0 ) {
        c++;
        li = i;
        lj = j;
      }
    }
  }
  //printf("\n%d %d %d\n",c,li,lj);
  if(W>1) c += (1 < li) + (1<lj) + (li<N) + (lj<M) + W-2;
  printf("Case #%d: %d\n",t,c);
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}