#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <algorithm>
#include <map>
#include <set>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

ull gcd(ull x, ull y)
{
  return (y == 0) ? x : gcd(y, x % y);
}

int main()
{
  freopen("A-large.in", "r", stdin);
  freopen("A-result-big.txt", "w", stdout);
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
  {
    ull p, q;
    scanf("%I64u/%I64u", &p, &q);

    ull g = gcd(p, q);
    p /= g;
    q /= g;

    int answer = 0;
    int step = 0;

    while ((1ULL << step) < q)
    {
      ++step;
    }

    if ((1ULL << step) != q)
      answer = -1;
    else
    {
      int x = 1;

      while (p < q / (1ULL << x))
      {
        ++x;
      }
      answer = x;
    }


    printf("Case #%d: ", i + 1);
    if (answer == -1)
      printf("impossible");
    else
      printf("%d", answer);



    printf("\n");
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
};