
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> topo;

int in_degree[1000];
bool G[1000][1000];
bool seen[1000];

bool dfs(int u, int N)
{
  for (int i = 0; i < N; i++)
  {
    if (i == u) continue;
    if (G[u][i] && seen[i])
      return true;
    if (G[u][i] && !seen[i])
    {
      seen[i] = true;
      bool res = dfs(i, N);
      if (res == true) return true;
    }
  }
  return false;
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int case_id = 1; case_id <= T; case_id++)
  {
    memset(G, 0, sizeof(G));
    memset(seen, 0, sizeof(seen));
    memset(in_degree, 0, sizeof(in_degree));
    
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
      int neighbors;
      scanf("%d", &neighbors);
      for (int j = 0; j < neighbors; j++)
      {
	int neighbor;
	scanf("%d", &neighbor);
	G[i][neighbor-1] = true;
	in_degree[neighbor-1]++;
      }
    }

    vector<int> sources;
    for (int i = 0; i < N; i++)
      if (in_degree[i] == 0) sources.push_back(i);

    bool ans = false;
    for (int i = 0; i < sources.size(); i++)
    {
      memset(seen, 0, sizeof(seen));
      seen[sources[i]] = true;
      bool res = dfs(sources[i], N);
      if (res == true)
      {
	ans = true;
	break;
      }
    }

    printf("Case #%d: %s\n", case_id, ans ? "Yes" : "No");
  }
}
