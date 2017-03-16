#include <cstdio>
#include <cassert>
#include <cstring>

#define MAX_MOVES 500

using namespace std;

typedef long long ll;

#define MAX_MOVES 500
char moves[MAX_MOVES+1] = {0};
ll X, Y;

int dx[] = { 0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0};
char dc[] = { 'N', 'S', 'E', 'W' };

bool dfs(int x, int y, int d, int md) {
  if (x == X && y == Y) return true;
  if (d == md) return false;

  for (int i = 0; i < 4; ++i) {
    moves[d] = dc[i];
    if (dfs(x + dx[i]*(d+1), y + dy[i]*(d+1), d+1, md))
      return true;
  }
  moves[d] = '\0';
  return false;
}

int gowest(int c, int i) {
  // east-west goes one step west
  for (int j = 0; j < c; ++j) {
    moves[i++] = 'E';
    moves[i++] = 'W';
  }
  return i;
}
int goeast(int c, int i) {
  // west-east goes one step east
  for (int j = 0; j < c; ++j) {
    moves[i++] = 'W';
    moves[i++] = 'E';
  }
  return i;
}

int gonorth(int c, int i) {
  for (int j = 0; j < c; ++j) {
    moves[i++] = 'S';
    moves[i++] = 'N';
  }
  return i;
}
int gosouth(int c, int i) {
  for (int j = 0; j < c; ++j) {
    moves[i++] = 'N';
    moves[i++] = 'S';
  }
  return i;
}



void solve(int tc) {
  scanf("%lld %lld", &X, &Y);

/*  bool found = false;
  for (int md = 1; md < MAX_MOVES && !found; ++md) {
    found = dfs(0,0,0,md);
  }
  assert(found == true);
  */

  memset(moves, 0, sizeof moves);
  int i = 0;
  if (X < 0) {
    i = gowest(-X, i);
  } else {
    i = goeast(X, i);
  }
  if (Y < 0) {
    i = gosouth(-Y, i);
  } else {
    i = gonorth(Y, i);
  }
  assert(i < 500);

  printf("Case #%d: %s\n", tc, moves);
}

int main() {
  int N;
  scanf("%d\n", &N);
  for (int tc = 1; tc <= N; ++tc)
    solve(tc);
  return 0;
}
