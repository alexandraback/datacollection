#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char abc[20][200];
int v[20] = {0};
int re[20], n;
int A(int t){
  int i, j,ans = 0;
  if(t == n){
    int num[30] = {0};
    char s[4000] = "";
    for(i = 0; i < n; i++)
      strcat(s, abc[re[i]]);
    //printf("%s \n", s);
    int len = strlen(s);
    char tmp;
    tmp = s[0];
    num[s[0]-'a'] = 1;
    for(j = 1; j < len; j++){
      if(tmp == s[j]) continue;
      else tmp = s[j];
      if(num[tmp - 'a'] == 1) return 0;
      num[s[j]-'a'] = 1;
    }
    return 1;
  }
  for(i = 0; i < n; i++){
    if(v[i] != 1){
      v[i] = 1;
      re[t] = i;
      ans += A(t+1);
      v[i] = 0;
    }
  }
  return ans % 1000000007;
}
int main(){
  int t, T;
  scanf("%d", &t);
  for(T = 1; T <= t; T++){
    int i, j, ans;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
      scanf("%s", abc[i]);
    ans = A(0) % 1000000007;
    printf("Case #%d: %d\n", T, ans);
  }
  return 0;
}