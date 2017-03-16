#include<stdio.h>

int N;

long long count(int N) {
  int i,digits[10];
  for(i=0;i<10;i++) digits[i] = 0;
  long long n = N, cnt = 1;
  while(1) {
    n = N * cnt;
    while(n) {
      digits[n%10] = 1;
      n/=10;
    }
    for(i=0;i<10;i++) if(!digits[i]) break;
    if(i==10) return cnt*N;
    cnt++;
  }
}

void solve(int t) {
  int i, total, added = 0;
  scanf("%d",&N);
  if(N > 0) 
    printf("Case #%d: %lld\n",t,count(N));
  else
    printf("Case #%d: INSOMNIA\n",t);
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}