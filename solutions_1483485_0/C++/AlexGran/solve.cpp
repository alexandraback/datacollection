#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxlen = 1001;

char abc[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

char s[maxlen];

int main (void)
{
  freopen ("in.txt", "rt", stdin);
  freopen ("out.txt", "wt", stdout);

  int tst_cnt;

  gets(s);

  sscanf(s, "%d", &tst_cnt);

  for (int tst_num = 0; tst_num < tst_cnt; tst_num++)
  {
    gets(s);

    printf("Case #%d: ", tst_num + 1);

    for (int i = 0; s[i] != 0; i++)
      if (s[i] != ' ')
        s[i] = abc[s[i] - 'a'];
    puts(s);
  }

  return 0;
}


