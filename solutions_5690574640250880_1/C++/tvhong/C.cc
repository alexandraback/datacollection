#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 55;
int T, r, c, m, nreach;
int seen[N][N];
char board[N][N];

bool validi(int i) {
  return (i>=0 && i<r);
}
bool validj(int j) {
  return (j>=0 && j<c);
}

void print_board() {
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

void DFS(int i, int j) {
  if (seen[i][j]) return;
  seen[i][j] = 1;
  nreach++;
  int cnt = 0;
  for (int di=-1; di<=1; di++) {
    for (int dj=-1; dj<=1; dj++) {
      if (di == 0 && dj == 0) continue;
      if (validi(i+di) && validj(j+dj)) 
        if (board[i+di][j+dj] == '*')
          cnt++;
    }
  }
  if (cnt > 0) return;
  for (int di=-1; di<=1; di++) {
    for (int dj=-1; dj<=1; dj++) {
      if (di == 0 && dj == 0) continue;
      if (!validi(i+di) || !validj(j+dj)) continue;
      DFS(i+di, j+dj);
    }
  }
}

int main() {
  scanf("%d", &T);
  for (int t=1; t<=T; t++) {
    for (int i=0; i<N; i++)
      for (int j=0; j<N; j++) {
        board[i][j] = '.';
        seen[i][j] = 0;
      }
    printf("Case #%d:\n", t);
    scanf("%d %d %d", &r, &c, &m);
    //printf("%d %d %d", r, c, m);
    int mm = m;
    int sr = 0, sc = 0;
    if (c > r) {
      for (int j=0; mm && j<c-r; j++) {
        for (int i=0; mm && i<r; i++) {
          if (i==r-2 && mm == 1) break;
          board[i][j] = '*';
          mm--;
        }
      }
      sc = c - r;
    }
    if (r > c) {
      for (int i=0; mm && i<r-c; i++) {
        for (int j=0; mm && j<c; j++) {
          if (j==c-2 && mm == 1) break;
          board[i][j] = '*';
          mm--;
        }
      }
      sr = r - c;
    }
    for (int k=0; mm && k<min(c, r); k++) {
      for (int i=sr+k; mm && i<r; i++) {
        if (i==r-2 && mm == 1) break;
        board[i][sc+k] = '*';
        mm--;
      }
      for (int j=sc+k+1; mm && j<c; j++) {
        if (j==c-2 && mm == 1) break;
        board[sr+k][j] = '*';
        mm--;
      }
    }
    //printf("Good\n");
    //print_board();
    board[r-1][c-1] = 'c';
    nreach = 0;
    DFS(r-1, c-1);
    //printf("%d %d %d %d\n", r, c, m, nreach);
    if (nreach == r*c - m) {
      print_board();
    } else {
      printf("Impossible\n");
    }
  }
  return 0;
}
