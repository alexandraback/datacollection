#include<stdio.h>

#define M 201
#define TEST(n,x) if(!(x)) printf("ERROOOOOOOOOOOOOOOOR %d\n",n);
int A[500][500];
int C[500][500];
int type[500];
int tot[500];
int order[500];
int usd[500];
int N;

void dfs(int n) {
  int i;
  if(usd[n]) return;
  usd[n] = 1;
  for(i=0;i<M;i++) if(A[n][i]) dfs(i);
}

int check() {
  int i,j, cnt;
  
  //check incoming
  for(i=0;i<M;i++) {
    cnt = 0;
    for(j=0;j<M;j++) cnt += A[j][i];
    if(cnt < tot[i]) return 0;
  }
  for(i=0;i<M;i++) usd[i] = 0;
  dfs(0);
  for(i=0;i<M;i++) if(!usd[i] && tot[i] > 0) return 0;
  return 1;
}

void go(int t) {
  int i,j,k,c,ci;
  scanf("%d %d",&k,&N);

  for(i=0;i<500;i++) {
    type[i]=0;
    tot[i]=0;
    order[i] = 0;
    for(j=0;j<500;j++) A[i][j] = 0;
  }
  
  for(i=0;i<k;i++) {
    scanf("%d",&c);
    A[0][c]++;
  }
  for(i=0;i<N;i++) {
    scanf("%d %d",&type[i],&k);
    tot[ type[i] ]++;
    for(j=0;j<k;j++) {
      scanf("%d",&C[i][j]);
      A[ type[i] ][ C[i][j] ]++;
    }
    C[i][k] = -1;
  }
  if(!check()) {
    printf("Case #%d: IMPOSSIBLE\n",t);
    return;
  }
  printf("Case #%d:",t);
  for(k=0;k<N;k++) {
    for(i=0;i<N;i++) {
      if(type[i]<0 || A[0][ type[i] ] <= 0) continue;
      

      A[ 0 ][ type[i] ]--;
      TEST( 2, A[ 0 ][ type[i] ] >= 0);
      tot[ type[i] ]--;
      TEST( 3, tot[ type[i] ] >= 0);
      order[k] = i;
      
      for(j=0;C[i][j]>0;j++) {
        A[ type[i] ][ C[i][j] ]--;
        TEST( 1, A[ type[i] ][ C[i][j] ] >= 0);
        A[ 0 ][ C[i][j] ]++;
      }
      
      if(check()) {
        type[i] = -1;
        break;
      }
      order[k] = -1;
      tot[ type[i] ]++;
      A[ 0 ][ type[i] ]++;
      for(j=0;C[i][j]>0;j++) {
        A[ type[i] ][ C[i][j] ]++;
        A[ 0 ][ C[i][j] ]--;
      }
    }
    printf(" %d",order[k]+1);
  }
  printf("\n");
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) go(t);
  return 0;
}
