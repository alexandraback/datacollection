#include <cstdio>
#include <cstring>

int res;
int gain;

int tasks[10123];

int N, E;

int memo[12][12];

int go(int idx, int energy)
{
  if(memo[idx][energy] > -1) return memo[idx][energy];

  if(idx == N) return 0;

  int res = 0;

  for(int i = energy; i >= 0; i--)
  {
    int n = energy - i + gain;

    if(n > E) n = E;

    int r = tasks[idx] * i + go(idx + 1, n);

    if(r > res) res = r;
  }

  return memo[idx][energy] = res;
}


int main(void)
{
  int T;

  scanf("%d\n", &T);

  for(int cas = 1; cas <= T; cas++)
  {
    scanf("%d %d %d\n", &E, &gain, &N);
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < N; i++)
    {
      scanf("%d", &tasks[i]);
    }

    printf("Case #%d: %d\n", cas, go(0, E));
  }

  return 0;
  
}
