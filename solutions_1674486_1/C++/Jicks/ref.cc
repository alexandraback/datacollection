#include <iostream>
#include <vector>

bool dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& mark, int start)
{
  if (mark[start]) return true;
  mark[start] = true;

  for (int i = 0; i < graph[start].size(); ++i)
  {
    if (dfs(graph, mark, graph[start][i] - 1))
      return true;
  }

  return false;
}

int main()
{
  int T; std::cin >> T; std::cin.ignore();

  for (int i = 1; i <= T; ++i)
  {
    bool result = false;
    int N; std::cin >> N; std::cin.ignore();
    std::vector<std::vector<int>> graph(N, std::vector<int>());

    for (int j = 0; j < N; ++j)
    {
      int Mi; std::cin >> Mi;

      for (int k = 0; k < Mi; ++k)
      {
        int tmp; std::cin >> tmp;
        graph[j].push_back(tmp);
      }
      std::cin.ignore();
    }
    for (int j = 0; j < N; ++j)
    {
      std::vector<bool> mark(N, false);
      if (dfs(graph, mark, j)) { result = true; break; }
    }

    std::cout << "Case #" << i << ": " << ((result) ? "Yes" : "No") << std::endl;
  }
}
