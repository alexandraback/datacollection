#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    int h, n, m;
    cin >> h >> n >> m;
    vector<vector<int>> C(n, vector<int>(m)), F(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        cin >> C[i][j];
      }
    }
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        cin >> F[i][j];
      }
    }
    cout << "Case #" << t << ": ";
    set<pair<int, int>> was;
    set<pair<int, pair<int, int>>> queue;
    queue.insert(make_pair(0, make_pair(0, 0)));
    was.insert(queue.begin()->second);
    while (true)
    {
      pair<int, pair<int, int>> p = *queue.begin();
      if (p.second == make_pair(n - 1, m - 1))
      {
        cout << p.first / 10.0;
        break;
      }
      queue.erase(queue.begin());
      int x = p.second.first, y = p.second.second;
      int l = h - p.first;
      int t = p.first;
      for (int dx = -1; dx < 2; ++dx)
      {
        for (int dy = -1; dy < 2; ++dy)
        {
          if (abs(dx) + abs(dy) != 1 || x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= m)
          {
            continue;
          }
          if (C[x + dx][y + dy] - F[x + dx][y + dy] < 50 ||
              C[x + dx][y + dy] - F[x][y] < 50 ||
              C[x][y] - F[x + dx][y + dy] < 50)
          {
            continue;
          }
          int start = max(t, l - (C[x + dx][y + dy] - 50));
          if (start == 0 && was.find(make_pair(x + dx, y + dy)) == was.end())
          {
            was.insert(make_pair(x + dx, y + dy));
            queue.insert(make_pair(0, make_pair(x + dx, y + dy)));
            continue;
          }
          if (l - start + t - F[x][y] >= 20)
          {
            queue.insert(make_pair(start + 10, make_pair(x + dx, y + dy)));
          }
          else
          {
            queue.insert(make_pair(start + 100, make_pair(x + dx, y + dy)));
          }
        }
      }
    }
    cout << "\n";
  }
  return 0;
}
