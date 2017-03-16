#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int cases;
  scanf("%d", &cases);

  char *buffer = (char *)malloc(1000010);

  for(int caseno = 0;caseno < cases;caseno++) {
    int n;
    scanf("%s %d", buffer, &n);
    int len = strlen(buffer);
    int first = -1;
    int lastVow = -1;
    long long total = 0;
    for(int i = 0;i<len;i++) {
      switch(buffer[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
	lastVow = i;
	break;
      default:
	if (i - lastVow >= n) {
	  for (int j = first;j<i-n+1;j++)
	    total += len - i;
	  first = i - n + 1;
	}
      }
    }

    printf("Case #%d: %lld\n", caseno+1, total);
  }
}
