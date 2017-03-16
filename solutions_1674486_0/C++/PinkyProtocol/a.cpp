#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int t; cin >> t;
  for (int k = 1 ; k <= t; ++k)
  {
    int N; cin >> N;
    vector<int> roots;
    vector<vector<int> > g(N, vector<int>());    
    vector<int> f(N, 0);
    vector<vector<bool> > edges(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i)
    {
      int M; cin >> M;
      if (M == 0) roots.push_back(i);
      for (int j = 0; j < M; ++j)
      {
        int n; cin >> n;
        ++f[i];
        edges[n-1][i] = true;
      }
    }
    queue<int > q;
    for (int i =0; i < roots.size(); ++i)
    {
      q.push(roots[i]);
      g[roots[i]].push_back(roots[i]);
      ++f[roots[i]];
    }
    while (!q.empty())
    {
      int z = q.front();
      q.pop();
      if (f[z] == 1)
      {
        for (int i = 0; i < N; ++i)
        {;
          if (edges[z][i])
          {
            for (int j = 0; j < g[z].size(); ++j)
            {  g[i].push_back(g[z][j]); }
            q.push(i);
          }
        }
      }
      else --f[z];
    }
    bool flag = false;
    for (int i =0; i < N; ++i)
    {
      vector<int> z(N, 0);
      for (int j = 0; j < g[i].size(); ++j)
      {
        ++z[g[i][j]];
      }
      for (int j = 0; j < N; ++j)
        if (z[j] >= 2) flag = true;
    }
    if (flag) printf("Case #%i: Yes\n", k);
    else printf("Case #%i: No\n", k);
  }
}