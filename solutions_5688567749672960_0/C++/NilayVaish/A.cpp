#include <cassert>
#include <list>
#include <map>
#include <vector>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int Rev(int n)
{
  int a = 0;
  while (n > 0)
  {
    a *= 10;
    int t = n % 10;
    n /= 10;
    a += t;
  }
  return a;
}

int main()
{
  vector<int> V(1000005, -1); V[1] = 1;
  queue<int> Q; Q.push(1);
  while (!Q.empty())
  {
    int n = Q.front(); Q.pop();
    if (n < 1000000)
    {
      if (V[n+1] == -1 || V[n+1] > V[n] + 1)
      {
        V[n+1] = V[n] + 1;
        Q.push(n+1);
      }
    }
    int m = Rev(n);
    if (m <= 1000000)
    {
      if (V[m] == -1 || V[m] > V[n] + 1)
      {
        V[m] = V[n] + 1;
        Q.push(m);
      }
    }
  }

  int T; scanf("%d\n", &T); for (int ii = 1; ii <= T; ++ii)
  {
    long long N; scanf("%lld\n", &N);
    printf("Case #%d: %d\n", ii, V[N]);
  }
  return 0;
}
