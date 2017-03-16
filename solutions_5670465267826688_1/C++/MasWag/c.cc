#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>


#define rep(i,n) for (int i = 0; i < n; i++)
#define sign(A) (A / abs(A))
char str[10001];

int main(void)
{
  int T;
  const int I = 2;
  const int J = 3;
  const int K = 4;
  scanf ("%d",&T);
  int product[5][5];

  rep (t,5)
    {
      product [1][t] = t;
      product [t][1] = t;
    }
  
  product [I][I] = -1;
  product [I][J] = K;
  product [I][K] = -J;
  product [J][I] = -K;
  product [J][J] = -1;
  product [J][K] = I;
  product [K][I] = J;
  product [K][J] = -I;
  product [K][K] = -1;

  rep (t,T)
    {
      memset (str,0,10001);
      
      char f = I;
      int L,X;
      int result = 0;
      scanf (" %d %d ",&L,&X);
      // scanf ("%10000s",str);
      // for (int i = 1;i < X; i++) 
      //   {
      //     memcpy(str + i * L, str, L);
      //   }

      signed char a = 1;

      if (X & 1)
        {
          if (X == 1)
            {
              for (int i = 0; i < L; ++i)
                {              
                  const char c = getchar ();
                  a = sign (a) * product[abs (a)][c - 'g'];
                  if (a != f)
                    continue;
                  f += 2;
                }

              if (a == -1 && f == 'm' - 'g') 
                {
                  result = 1;
                }
            }
          else
            {
              bool count[5] = {};
              for (int i = 0; i < L; ++i)
                {
                  const char c = getchar ();
                  a = sign (a) * product[abs (a)][c - 'g'];
                  count[abs(a)] = true;
                }

              if (a == -1 && count[I] && count[K])
                {
                  result = 1;
                }
            }
        }
      else
        {
          bool cnt[5] = {};
          for (int i = 0; i < L; ++i)
            {
              const char c = getchar ();
              a = sign (a) * product[abs (a)][c - 'g'];
              cnt[abs(a)] = true;
            }
          if (X & 2)
            {
              if (X == 2)
                {
                  if ((abs(a) == I && cnt[1] && cnt[J]) || (abs(a) == J && (cnt [I] && cnt [K])) || (abs(a) == K && cnt[1] && cnt[J]))
                    {
                      result = 1;
                    }
                }
              else
                {
                  if ((abs(a) == I && cnt[J]) || (abs(a) == J && (cnt [I] || cnt [K])) || (abs(a) == K && cnt[J]))
                    {
                      result = 1;
                    }
                }
            }
        }
      
      printf ("Case #%d: %s\n",t+1,result ? "YES" : "NO");
    }
  return 0;
}










