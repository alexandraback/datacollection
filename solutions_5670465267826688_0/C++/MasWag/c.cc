#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>


#define rep(i,n) for (int i = 0; i < n; i++)
#define sign(A) (A / abs(A))
char str[10001];
signed char dp[10000][10000];

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
      memset (dp,1,10000 * 10000);
      
      int L,X;
      int result = 0;
      scanf ("%d %d",&L,&X);
      scanf ("%10000s",str);
      for (int i = 1;i < X; i++) 
        {
          memcpy(str + i * L, str, L);
        }

      const int lim = X * L;
      rep (y,lim)
        {
          const char c = str[y];
          rep (x,y + 1)
            {
              const int l = y && x != y ? dp[x][y-1] : 1;
              dp[x][y] = sign (l) * product[abs (l)][c - 'g'];
            }
        }
      


      for (int i = 0; i < lim; ++i) 
        {          
          if (dp[0][i] != I)
            continue;
          for (int j = i + 1; j < lim; ++j)
            {
              if (dp[i+1][j] != J)
                continue;
              if (dp[j+1][lim-1] == K)
                {
                  result = 1;
                  goto end;
                }
            }
        }

      end:
      printf ("Case #%d: %s\n",t+1,result ? "YES" : "NO");
    }
  return 0;
}










