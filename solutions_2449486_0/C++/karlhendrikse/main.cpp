
#include <cassert>
#include <cstdio>

int sy;
int sx;
int desired[100][100];
int rowMaxs[100];
int colMaxs[100];

int main()
{
  int t;
  std::scanf("%d", &t);
  for(int tt = 0; tt < t; ++tt)
  {
    std::scanf("%d %d", &sy, &sx);

    for(int y = 0; y < sy; ++y)
    {
      for(int x = 0; x < sx; ++x)
      {
        int a;
        std::scanf("%d", &a);
        desired[y][x] = a;
        if(x == 0 || a > rowMaxs[y]) rowMaxs[y] = a;
        if(y == 0 || a > colMaxs[x]) colMaxs[x] = a;
      }
    }

    bool yes = true;
    for(int y = 0; y < sy; ++y)
    {
      for(int x = 0; x < sx; ++x)
      {
        if(desired[y][x] == rowMaxs[y]
        || desired[y][x] == colMaxs[x])
        {
        }
        else
        {
          yes = false;
          break;
        }
      }
      if(!yes) break;
    }

    std::printf("Case #%d: %s\n", tt + 1, yes ? "YES" : "NO");
  }
}
