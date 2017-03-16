#include <cstdio>
#include <algorithm>
using namespace std;

const int infinity = 1000000009;
const int di[] = {-1, 0, +1, 0};
const int dj[] = {0, +1, 0, -1};

int H, N, M;
int F[109][109];
int C[109][109];

int T[109][109];
int done[109][109];

int whenMoveFromInDir (int i, int j, int d)
{
  //destination
  int id = i + di[d];
  int jd = j + dj[d];
  int cd = C[id][jd];
  if (F[i][j] + 50 > cd) return infinity;
  if (F[id][jd] + 50 > cd) return infinity;
  if (F[id][jd] + 50 > C[i][j]) return infinity;
  return max(0, H - (cd - 50));
}

void DFS (int i, int j)
{
  T[i][j] = 0;
  for (int d = 0; d < 4; d++)
    if ((whenMoveFromInDir(i, j, d) == 0) && (T[i + di[d]][j + dj[d]] > 0))
      DFS(i + di[d], j + dj[d]);
}

int main()
{
  int TC;
  scanf("%d", &TC);
  for (int Ti = 1; Ti <= TC; Ti++)
  {
    //init
    scanf("%d %d %d", &H, &N, &M);
    for (int i = 0; i <= N + 1; i++)
      for (int j = 0; j <= M + 1; j++)
      {
        F[i][j] = 0;
        C[i][j] = 0;
        T[i][j] = infinity;
        done[i][j] = false;
      }
  
    //input
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++)
        scanf("%d", &C[i][j]);
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++)
        scanf("%d", &F[i][j]);
    
      /*
    printf("%d\n", Ti);
    printf("%d %d %d\n", H, N, M);
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= M; j++)
        printf(" %d", C[i][j]);
      printf("\n");
    }
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= M; j++)
        printf(" %d", F[i][j]);
      printf("\n");
    }*/
      
    //initial movement
    DFS(1, 1);
    
    //Dijkstra
    while (true)
    {
      //extract-min
      int i = -1;
      int j = -1;
      int t = infinity;
      for (int x = 1; x <= N; x++)
        for (int y = 1; y <= M; y++)
          if ((!done[x][y]) && (T[x][y] < t))
          {
            t = T[x][y];
            i = x;
            j = y;
          }
      if (i == -1) break;
      done[i][j] = true;
      
      //relax
      for (int d = 0; d < 4; d++)
      {
        int id = i + di[d];
        int jd = j + dj[d];
        int startMoving = max(T[i][j], whenMoveFromInDir(i, j, d));
        int moveTime = (H - startMoving >= F[i][j] + 20) ? 10 : 100;
        //if (startMoving < infinity)
        //  printf("Moving from %d %d in dir %d (to %d %d) at time %d\n", i, j, d, id, jd, startMoving);
        if (T[id][jd] > startMoving + moveTime)
          T[id][jd] = startMoving + moveTime;
      }
    }
    /*
    printf("%d\n", whenMoveFromInDir(1, 7, 1));
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= M; j++)
        printf(" %d", T[i][j]);
      printf("\n");
    }
    */
    //output
    printf("Case #%d: %f\n", Ti, 0.1 * T[N][M]);
    
  }
  return 0;
}