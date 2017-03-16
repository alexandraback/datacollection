#include <stdio.h>
#define MAX 1100

int main () {
  int teste;
  scanf ("%d", &teste);
  for (int t = 0; t < teste; t++) {
    int ns;
    scanf ("%d", &ns);
    int ret = 0;
    int np = 0;
    for (int i = 0; i <= ns; i++) {
      char c;
      scanf (" %c", &c);
      int now = c - '0';
      if (now > 0) {
	if (np < i) {
	  ret += i - np;
	  np = i;
	}
      }
      np += now;
    }
    printf ("Case #%d: %d\n", t + 1, ret);
  }
  return 0;
}
