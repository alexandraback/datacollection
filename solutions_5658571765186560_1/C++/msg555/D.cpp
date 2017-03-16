#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define RICHARD "RICHARD\n"
#define GABRIEL "GABRIEL\n"

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

typedef vector<pair<int, int>> xomino;

xomino canon(xomino x) {
  xomino r;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      xomino v = x;
      sort(v.begin(), v.end());
      v.resize(unique(v.begin(), v.end()) - v.begin());
      int mr = v[0].first;
      int mc = v[0].second;
      for (int k = 0; k < v.size(); k++) {
        mr = min(mr, v[k].first);
        mc = min(mc, v[k].second);
      }
      for (int k = 0; k < v.size(); k++) {
        v[k].first -= mr;
        v[k].second -= mc;
      }
      r = max(v, r);

      for (int k = 0; k < x.size(); k++) {
        x[k] = make_pair(-x[k].second, x[k].first);
      }
    }
    for (int j = 0; j < x.size(); j++) {
      x[j].second *= -1;
    }
  }
  return r;
}

int dfs(int r, int c, vector<vector<bool>>& vis) {
  if (r < 0 || r >= vis.size() || c < 0 || c >= vis[r].size() || vis[r][c]) {
    return 0;
  }
  vis[r][c] = true;

  int res = 1;
  for (int i = 0; i < 4; i++) {
    res += dfs(r + dr[i], c + dc[i], vis);
  }
  return res;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int X, N, M;
    cin >> X >> N >> M;

    cout << "Case #" << t << ": ";
    if (X >= 7 || (N * M) % X != 0) {
      cout << RICHARD;
      continue;
    } else if (N >= X + 2 && M >= X + 2) {
      cout << GABRIEL;
      continue;
    }

    vector<xomino> omino;
    omino.push_back(xomino(1, make_pair(0, 0)));

    for (int i = 2; i <= X; i++) {
      set<vector<pair<int, int>>> nomino;
      for (int j = 0; j < omino.size(); j++) {
        for (int k = 0; k < i - 1; k++) {
          for (int dir = 0; dir < 4; dir++) {
            xomino om = omino[j];
            om.push_back(make_pair(om[k].first + dr[dir],
                                   om[k].second + dc[dir]));
            om = canon(om);
            if (om.size() == i) {
              nomino.insert(om);
            }
          }
        }
      }
      omino.assign(nomino.begin(), nomino.end());
    }

    bool gabwins = true;
    for (int i = 0; i < omino.size(); i++) {
      xomino om = omino[i];

      bool found = false;
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
          int mr = om[0].first;
          int mc = om[0].second;
          for (int k = 0; k < om.size(); k++) {
            mr = min(mr, om[k].first);
            mc = min(mc, om[k].second);
          }
          for (int k = 0; k < om.size(); k++) {
            om[k].first -= mr;
            om[k].second -= mc;
          }

          for (int offr = 0; offr < N; offr++) {
            for (int offc = 0; offc < N; offc++) {
              vector<vector<bool>> vis(N, vector<bool>(M, false));

              bool ok = true;
              for (int k = 0; k < om.size(); k++) {
                int r = offr + om[k].first;
                int c = offc + om[k].second;
                if (0 <= r && r < N && 0 <= c && c < M) {
                  vis[r][c] = true;
                } else {
                  ok = false;
                }
              }
              if (!ok) {
                continue;
              }

              for (int r = 0; r < N; r++) {
                for (int c = 0; c < M; c++) {
                  if (dfs(r, c, vis) % X != 0) {
                    ok = false;
                  }
                }
              }
              if (ok) {
                found = true;
              }
            }
          }

          for (int k = 0; k < om.size(); k++) {
            om[k] = make_pair(-om[k].second, om[k].first);
          }
        }
        for (int j = 0; j < om.size(); j++) {
          om[j].second *= -1;
        }
      }
      if (!found) {
        gabwins = false;
      }
    }
    if (gabwins) {
      cout << GABRIEL;
    } else {
      cout << RICHARD;
    }
  }
  return 0;
}
