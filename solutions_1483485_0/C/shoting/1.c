#include <stdio.h>
#include <string.h>

/* a b c d e f g h i j k l m n o p q r s t u v w x y z
   y h e s o c v x d u i g l b k r z t n w j p f m a q */

char mapping[26] = {
'y', 'h', 'e', 's', 'o', 'c', 'v', 'x' ,'d', 'u', 'i' ,'g' ,'l' ,'b' ,'k' ,'r' ,'z' ,'t' ,'n' ,'w' ,'j' ,'p' ,'f' ,'m' ,'a', 'q' };


int main() {
	int i, j, t;
    char tmp;
	scanf("%d\n", &t);
	for (i = 0 ; i < t ; ++i) {
	  printf("Case #%d: ", i + 1);
	  while (scanf("%c", &tmp)) {
		if (tmp == ' ')  {
		  printf(" ");
		} else if (tmp == '\n') {
		  break;
		} else {
		  printf("%c", mapping[tmp - 'a']);
		}
	  }
	  printf("\n");
	}

    return 0;
}
