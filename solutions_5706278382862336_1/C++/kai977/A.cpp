#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
long long P, Q;
int i;
long long p2[41];

long long gcd(long long a, long long b)
{
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {

  p2[0] = 1;
  for (i = 1; i <= 40; i++) p2[i] = p2[i-1] * 2;
    
  scanf("%d", &T);
  int c = 0;
  while (T--) {
    c++;
    scanf("%lld/%lld", &P, &Q);

    if (P == Q) {
      printf("Case #%d: %d\n", c, 0);
      continue;
    }
    
    long long g = gcd(P, Q);
    P /= g;
    Q /= g;    
    
    bool ok = false;
    for (i = 0; i <= 40; i++)
      if (p2[i] == Q) {ok = true; break;}
    
    if (!ok) {
      printf("Case #%d: impossible\n", c);
      continue;
    }
    
    int sol = 1;
    while (P < Q/2) {
      Q /= 2; sol++;
    }
    
    printf("Case #%d: %d\n", c, sol);
  }
  
  
  return 0;
}