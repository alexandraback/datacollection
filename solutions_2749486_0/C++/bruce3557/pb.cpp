#include <stdio.h>
#include <string.h>

char ans[510];

int main() {
  int t, kas=0;
  
  scanf("%d", &t);
  while(t--) {
    int x, y;
    scanf("%d%d", &x, &y);
    
    int ct = 0;
    if(x > 0) {
      for(int i=0;i<x;++i) {
        ans[ct++] = 'W';
        ans[ct++] = 'E';
      }
    } else if(x < 0) {
      for(int i=0;i<-x;++i) {
        ans[ct++] = 'E';
        ans[ct++] = 'W';
      }
    }

    if(y > 0) {
      for(int i=0;i<y;++i) {
        ans[ct++] = 'S';
        ans[ct++] = 'N';
      }
    } else if(y < 0) {
      for(int i=0;i<-y;++i) {
        ans[ct++] = 'N';
        ans[ct++] = 'S';
      }
    }
    ans[ct] = '\0';
    printf("Case #%d: %s\n", ++kas, ans);
  }

  return 0;
}

