#include <iostream>

const int MAX_CHILD = 1005;
const int INF = 1023456789;

using namespace std;

int bff [MAX_CHILD];
int gen [MAX_CHILD];
int col [MAX_CHILD];
int dist [MAX_CHILD][MAX_CHILD];
int farthest [MAX_CHILD];

int main () {
  int testc;
  cin >> testc;

  for (int t = 1; t <= testc; t++) {
    for (int i = 1; i < MAX_CHILD; i++) {
      gen[i] = 0;
      col[i] = 0;
      farthest[i] = 0;

      for (int j = 1; j < MAX_CHILD; j++) {
        dist[i][j] = INF;
      }
    }


    int childc;
    cin >> childc;

    for (int i = 1; i <= childc; i++) {
      cin >> bff[i];
      dist[i][bff[i]] = 1;
      dist[i][i] = 0;
    }
    
    for (int i = 1; i <= childc; i++) {
      if (bff[bff[i]] == i) {
        dist[i][bff[i]] = INF;
        dist[bff[i]][i] = INF;
      }
    }

    for (int k = 1; k <= childc; k++) {
      for (int i = 1; i <= childc; i++) {
        for (int j = 1; j <= childc; j++) {
          dist[i][j] = min(dist[i][j],
                           dist[i][k] + dist[k][j]);
        }
      }
    }

    for (int i = 1; i <= childc; i++) {
      for (int j = 1; j <= childc; j++) {
        if (dist[i][j] != INF) {
          farthest[j] = max(farthest[j], dist[i][j]);
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= childc; i++) {
      if (!col[i]) {
        int cur = i;
        for (int j = 1; true; j++) {
          col[cur] = i;
          gen[cur] = j;

          if (col[bff[cur]] == col[cur]) {
            ans = max(ans, gen[cur] - gen[bff[cur]] + 1);
            break;
          } else if (col[bff[cur]]) {
            break;
          }
        
          cur = bff[cur];
        }
      }
    }

    for (int i = 1; i <= childc; i++) {
      if (bff[bff[i]] == i) {
        ans = max(ans, farthest[i] + farthest[bff[i]] + 2);
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
