#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MaxR = 8000, MaxK = 12, MaxN = 12, MaxM = 12;
const double MINUTES = 3.5;                            

long long p[MaxR+1][MaxK + 1];

int ans[MaxR][MaxN];
int ok[MaxR];
int tmp[MaxN];
long long sub[1 << MaxN];
map <int, char> u;

int main (void)
{
  int test, tests;

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, j, l, r, n, m, k, cnt, cnta;
    time_t start, end;
    char srt[MaxM];
    srand(time(NULL));
    start = clock();
    scanf ("%d %d %d %d", &r, &n, &m, &k);
    for (i = 0; i < r; i++)
      for (j = 0; j < k; j++)
        scanf ("%I64d", &p[i][j]);
    for (i = 0; i < r; i++)
    {
      ok[i] = 1;
      for (j = 0; j < n; j++)
        ans[i][j] = 2;
    }
    u.clear();
    while (1)
    {
      end = clock();
      if ((double)(end-start)/CLOCKS_PER_SEC / 60 > MINUTES)
        break;
      memset (srt, 0, sizeof(srt));
      for (i = 0; i < n; i++)
        tmp[i] = 2 + rand() % (m - 1), 
        srt[tmp[i]]++;
      long long s = 0, mod = 1000000007, pr = 41;
      for (i = 2; i <= m; i++)
        s = (s * pr + srt[i]) % mod;
      if (u[(int)s] == 1)
        continue;
      u[(int)s] = 1;

      for (j = 0; j < (1 << n); j++)
      {
        sub[j] = 1;
        for (i = 0; i < n; i++) if (j & (1 << i))
          sub[j] *= tmp[i];
      }
      for (l = 0; l < r; l++)
      {
        cnta = 0;
        for (i = 0; i < k; i++)
        {
          cnt = 0;
          for (j = 0; j < (1 << n); j++)
            if(p[l][i] == sub[j])
              cnt++;
          if (cnt == 0)
            break;
          cnta += cnt; 
        }
        if (i == k)
          if (ok[l] < cnta)
          {
            ok[l] = cnta;
            for (i = 0; i < n; i++)
              ans[l][i] = tmp[i];
          }
      }
    }
    printf ("Case #%d:\n", test + 1);
    for (i = 0; i < r; i++, printf ("\n"))
      for (j = 0; j < n; j++)
        printf ("%d", ans[i][j]);
      
    
  }
  return 0;
}
