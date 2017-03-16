#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


int pal(char *x)
{
  int i, j, l;
  l = strlen(x);
  for(i=0, j=l-1; i<=j; i++, j--)
      if(x[i] != x[j])
          return 0;
  return 1;
}


int pal(int x)
{
  char s[100];
  sprintf(s, "%d", x);
  return pal(s);
}


int pal(long long x)
{
  char s[100];
  sprintf(s, "%lld", x);
  return pal(s);
}


const int MAXFS = 100;
long long fs[MAXFS];
int nfs=0;
long long last = 0;


int precomp(long long B)
{
  long long s;
  int a, b;
  int i;

  a = ceil(sqrt(last + 1));
  b = floor(sqrt(B));
  for(i=a; i<=b; i++)
      if(pal(i))
        {
          s = i * (long long) i;
          if(pal(s))
            {
              // std::cerr << i << "  " << s << "\n";
              assert(nfs<MAXFS);
              fs[nfs++] = s;
            }
        }
  if(B>last)
      last = B;
}


int main(int argc, char **argv)
{
  long long A, B;
  int i, j, N, n;

  std::cin >> N;
  for(i=1; i<=N; i++)
    {
      std::cin >> A >> B;
      precomp(B);
      n = 0;
      for(j=0; j<nfs; j++)
          if(fs[j]>=A && fs[j]<=B)
              n++;
      std::cout << "Case #" << i << ": " << n << "\n";
    }
}
