#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 105;

int h, n, m, floor[MAXN][MAXN], ceiling[MAXN][MAXN];

int dr[] = {-1, 0, +1, 0}, dc[] = {0, +1, 0, -1};

bool okay[MAXN][MAXN][4];

inline bool can_go(int hc, int hf, int tc, int tf) {
  return hf + 50 <= tc && tf + 50 <= tc && tf + 50 <= hc;
}

inline bool accessible(int water, int tc) {
  return water + 50 <= tc;
}

inline int time(int water, int hf) {
  return hf + 20 <= water ? 10 : 100;
}

int best[MAXN][MAXN];

priority_queue< pair<int, pair<int, int> > > q;

void add(int r, int c, int t) {
  if (t < best[r][c] || best[r][c] == -1) {
    best[r][c] = t;
    q.push(make_pair(-t, make_pair(r, c)));

    for (int d = 0; d < 4; d++) {
      int nr = r + dr[d], nc = c + dc[d];
      if (okay[r][c][d]) {
        int nt = h - (ceiling[nr][nc] - 50);
        if (nt > t) {
          q.push(make_pair(-nt, make_pair(r, c)));
        }
      }
    }
  }
}

void flood_fill(int r, int c) {
  if (best[r][c] != -1) return;

  add(r, c, 0);

  for (int d = 0; d < 4; d++) {
    int nr = r + dr[d], nc = c + dc[d];
    if (okay[r][c][d] && accessible(h, ceiling[nr][nc]))
      flood_fill(nr, nc);
  }
}

void solve() {
  cin >> h >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> ceiling[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> floor[i][j];

  for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
      for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];

        okay[r][c][d] = (nr >= 0 && nr < n && nc >= 0 && nc < m && can_go(ceiling[r][c], floor[r][c], ceiling[nr][nc], floor[nr][nc]));
      }

  while (!q.empty()) q.pop();

  for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
      best[r][c] = -1;

  flood_fill(0, 0);


  while (!q.empty()) {
    int t = -q.top().first;
    int r = q.top().second.first;
    int c = q.top().second.second;
    q.pop();

    if (r == n - 1 && c == m - 1) {
      cout << t / 10 << "." << t % 10 << "\n";
      return;
    }

    for (int d = 0; d < 4; d++) {
      int nr = r + dr[d], nc = c + dc[d];
      if (okay[r][c][d] && accessible(h - t, ceiling[nr][nc]))
        add(nr, nc, t + time(h - t, floor[r][c]));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}


