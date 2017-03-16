#include<stdio.h>
#include<stdlib.h>

int main() {

  int N, i;
  char c, map[26];

  map[0]  = 'y'; map[1]  = 'h'; map[2]  = 'e'; map[3]  = 's';
  map[4]  = 'o'; map[5]  = 'c'; map[6]  = 'v'; map[7]  = 'x';
  map[8]  = 'd'; map[9]  = 'u'; map[10] = 'i'; map[11] = 'g';
  map[12] = 'l'; map[13] = 'b'; map[14] = 'k'; map[15] = 'r';
  map[16] = 'z'; map[17] = 't'; map[18] = 'n'; map[19] = 'w';
  map[20] = 'j'; map[21] = 'p'; map[22] = 'f'; map[23] = 'm';
  map[24] = 'a'; map[25] = 'q';

  scanf("%d", &N);

  c = getchar();

  for(i=1; i<=N; i++) {
    printf("Case #%d: ", i);
    for(c=getchar(); c!='\n'; c=getchar()) {

      if ((c >= 'a') && (c <= 'z'))
        printf("%c", map[c - 'a']);
      else
        printf("%c", c);
    }
    printf("\n");
  }

  return 0;
}
