/* gcc -o pb1 pb1.c  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define TRUE 1
#define FALSE 0


static void solve (void);

int main () 
{
  freopen ("in.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  int t,i;
  scanf ("%d", &t);
  for (i = 0; i < t; i++) {
    printf ("Case #%d: ", i + 1);
    solve ();
  }
  return 0;
}

static unsigned long long mylog2 (unsigned long long val) {
    unsigned long long ret = -1;
    while (val != 0) {
        val >>= 1;
        ret++;
    }
    return ret;
}

unsigned long long gcd ( unsigned long long a, unsigned long long b )
{
  unsigned long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

void solve (void) 
{
  int i;
  int res = 0;
  unsigned long long a,b;
  unsigned long long g;

  scanf("%lld/%lld", &a, &b);
  
  g = gcd(a,b);
  a = a/g;
  b = b/g;

  // b is a power of 2
  int logb = mylog2(b);
  if(b != (1ULL << logb)){
    printf("impossible\n");
    return;
  }
  
  int loga = mylog2(a);
  res = logb - loga;
  printf("%d\n",res);

}


