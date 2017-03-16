#include<stdio.h>

int N;
char shy[100000];

void solve(int t) {
  int i, total, added = 0;
  scanf("%d %s",&N,shy);
  total = shy[0]-'0';
  for(i=1;i<=N;i++) {
    if(total < i) {
      total++;
      added++;
    }
    total += shy[i]-'0';
  }
  printf("Case #%d: %d\n",t,added);
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}