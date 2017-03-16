/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.04.14
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(t, tn)
  {
    printf("Case #%d: ", t + 1);

    int L, R, res = 0;;
    scanf("%d%d", &L, &R);
    for (int i = L; i <= R; i++)
    {
      char s[15];
      sprintf(s, "%d", i);
      int len = strlen(s);
      int T = 1;
      while (!(len % T == 0 && !strncmp(s, s + T, len - T)))
        T++;
      if (T * 2 > len)
        T = len;
      for (int i = 1; i < T; i++)
      {
        int x = 0;
        forn(j, len)
          x = x * 10 + (s[(i + j) % len] - '0');
        res += (L <= x && x <= R);
      }
    }
    printf("%d\n", res / 2);
  }
  return 0;
}
