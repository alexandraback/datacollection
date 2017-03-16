#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector <int> edges [1001];
int visited[1001];
int flag;

void test(int fr, int to)
{
  memset(visited, 0, sizeof(visited));
  queue<int> q;
  q.push(fr);
  int fs = 0;
  while (!q.empty())
  {
    int cc = q.front();
    q.pop();
    if (cc == to)
    {
      if (fs)
      {
        flag = 1;
        break;
      }
      fs = 1;
      continue;
    }
    visited[cc] = 1;
    int i, tam = edges[cc].size();
    for (i = 0; i < tam; i++)
      if (!visited[edges[cc][i]])
        q.push(edges[cc][i]);
  }
}

int main()
{
  int t, T, i, j, n, k, val;
  scanf("%d", &T);
  for (t = 0; t < T; t++)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%d", &k);
      edges[i].clear();
      for (j = 0; j < k; j++)
      {
        scanf("%d", &val);
        val--;
        edges[i].push_back(val);
      }
    }
    flag = 0;
    for (i = 0; i < n && !flag; i++)
      for (j = 0; j < n && !flag; j++)
        if (i != j)
          test(i, j);
    if (flag)
      printf("Case #%d: Yes\n", t + 1);
    else
      printf("Case #%d: No\n", t + 1);
  }

  return 0;
}
