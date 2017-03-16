#include <cstdio>
#include <cstdlib>
#include <vector>

#define rep(i,n) for (int i = 0; i < n; i++)

using namespace std;

int main(void)
{
  int T;
  scanf ("%d",&T);
  for (int t = 0; t < T; ++t) 
    {
      int n = 0;
      int a = 0;
      int num;
      char s[2000];
      scanf ("%d",&num);
      scanf ("%1000s",s);
      for (int i = 0; i <= num; ++i) 
        {
          if (a < i)
            {
              n += i - a;
              a = i;
            }
          a += s[i] - '0';
        }

      printf ("Case #%d: %d\n",t + 1,n);
    }

  return 0;
}
