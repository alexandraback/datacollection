#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
              
int main (void)
{
  int test, tests;

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int n, m, k, t;
    scanf ("%d %d %d", &n, &m, &k);
    if (k <= 4 || m <= 2 || n <= 2)
    {
      printf ("Case #%d: %d\n", test + 1, k);
      continue;
    }
    if (n > m)
      t = n, n = m, m = t;

    if (n == 3) 
    {
      if (m == 3)
      {
        printf ("Case #%d: %d\n", test + 1, k - 1);
        continue;
      }
      if (m == 4)
      {
        printf ("Case #%d: %d\n", test + 1, k - 1 - (k > 7));
        continue;
      }
      if (m == 5)
      {
        printf ("Case #%d: %d\n", test + 1, k - 1 - (k > 7) - (k > 10));
        continue;
      }
      if (m == 6)                                                                  
      {
        printf ("Case #%d: %d\n", test + 1, k - 1 - (k > 7) - (k > 10) - (k > 13));
        continue;
      }
    }
    if (n == 4)
    {
      if (m == 4)
      {          //    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
        int ans[16] = {1, 2, 3, 4, 4, 5, 6, 6, 7, 7,  8,  8,  9,  10, 11, 12};
        printf ("Case #%d: %d\n", test + 1, ans[k - 1]);
        continue;

      }
      if (m == 5)
      {          //    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
        int ans[20] = {1, 2, 3, 4, 4, 5, 6, 6, 7, 7,  8,  8,   9,  9, 10, 10, 11, 12, 13, 14};
        printf ("Case #%d: %d\n", test + 1, ans[k - 1]);
        continue;

      }
    }  
    
    
  }
  return 0;
}
