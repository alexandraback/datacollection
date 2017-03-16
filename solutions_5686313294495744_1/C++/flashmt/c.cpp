#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp
{
  vector <int> leftMatch, rightMatch, dist, cur;
  vector < vector <int> > a;
  int m, n;

  HopcroftKarp() {}
  HopcroftKarp(int m, int n)
  {
    this -> m = m;
    this -> n = n;
    a = vector < vector <int> >(m);
    leftMatch = vector <int>(n, -1);
    rightMatch = vector <int>(m, -1);
    dist = vector <int>(m, -1);
    cur = vector <int>(m, -1);
  }

  void addEdge(int x, int y)
  {
    a[x].push_back(y);
  }

  int bfs()
  {
    int found = 0;
    queue <int> q;
    for (int i = 0; i < m; i++)
      if (rightMatch[i] < 0) dist[i] = 0, q.push(i);
      else dist[i] = -1;

    while (!q.empty())
    {
      int x = q.front(); q.pop();
      for (int i = 0; i < int(a[x].size()); i++)
      {
        int y = a[x][i];
        if (leftMatch[y] < 0) found = 1;
        else
          if (dist[leftMatch[y]] < 0)
            dist[leftMatch[y]] = dist[x] + 1, q.push(leftMatch[y]);
      }
    }

    return found;
  }

  int dfs(int x)
  {
    for (; cur[x] < int(a[x].size()); cur[x]++)
    {
      int y = a[x][cur[x]];
      if (leftMatch[y] < 0 || (dist[leftMatch[y]] == dist[x] + 1 && dfs(leftMatch[y])))
      {
        leftMatch[y] = x; rightMatch[x] = y;
        return 1;
      }
    }
    return 0;
  }

  int maxMatching()
  {
    int match = 0;
    while (bfs())
    {
      for (int i = 0; i < m; i++) cur[i] = 0;
      for (int i = 0; i < m; i++)
        if (rightMatch[i] < 0) match += dfs(i);
    }
    return match;
  }
};

map <string,int> words[2];

int get(map <string,int> &words, string s)
{
  if (!words.count(s))
    words[s] = words.size() - 1;
  return words[s];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cerr << "Running test " << iTest << "..." << endl;
    int n, x[1010], y[1010];
    string s, t;
    words[0].clear();
    words[1].clear();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> s >> t;
      x[i] = get(words[0], s);
      y[i] = get(words[1], t);
    }

    int L = words[0].size(), R = words[1].size();
    HopcroftKarp hk(L, R);
    for (int i = 0; i < n; i++)
      hk.addEdge(x[i], y[i]);

    cout << "Case #" << iTest << ": " << n - (L + R - hk.maxMatching()) << endl;
  }
}