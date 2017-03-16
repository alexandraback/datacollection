#include<stdio.h>
#include<algorithm>

int N, BFF[100000], usd[100000], best[10000];

void solve(int t) {
  int i, j;
  scanf("%d",&N);
  for(i=0;i<N;i++) {
    scanf("%d",BFF+i);
    BFF[i]--;
    best[i] = 0;
  }
  
  int V = 1, a, mx = 0, sum = 0;
  for(i=0;i<N;i++) {
    for(j=0;j<N;j++) usd[j] = 0;
    a = i;
    for(j=1;!usd[a];j++) {
      usd[a] = j;
      a = BFF[a];
    }
    if(mx < j - usd[a]) mx = j - usd[a];
    if(j-usd[a] == 2 && usd[a] > best[a]) best[a] = usd[a];
  }
  for(i=0;i<N;i++) sum += best[i];
  printf("Case #%d: %d\n",t, std::max(mx,sum));
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}
