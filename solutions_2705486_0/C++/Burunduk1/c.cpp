/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.05.04
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 522000;
const int LEN = 11;
const int sLen = 4000 + LEN;
const int M = 5;

char s[sLen + 1];
char w[N][LEN + 1];
int wn, mlen, n, p[N];
int f[N][M];

inline bool pless( int i, int j )
{
  return strcmp(w[i], w[j]) < 0;
}

inline void relax( int i, int last, int F )
{
  int j = min(i - last - 1, 4);
  //printf("relax i = %d, j = %d : %d\n", i, j, F);
  f[i][j] = min(f[i][j], F);
}

int main()
{
  FILE *F = fopen("garbled_email_dictionary.txt", "rt");
  while (fscanf(F, "%s", w[wn]) == 1)
  {
    mlen = max(mlen, (int)strlen(w[wn]));
    p[wn] = wn;
    wn++;
  }
  assert(wn <= N && mlen <= LEN);
  fprintf(stderr, "wn = %d, mlen = %d\n", wn, mlen);
    
  forn(i, wn - 1)
    assert(pless(p[i], p[i + 1]));
  //sort(p, p + wn, pless);

  int tn;
  scanf("%d", &tn);
  forn(tt, tn)
  {
    fprintf(stderr, "Case #%d\n", tt + 1);
    printf("Case #%d: ", tt + 1);
    scanf("%s", s);
    n = strlen(s);
    memset(f, 0x10, sizeof(f));
    f[0][4] = 0;
    forn(i, n)
      for (int len = 1; len <= mlen && i + len <= n; len++)
      {
        memcpy(w[wn], s + i, len);
        //printf("----> try i = %d, s = %s\n", i, w[wn]);
        w[wn][len] = 0;
        //printf("i = %d, len = %d\n", i, len);
        forn(j, M)
          if (f[i][j] < n)
          {
            //printf("i = %d, len = %d, j = %d [%d <= %d && %d + %d <= %d]\n", i, len, j, len, mlen, i, len, n);
            int last = i - j - 1, F = f[i][j];

            #define DO_IT(last, add) \
            { \
              int pos = lower_bound(p, p + wn, wn, pless) - p; \
              if (pos < wn && !strcmp(w[wn], w[p[pos]])) { \
                relax(i + len, last, F + add); } \
            }
            // if (add == 0) printf("i = %d, use %s = %s, add = %d + %d\n", i, w[wn], w[p[pos]], f[i][j], add); 
            DO_IT(last, 0)
            forn(t, len)
              if (t + j + 1 >= 5)
                forn(x, 26)
                {
                  char ch = x + 'a';
                  swap(ch, w[wn][t]);
                  DO_IT(i + t, 1)
                  swap(ch, w[wn][t]);
                }
            forn(t1, len)
              forn(t2, t1)
                if (t2 + j + 1 >= 5 && t1 - t2 >= 5)
                  forn(x1, 26)
                    forn(x2, 26)
                    {
                      char ch1 = x1 + 'a';
                      char ch2 = x2 + 'a';
                      swap(ch1, w[wn][t1]);
                      swap(ch2, w[wn][t2]);
                      DO_IT(i + t1, 2)
                      swap(ch1, w[wn][t1]);
                      swap(ch2, w[wn][t2]);
                    }
          }
      }
    printf("%d\n", *min_element(f[n], f[n] + M));
  }
  return 0;
}
                                                     