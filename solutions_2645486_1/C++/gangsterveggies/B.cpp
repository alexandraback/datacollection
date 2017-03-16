#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct node
{
  int inter, pos;
  long long int val;
  bool operator < (const node b) const
    {
      return val < b.val;
    }
} typedef node;

long long int v[12000];
long long int E, R, N;
int used[12000];
priority_queue<node> pq;

inline long long int max(long long int a, long long int b)
{
  return (a > b) ? a : b;
}

long long int calc()
{
  if (R >= E)
  {
    long long int ans = 0;
    int i;
    for (i = 0; i < N; i++)
      ans += E * v[i];
    return ans;
  }
  long long int ans = 0, dif = E / R;
  int i = 0;
  memset(used, 0, sizeof used);
  for (i = 0; i < N; i++)
  {
    node nx = pq.top();
    pq.pop();
    if (nx.inter != i)
    {
      int j, mx = N + 3;
      for (j = 1; j <= dif && nx.pos + j < N; j++)
        if (used[nx.pos + j])
        {
          mx = j;
          break;
        }
      for (j = 1; j <= dif && nx.pos - j >= 0; j++)
        if (used[nx.pos - j])
        {
          if (j < mx)
            mx = j;
          break;
        }
      if (mx != N + 3)
      {
        nx.val = R * mx * v[nx.pos];
      }
      nx.inter = i;
      pq.push(nx);
      i--;
    }
    else
    {
      ans += nx.val;
      used[nx.pos] = 1;
    }
  }
  return ans;
}

int main()
{
  int t, T, i;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%lld %lld %lld", &E, &R, &N);
    for (i = 0; i < N; i++)
    {
      scanf("%lld", &v[i]);
      node nn;
      nn.inter = 0;
      nn.pos = i;
      nn.val = v[i] * E;
      pq.push(nn);
    }
    printf("Case #%d: %lld\n", t, calc());
  }
  return 0;
}
