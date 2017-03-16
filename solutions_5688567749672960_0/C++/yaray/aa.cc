#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

ll rl()
{
  ll x;
  scanf("%lld", &x);
  return x;
}

const int N = 1000000;
int s[N+1];

int main()
{
  int cases = ri(), d[7] = {};
  FOR(i, 1, N) {
    int x = i, y = 0;
    do y = y*10+x%10; while (x /= 10);
    s[i] = s[i-1]+1;
    if (y < i && i % 10) s[i] = min(s[i], s[y]+1);
  }
  s[N] = s[N-1]+1;
  REP1(cc, cases)
    printf("Case #%d: %d\n", cc, s[ri()]);
}
