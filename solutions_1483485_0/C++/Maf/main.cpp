#include <cstdio>
#include <cstring>
#include <ctype.h>

const char* A = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
  "de kr kd eoya kw aej tysr re ujdr lkgc jv"
  "yezq";

const char* B = "our language is impossible to understand"
  "there are twenty six factorial possibilities"
  "so it is okay if you want to just give up"
  "aoqz";

char trans[256];
char buffer[101];

int main(int argc, char *argv[])
{
  for (int i = 0; i < strlen(A); ++i) {
    char a = A[i];
    char b = B[i];
    trans[a] = b;
    a = toupper(a);
    b = toupper(b);
    trans[a] = b;
  }
  // for (int i = 'A'; i <= 'Z'; ++i) {
  //   printf("%c -> %c\n", i, trans[i]);
  // }
  int n;
  scanf("%d ", &n);
  for(int i=0; i<n; ++i) {
    gets(buffer);
    for (int j = 0; j < strlen(buffer); ++j) {
      buffer[j] = trans[buffer[j]];
    }
    printf("Case #%d: %s\n", i+1, buffer);
  }
  return 0;
}
