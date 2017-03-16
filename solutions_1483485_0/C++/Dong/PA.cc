#include <stdio.h>

char mapping[256];

int main()
{
  mapping['a'] = 'y';
  mapping['b'] = 'h';
  mapping['c'] = 'e';
  mapping['d'] = 's';
  mapping['e'] = 'o';
  mapping['f'] = 'c';
  mapping['g'] = 'v';
  mapping['h'] = 'x';
  mapping['i'] = 'd';
  mapping['j'] = 'u';
  mapping['k'] = 'i';
  mapping['l'] = 'g';
  mapping['m'] = 'l';
  mapping['n'] = 'b';
  mapping['o'] = 'k';
  mapping['p'] = 'r';
  mapping['q'] = 'z';
  mapping['r'] = 't';
  mapping['s'] = 'n';
  mapping['t'] = 'w';
  mapping['u'] = 'j';
  mapping['v'] = 'p';
  mapping['w'] = 'f';
  mapping['x'] = 'm';
  mapping['y'] = 'a';
  mapping['z'] = 'q';

  int ntc;
  char line[200];

  scanf("%d", &ntc);
  gets(line);
  for (int tc = 0; tc < ntc;) {
    gets(line);
    printf("Case #%d: ", ++tc);
    for (char *p = line; *p; ++p)
      if (*p == ' ') putchar(' ');
      else putchar(mapping[*p]);
    putchar('\n');
  }

  return 0;
}
