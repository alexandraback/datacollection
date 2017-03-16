#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long double Double;
typedef vector<int> VInt;
typedef vector< vector<int> > VVInt;
typedef long long Int;
typedef pair<int, int> PII;

#define FOR(i, n, m) for(i = n; i < m; ++i)
#define RFOR(i, n, m) for(i = (n) - 1; i >= (m); --i)
#define CLEAR(x, y) memset(x, y, sizeof(x))
#define COPY(x, y) memcpy(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

int Floor[110][110];
int Top[110][110];
int R[110][110];

#define MAX 100000000

int Mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int N, M, H;
    scanf("%d%d%d", &H, &N, &M);
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        scanf("%d", &Top[i][j]);

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        scanf("%d", &Floor[i][j]);

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        R[i][j] = MAX;
    R[0][0] = 0;

    while (true) {
      int relax = 0;
      for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
          if (R[i][j] != MAX) {
            for (int d = 0; d < 4; ++d) {
              int ni = i + Mv[d][0];
              int nj = j + Mv[d][1];
              if (ni < 0 || ni >= N || nj < 0 || nj >= M)
                  continue;
              if (Floor[ni][nj] + 50 > Top[i][j])
                continue;
              if (Floor[ni][nj] + 50 > Top[ni][nj] || Floor[i][j] + 50 > Top[ni][nj])
                continue;
              int ct = R[i][j];
              int wait = max(0, (H - ct) - (Top[ni][nj] - 50));
              ct += wait;
              int sp;
              if (H-ct-20 >= Floor[i][j])
                sp = 10;
              else
                sp = 100;

              int nr = (ct == 0 ? ct : ct + sp);
              if (nr < R[ni][nj]) {
                relax = 1;
                R[ni][nj] = nr;
              }
            }
          }
      if (relax == 0)
        break;
    }

      printf("Case #%d: %.1lf\n", t+1, R[N-1][M-1] / 10.0);

    fprintf(stderr, "%d/%d\n", t+1, T);
  }

  return 0;
};
