#include<stdio.h>
#include<algorithm>
using namespace std;

int A,N;
int sizes[1000];
void go(int t) {
  int i,j,k;
  scanf("%d %d",&A,&N);
  for(i=0;i<N;i++) scanf("%d",sizes+i);

  if(A==1) {
    printf("Case #%d: %d\n",t,N);
    return;
  }
  sort(sizes,sizes+N);
  
  int ans = N, sz, cur;
  for(i=0;i<ans;i++) {
    sz = A;
    cur = i;
    for(j=0;j<N-i;j++) {
      while(sz <= sizes[j]) {
        sz += sz-1;
        cur++;
      }
      sz += sizes[j];
    }
    if(cur < ans) ans = cur;
  }
  printf("Case #%d: %d\n",t,ans);
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) go(t);
  return 0;
}
