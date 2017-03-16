#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

char input[] = 
 "ejp mysljylc kd kxveddknmc re jsicpdrysi\
 rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
 de kr kd eoya kw aej tysr re ujdr lkgc jv";

char output[] =
"our language is impossible to understand\
 there are twenty six factorial possibilities\
 so it is okay if you want to just give up";

char map[256];
bool used[256];

int main() {
  int n = strlen(input);
  assert(n == strlen(output));
  map['a'] = 'y';
  map['o'] = 'e';
  map['z'] = 'q';
  for (int i = 0; i < n; ++i)
    map[input[i]] = output[i];
  for (char l = 'a'; l <= 'z'; ++l)
    used[map[l]] = true;

  char unused = 0;
  for (char l = 'a'; l <= 'z'; ++l)
    if (!used[l]) {
      unused = l;
   //   printf("unused %c\n", l);
    }
  for (char l = 'a'; l <= 'z'; ++l) {
    if (!isalpha(map[l])) {
 //     printf("unknown %c; mapping to %c\n", l,  unused);
      map[l] = unused;
    }
  }

  map[' '] = ' ';
  map['\n'] = '\n';

  int cases;
  scanf("%i\n", &cases);
  for (int ncase = 1; ncase <= cases; ++ncase) {
    char text[200];
    gets(text);
    printf("Case #%i: ", ncase);
    for (int i = 0; text[i]; ++i)
      putchar(map[text[i]]);
    puts("");
  }
  return 0;
}
