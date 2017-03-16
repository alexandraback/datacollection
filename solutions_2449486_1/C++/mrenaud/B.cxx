#include <iostream>
#include <vector>

bool row_valid(std::vector<std::vector<int>> const& l, int x, int r, int m)
{
  for (int j = 0; j < m; ++j)
  {
    if (l[r][j] > x)
      return false;
  }
  return true;
}


bool col_valid(std::vector<std::vector<int>> const& l, int x, int c, int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (l[i][c] > x)
      return false;
  }
  return true;
}

void solve()
{
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > lawn(
    n, std::vector<int>(m, 0)
  );

  for (int i = 0; i < n; ++i)
  {
    for(int j = 0; j < m; ++j)
    {
      int h;
      std::cin >> h;
      lawn[i][j] = h;
    }
  }

  // Logic: For each square, if everything in the row is less than or
  //   equal to it, then we have no problem yet. If a tile is greater
  //   than it then the row then the perpendicular direction must all
  //   be less than or equal to it.

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (!row_valid(lawn, lawn[i][j], i, m))
      {
        if (!col_valid(lawn, lawn[i][j], j, n))
        {
          std::cout << "NO\n";
          return;
        }
      }

      // I think this may be redundant.
      if (!col_valid(lawn, lawn[i][j], j, n))
      {
        if (!row_valid(lawn, lawn[i][j], i, m))
        {
          std::cout << "NO\n";
          return;
        }
      }
    }
  }

  std::cout << "YES\n";
}


int main()
{
  int N;
  std::cin >> N;

  for (int i = 1; i <= N; ++i)
  {
    std::cout << "Case #" << i << ": ";

    solve();
  }
}
