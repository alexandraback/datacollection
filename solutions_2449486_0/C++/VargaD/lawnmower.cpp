#include <iostream>

#define MAX_W 100

int main()
{
  int T;
  std::cin >> T;
  for (int t=0; t<T; ++t)
  {
    printf("Case #%d: ", t+1);
    int w, h;
    int g[MAX_W][MAX_W];
    bool p[MAX_W][MAX_W] = {};
    // Read input
    std::cin >> w >> h;
    for (int i=0; i<w; ++i)
      for (int j=0; j<h; j++)
        std::cin >> g[i][j];
    // Solve
    // Rows
    for (int i=0; i<w; ++i)
    {
      int max = g[i][0];
      for (int j=1; j<h; j++)
        if (g[i][j] > max) max = g[i][j];
      for (int j=0; j<h; j++)
        if (g[i][j] == max) p[i][j] = true;
    }
    // Cols
    for (int i=0; i<h; ++i)
    {
      int max = g[0][i];
      for (int j=1; j<w; j++)
        if (g[j][i] > max) max = g[j][i];
      for (int j=0; j<w; j++)
        if (g[j][i] == max) p[j][i] = true;
    }
    for (int i=0; i<w; ++i)
      for (int j=0; j<h; j++)
        if (!p[i][j])
        {
          printf("NO\n");
          goto finished;
        }
    printf("YES\n");
finished:;
  }
}
