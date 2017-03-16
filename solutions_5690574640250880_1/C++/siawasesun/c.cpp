#include <bits/stdc++.h>

using namespace std;

#include <cout.h>

int M, R, C;
const int UndecidedPosition = -2;
const int DecidedMine = -1;

void Input() {
  cin >> R >> C >> M;
}

void PrintMap(const vector<string>& V) {
  cout << endl;
  for (const auto& s : V) cout << s << endl;
}

int Score(const vector<string>& V, int x, int y) {
  if (V[y][x] == '*') return -2;

  int score = 0;
  for (int dy = -1; dy <= 1; dy++) {
    if (y + dy < 0 || y + dy >= R) continue;
    for (int dx = -1; dx <= 1; dx++) {
      if (x + dx < 0 || x + dx >= C) continue;
      if (dy == 0 && dx == 0) continue;

      if (V[y + dy][x + dx] == '*') score++;
    }
  }
  return score;
}

void Open(const vector<string>& V, int x, int y, vector<vector<int> >& S) {
  if (S[y][x] >= 0) return;

  S[y][x] = Score(V, x, y);

  if (S[y][x] == 0) {
    for (int dy = -1; dy <= 1; dy++) {
      if (y + dy < 0 || y + dy >= R) continue;
      for (int dx = -1; dx <= 1; dx++) {
        if (x + dx < 0 || x + dx >= C) continue;
        if (dy == 0 && dx == 0) continue;

        Open(V, x + dx, y + dy, S);
      }
    }
  }
}

int SurroundUndecidedPositions(int x, int y, const vector<vector<int> >& S) {
  int count = 0;
  for (int dy = -1; dy <= 1; dy++) {
    if (y + dy < 0 || y + dy >= R) continue;
    for (int dx = -1; dx <= 1; dx++) {
      if (x + dx < 0 || x + dx >= C) continue;
      if (dy == 0 && dx == 0) continue;

      if (S[y + dy][x + dx] == UndecidedPosition) {
        count++;
      }
    }
  };

  return count;
}

int SurroundDecidedMines(int x, int y, const vector<vector<int> >& S) {
  int count = 0;
  for (int dy = -1; dy <= 1; dy++) {
    if (y + dy < 0 || y + dy >= R) continue;
    for (int dx = -1; dx <= 1; dx++) {
      if (x + dx < 0 || x + dx >= C) continue;
      if (dy == 0 && dx == 0) continue;

      if (S[y + dy][x + dx] == DecidedMine) {
        count++;
      }
    }
  };

  return count;
}

void DecideSurroundMines(vector<vector<int> >& S, int x, int y) {
  for (int dy = -1; dy <= 1; dy++) {
    if (y + dy < 0 || y + dy >= R) continue;
    for (int dx = -1; dx <= 1; dx++) {
      if (x + dx < 0 || x + dx >= C) continue;
      if (dy == 0 && dx == 0) continue;

      if (S[y + dy][x + dx] == UndecidedPosition) {
        S[y + dy][x + dx] = DecidedMine;
      }
    }
  };
}

bool CheckDecidablePositions(const vector<string>& V, vector<vector<int> >& S) {
  bool decided = false;

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (S[y][x] == UndecidedPosition || S[y][x] == DecidedMine || S[y][x] == 0) continue;

      int surround_undecided_positions = SurroundUndecidedPositions(x, y, S);
      if (surround_undecided_positions == 0) continue;
      int surround_decided_mines = SurroundDecidedMines(x, y, S);
      if (surround_undecided_positions == (S[y][x] - surround_decided_mines)) {
        DecideSurroundMines(S, x, y);
        decided = true;
      }
    }
  }

  return decided;
}

bool CanSolve(vector<string> V, int x0, int y0) {
  if (V[y0][x0] == '*') return false;

  queue<pair<int, int> > q;
  vector<vector<int> > S(R, vector<int>(C, UndecidedPosition));

  Open(V, x0, y0, S);

  while (true) {
    bool decided = CheckDecidablePositions(V, S);
    if (!decided) break;
  }

  int undecidedSafes = 0;
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (S[y][x] == UndecidedPosition) {
        if (V[y][x] == '.') {
          undecidedSafes++;
        }
      }
    }
  }

  return undecidedSafes == 0;
}

inline void SetMine(vector<string>& S, int k, int W, int H) {
  int x = k % W;
  int y = k / W;
  S[y][x] = '*';
}

void Solve() {
  int W = C, H = R;
  int m = M;
  vector<string> T(R, string(C, '.'));
  for (; m > W && H > 3; m -= W) {
    for (int x = 0; x < W; x++) {
      T[H - 1][x] = '*';
    }
    H--;
  }
  for (; m > H && W > 3; m -= H) {
    for (int y = 0; y < H; y++) {
      T[y][W - 1] = '*';
    }
    W--;
  }
  int N = W * H;

  int s = (1 << m) - 1;
  while (!(s & (1 << N)))
  {
    vector<string> S = T;
    for (int j = 0; j < N; j++) {
      if (s & (1 << j)) {
        SetMine(S, j, W, H);
      }
    }
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        if (CanSolve(S, x, y)) {
          S[y][x] = 'c';
          PrintMap(S);
          return;
        }
      }
    }

    int lo = s & ~(s - 1);
    int lz = (s + lo) & ~s;
    s |= lz;
    s &= ~(lz - 1);
    s |= (lz / lo / 2) - 1;
  }

  printf("\nImpossible\n");
}

int main(int argc, char **argv) {
  int T;
  scanf("%d", &T);

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
  }
  return 0;
}
