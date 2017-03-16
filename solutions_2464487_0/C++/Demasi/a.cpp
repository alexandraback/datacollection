#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    printf("Case #%d: ", caso);

    long long resp, r, t;
    scanf("%lld %lld", &r, &t);

    resp = 0;

    while((2*r+1) <= t)
    {
      resp++;
      t -= 2*r+1;
      r += 2;
    }

    printf("%lld\n", resp);
  }
}
