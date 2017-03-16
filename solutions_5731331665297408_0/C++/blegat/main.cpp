#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

#define N 50

using namespace std;

int n, m;
int visit[N];
pair<int,int> zip[N];
int zz[N];
int order[N];
bool visited[N];
bool tmpvisited[N];
int curs[N];
int ncurs;
int g[N][N];
int ng[N];

int main (void) {
  int T;
  scanf("%d", &T);
  for (int currentcase = 1; currentcase <= T; ++currentcase) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", &zz[i]);
      zip[i].first = zz[i];
      zip[i].second = i;
    }
    sort(zip, zip+n);
    for (int i = 0; i < n; i++) {
      order[zip[i].second] = i;
    }

    memset(ng, 0, n * sizeof(int));
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b); a--;
      b--;
      g[a][ng[a]++] = b;
      if (a != b) {
        g[b][ng[b]++] = a;
      }
    }

    memset(visited, false, n * sizeof(int));
    ncurs = 1;
    curs[0] = zip[0].second;
    visit[0] = curs[0];
    visited[curs[0]] = true;
    for (int i = 1; i < n; i++) {
      int mini = 0, imin, kmin;
      bool notfound = true;
      while (notfound) {
        imin = -1;
        kmin = -1;
        for (int j = mini; j < ncurs; j++) {
          int cur = curs[j];
          for (int k = 0; k < ng[cur]; k++) {
            // greater is better so >=
            int kur = g[cur][k];
            if (!visited[kur] && (imin == -1 || zz[kmin] >= zz[kur])) {
              imin = j;
              kmin = kur;
            }
          }
        }
        notfound = false;
        if (imin+1 < ncurs) { // we need to left some behing
          // can we finish without them ?
          memcpy(tmpvisited, visited, n*sizeof(bool));
          queue<int> q;
          for (int j = 0; j <= imin; j++) {
            q.push(curs[j]);
          }
          int left = n;
          for (int j = 0; j < n; j++) {
            if (visited[j]) left--;
          }
          while (!q.empty() && left > 0) {
            int cur = q.front();
            q.pop();
            for (int k = 0; k < ng[cur]; k++) {
              int next = g[cur][k];
              if (!tmpvisited[next]) {
                left--;
                q.push(next);
                tmpvisited[next] = true;
              }
            }
          }
          if (left > 0) {
            notfound = true;
            mini = imin + 1;
          }
        }
      }
      ncurs = imin + 1;
      curs[ncurs++] = kmin;
      visit[i] = kmin;
      visited[kmin] = true;
    }


    printf("Case #%d: ", currentcase);
    for (int i = 0; i < n; i++) {
      printf("%d", zz[visit[i]]);
    }
    printf("\n");
  }
  return 0;
}
