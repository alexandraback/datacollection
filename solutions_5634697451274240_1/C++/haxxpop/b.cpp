#include <stdio.h>
#include <string.h>
char s[1000];
int flip(int k){
  for(int i = 0 ; i <= k/2 ; i++ ){
    char tmp = s[i] ;
    s[i] = s[k-i];
    s[k-1] = tmp;
  }
  for(int i = 0 ; i <= k ; i++ ){
    if( s[i] == '+' ) s[i] = '-';
    else if(s[i] == '-') s[i] = '+';
  }
}
int main(){
  int t;
  scanf("%d",&t);
  for(int  e= 0 ; e < t ; e++ ){
    scanf("%s",s);
    int n = strlen(s);
    int ans = 0;
    for(int i = 0 ; i < n-1 ; i++ ){
      if( s[i] != s[i+1] ){
        flip(i);
        ans++;
      }
    }
    if( s[n-1] == '-' ){
      ans++;
      flip(n-1);
    }
    printf("Case #%d: %d\n",e+1,ans);
  }
}
