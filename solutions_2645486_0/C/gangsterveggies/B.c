#include <stdio.h>

int v[20];
int E, R, N;

inline int max(int a, int b)
{
  return (a > b) ? a : b;
}

int dfs(int curr, int en)
{
  if (en > E)
    en = E;
  if (curr == N)
    return 0;
  int i, ans = 0;
  for (i = 0; i <= en; i++)
  {
    ans = max(ans, dfs(curr + 1, i + R) + v[curr] * (en - i));
  }
  return ans;
}

int main()
{
  int t, T, i;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%d %d %d", &E, &R, &N);
    for (i = 0; i < N; i++)
      scanf("%d", &v[i]);
    printf("Case #%d: %d\n", t, dfs(0, E));
  }
  return 0;
}
