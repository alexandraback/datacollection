#include <cstdio>

//                  abcdefghijklmnopqrstuvwxyz
const char *code = "yhesocvxduiglbkrztnwjpfmaq";

const int maxN = (int)1e5 + 10;

int n;
char s[maxN];

int main()
{
  scanf("%d ", &n);
  int t = 0;
  while (n--)
  {
    printf("Case #%d: ", ++t);
    gets(s);
    for (int i = 0; s[i]; i++)
      if (s[i] == ' ')
        putchar(s[i]);
      else 
        putchar(code[s[i] - 'a']);
    puts("");
  }
  return 0;
}
