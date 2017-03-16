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
    int N;
    scanf("%d", &N);
    double a[N], b[N];
    for(int i = 0; i < N; i++)
      scanf("%lf", a+i);
    for(int i = 0; i < N; i++)
      scanf("%lf", b+i);

    sort(a, a+N);
    sort(b, b+N);

    int p,q;
    p = q = 0;

    int i,j;
    for(i = j = 0; i < N; i++, j++)
      while(j < N && a[i] > b[j])
      {
        q++; j++;
      }

    for(i = j = 0; i < N; i++)
      if (a[i] > b[j]) { j++; p++; }

    printf("Case #%d: %d %d\n", caso, p, q);
  }
}
