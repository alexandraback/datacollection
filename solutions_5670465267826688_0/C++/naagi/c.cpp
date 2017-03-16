#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 12345;
char mul[256][256];
char sgn[256][256];

char s[MaxN], sl[MaxN];

void init_mul (void)
{
  char e = '1', i = 'i', j = 'j', k = 'k';
  memset (mul, 0, sizeof(mul));
  memset (sgn, 0, sizeof(sgn));
  mul[e][e] = e;
  mul[e][i] = i;
  mul[e][j] = j;
  mul[e][k] = k;
  mul[i][e] = i;
  mul[i][i] = e; sgn[i][i] = 1; 
  mul[i][j] = k;
  mul[i][k] = j; sgn[i][k] = 1;
  mul[j][e] = j;
  mul[j][i] = k; sgn[j][i] = 1;
  mul[j][j] = e; sgn[j][j] = 1;
  mul[j][k] = i;
  mul[k][e] = k;
  mul[k][i] = j;
  mul[k][j] = i; sgn[k][j] = 1;
  mul[k][k] = e; sgn[k][k] = 1;
}
              
int main (void)
{
  int test, tests;
  init_mul();
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, j, l, x, n, res = 0;
    char cmul = '1', csgn = 0, t;
    scanf ("%d %d", &l, &x);
    scanf (" %s", sl);
    for (i = 0; i < x; i++)
      for (j = 0; j < l; j++)
        s[i*l + j] = sl[j];
    n = l * x;
    s[n] = 0;
    for (i = 0; i < n; i++)
    {
      
      t = mul[cmul][s[i]];
      csgn = csgn ^ sgn[cmul][s[i]];
      cmul = t; 
      if (cmul == 'i' && csgn == 0)
        break;
    }  
    
    for (i++, cmul = '1'; i < n; i++)
    {
      
      t = mul[cmul][s[i]];
      csgn = csgn ^ sgn[cmul][s[i]];
      cmul = t; 
      if (cmul == 'j' && csgn == 0)
        break;

    }  

    for (i++, cmul = '1'; i < n; i++)
    {
      
      t = mul[cmul][s[i]];
      csgn = csgn ^ sgn[cmul][s[i]];
      cmul = t; 

    }  
    
    if (cmul == 'k' && csgn == 0)
      res = 1;
    printf ("Case #%d: %s\n", test + 1, res? "YES":"NO");
  }
  return 0;
}
