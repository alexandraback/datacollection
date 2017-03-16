#include<stdio.h>

int N,M;
int A[1000][1000];

int reduce() {
  int i,j,mn=100;
  for(i=0;i<N;i++) {
    for(j=0;j<M;j++) {
      if(A[i][j]<mn) mn=A[i][j];
    }
  }

  for(i=0;i<N;i++) {
    for(j=0;j<M;j++) {
      if(A[i][j]!=mn) break;
    }
    if(j==M) {
      N--;
      for(;i<N;i++) for(j=0;j<M;j++) A[i][j] = A[i+1][j];
      return 1;
    }
  }
  

  for(j=0;j<M;j++) {
    for(i=0;i<N;i++) {
      if(A[i][j]!=mn) break;
    }
    if(i==N) {
      M--;
      for(;j<M;j++) for(i=0;i<N;i++) A[i][j] = A[i][j+1];
      return 1;
    }
  }
  return 0;
}

void go(int t) {
  int i,j;
  scanf("%d %d",&N,&M);
  for(i=0;i<N;i++) {
    for(j=0;j<M;j++) {
      scanf("%d",&A[i][j]);
    }
  }
  while(reduce());
  if(N*M) printf("Case #%d: NO\n",t);
  else printf("Case #%d: YES\n",t);
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) go(t);
  return 0;
}
