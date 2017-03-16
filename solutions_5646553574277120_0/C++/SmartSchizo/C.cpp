#include<stdio.h>
#include<algorithm>

int C,D,V;
int A[100];

void solve(int t) {
  int i, j, k;
  scanf("%d %d %d",&C,&D,&V);
  for(i=0;i<D;i++) scanf("%d",A+i);
  
  std::sort(A,A+D);
  
  int coins = 0;
  long long last_sum = 0;
  i = 0;
  while(last_sum < V) {
    if(i >= D || A[i] > last_sum + 1) {
      coins ++; 
      last_sum += C*(last_sum+1);
    } else {
      while(i<D && A[i] <= last_sum+1) {
        last_sum += C * (long long)A[i];
        i++;
      }
    }
  }
  
  printf("Case #%d: %d\n",t,coins);
}

int main() {
  int t,T;
  //freopen("/Users/sushi/Downloads/C-small-attempt1.in","r",stdin);
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}
