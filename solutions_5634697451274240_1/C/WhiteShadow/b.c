#include <stdio.h>
#include <string.h>

#define MAX_BUF 128

int main() {
  int n, c, i, count;
  char buf[MAX_BUF];

  scanf("%d", &n);
  for (c=1; c<=n; c++) {
    scanf("%s", buf);
    for (i=strlen(buf)-1,count=0; i>=0; i--)
      if ((buf[i]=='-' && count%2==0) || (buf[i]=='+' && count%2==1))
	count++;
    printf("Case #%d: %d\n", c, count);
  }
   
  return 0;
}
  
