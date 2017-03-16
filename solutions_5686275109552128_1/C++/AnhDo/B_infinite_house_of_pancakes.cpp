#include <iostream>
#include <stdio.h>

int solve(int a[], int n){
  int result = 1000+5;
  for(int i = 1; i < 1000+1; i++){
    int tmp = 0;
    for(int j = 0; j < n; j++){
      tmp += (a[j] + i-1)/i - 1;
    }
    if(tmp+i < result)result = tmp+i;
  }
  return result;
}
int main(){
  freopen("B-large.in","r",stdin);
  freopen("output.txt","w",stdout);
  int T, n, d, a[1000+5];
  scanf("%d",&T);
  for(int t = 1; t <= T; t++){
    scanf("%d",&d);
    for(int j = 0; j < d; j++)scanf("%d",&a[j]);
    printf("Case #%d: %d\n",t, solve(a,d));
  }
  return 0;
}