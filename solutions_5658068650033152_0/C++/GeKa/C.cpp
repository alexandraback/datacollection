#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <algorithm>
#include <map>
#include <set>

using namespace std;

int N, M, K;

int grid[21][21];
int visited[21][21];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool is_valid(int x, int y)
{
  return x >= 0 && x < N && y >= 0 && y <= M;
}

bool dfs(int i, int j)
{
  bool res = false;
  visited[i][j] = 1;
  for (int k = 0; k < 4; ++k)
  {
    int x = i + dx[k];
    int y = j + dy[k];

    if (is_valid(x, y) && !visited[x][y] && grid[x][y] == 0)
      res = res || dfs(x, y);
  }

  if (i == 0 || i == N-1 || j ==0 || j == M - 1)
    res = true;

  return res;
}

bool check(int mask)
{
  memset(grid, 0, sizeof(grid));
  memset(visited, 0, sizeof(visited));

  int enclosed = 0;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
    {
      if (mask & (1 << (i * M +j)))
      {
        grid[i][j] = 1;
        enclosed++;
      }

    }

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
    {
      if (grid[i][j] == 0)
      {
        memset(visited, 0, sizeof(visited));
        if (!dfs(i, j))
          ++enclosed;
      }
    }

  return enclosed >= K;
}

int main()
{
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("c-result.txt", "w", stdout);
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
  {
    cin >> N >> M >> K;

    int max_size = N * M;

    int best = max_size;
    vector<int> masks;
    masks.reserve(1 << max_size);
    for (int m = 0; m < (1 << max_size); ++m)
      masks.push_back(m);
    sort(masks.begin(), masks.end(), [&](int a, int b) -> bool
    {
      int c1 = 0, c2 = 0;
        for (int i = 0; i < max_size; ++i)
        {
          if (a & (1 << i))
            ++c1;
          if (b & (1 << i))
            ++c2;
        }

        return c1 < c2;
    }
    );

    check(305280);
    for (int m = 0; m < masks.size(); ++m)
    {
      if (check(masks[m]))
      {
        int count = 0;
        for (int i = 0; i < max_size; ++i)
        {
          if (masks[m] & (1 << i))
            ++count;

        }
        if (count < best)
            best = count;
      }
    }

    printf("Case #%d: %d", i + 1, best);



    printf("\n");
    fflush(stdout);
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
};