/*****************************************************************************
SPEAKING IN TONGUES
*****************************************************************************/
#include<stdio.h>
static char back_convert[26] = {'y', 'h', 'e', 's', 'o',    // a-e  
                                'c', 'v', 'x', 'd', 'u',    // f-j
                                'i', 'g', 'l', 'b', 'k',    // k-o
                                'r', 'z', 't', 'n', 'w',    // p-t
                                'j', 'p', 'f', 'm', 'a',    // u-y
                                'q'};
int main()
{
  int T;
  scanf("%d", &T);
  char c;
  c = getchar();
  int test_count = 1;
  while(T--) {
    printf("Case #%d: ", test_count++); 
    char c;
    while(((c = getchar()) != '\n') && (c != EOF)) {
      if(c >= 'a' && c <= 'z') {
        printf("%c", back_convert[(c-'a')]);
      } else {
        printf("%c", c);
      }
    }
    if( c == '\n') {
      printf("\n");
    } else {
      printf("%c",c);
    }
  }
}
