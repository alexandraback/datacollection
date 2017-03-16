#include <cstdio>

int main(){
  int numTC, TC = 1, arr[1001], S, ans, sum;
  char c;
  scanf("%d", &numTC);
  while(numTC--){
    scanf("%d%*c", &S);
    for(int i=0; i<=S; i++){ scanf("%c", &c); arr[i] = c-'0'; }
    if(S<1){ printf("Case #%d: 0\n", TC++); continue; }
    ans = 0; sum = arr[0];
    for(int i=1; i<=S; i++){
      if(arr[i]>0 && sum<i){ ans+=i-sum; sum = i; }
      sum+=arr[i];
    }
    printf("Case #%d: %d\n", TC++, ans);
  }
  return 0;
}
