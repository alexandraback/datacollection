/*       GCJ - Speaking in Tongues       */
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const char replace[]
  = "yhesocvxduiglbkrztnwjpfmaq";

void process(void);

int main(void) {
  process();
  return 0;
}

void process(void) {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf(" ");
    char str[200]; gets(str);
    for (int j = strlen(str)-1; j >= 0; j--)
      if (isupper(str[j]))
        str[j] = replace[str[j] - 'A'] - 'a' + 'A';
      else if (islower(str[j]))
        str[j] = replace[str[j] - 'a'];
    printf("Case #%d: ", i);puts(str);
  }
}