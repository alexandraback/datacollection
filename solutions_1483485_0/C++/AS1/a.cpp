#include <cstdio>
#include <cassert>
#include <string>
using namespace std;
string from  = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
string to    = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
int ne[256];
int main (void) {
  for (int i = 0; i < (int)from.size();i++) {
    ne[from[i]] = to[i]; 
  }
  ne['q'] = 'z';
  ne['z'] = 'q';
  for (int i = 'a'; i <= 'z'; i++) {
    if (!ne[i]) {
      fprintf (stderr, "no translation:%c\n", i);
    } else {
      fprintf (stderr, "%c->%c\n", i, ne[i]);
    }
  }
  int line_n;
  scanf ("%d", &line_n);
  while (getc(stdin) != '\n');
  char buf[110];
  for (int tt = 1; tt <= line_n; tt++) {
    printf ("Case #%d: ", tt);
    gets(buf);
    for (int i = 0; buf[i]; i++) {
      buf[i] = ne[buf[i]];
      assert (buf[i]);
    }
    puts (buf);
  }
  return 0;
}