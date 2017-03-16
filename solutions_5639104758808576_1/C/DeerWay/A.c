#include <stdio.h>
#define SMAX 1000
int main()
{
  int n, i, j, T, now, need;
  char s[SMAX+5];
  scanf("%d",&T);
  for(i=0;i<T;i++) {

    now = need = 0;
    scanf("%d%s",&n, s); 
    now = s[0]-'0';
    
    for(j=1;j<=n;j++){
      
      if( now < j ){
	need += j-now;
	now = j;
      }
      now += s[j]-'0';
    }
    printf("Case #%d: %d\n", i+1, need);
  }
  return 0;
} 
