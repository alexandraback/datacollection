#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int H,N,M;
int F[100][100];
int C[100][100];
int moveR[100][100];
int moveL[100][100];
int moveT[100][100];
int moveB[100][100];
bool visited[100][100];

struct Point {
  int r,c;
};

struct State {
  int r,c,t;
};

bool operator<(const State& s1, const State& s2) {
  return s1.t > s2.t;
}

int canMoveTime(int y1, int x1, int y2, int x2) {
  if (C[y2][x2] < F[y1][x1] + 50) return -1;
  if (C[y2][x2] < F[y2][x2] + 50) return -1;
  if (C[y1][x1] < F[y2][x2] + 50) return -1;
  if (H <= C[y2][x2] - 50) return 0;
  return H - C[y2][x2] + 50;
}

void init() {
  vector<Point> cur = {{0,0}};
  while(!cur.empty()) {
    vector<Point> next;
    for (const Point& p : cur) {
      if (p.r != 0 && !visited[p.r - 1][p.c] && moveT[p.r][p.c] == 0) {
	next.push_back({p.r - 1, p.c});
	visited[p.r - 1][p.c] = true;
      }
      if (p.r != N-1 && !visited[p.r + 1][p.c] && moveB[p.r][p.c] == 0) {
	next.push_back({p.r + 1, p.c});
	visited[p.r + 1][p.c] = true;
      }
      if (p.c != 0 && !visited[p.r][p.c - 1] && moveL[p.r][p.c] == 0) {
	next.push_back({p.r, p.c - 1});
	visited[p.r][p.c - 1] = true;
      }
      if (p.c != M-1 && !visited[p.r][p.c + 1] && moveR[p.r][p.c] == 0) {
	next.push_back({p.r, p.c + 1});
	visited[p.r][p.c + 1] = true;
      }
    }
    cur = next;
  }
}

double solve(){
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M-1; ++j) {
      moveR[i][j] = canMoveTime(i, j, i, j+1);
      moveL[i][j+1] = canMoveTime(i, j+1, i, j);
    } 
  } 
  for (int i = 0; i < N-1; ++i) {
    for (int j = 0; j < M; ++j) {
      moveB[i][j] = canMoveTime(i, j, i+1, j);
      moveT[i+1][j] = canMoveTime(i+1, j, i, j);
    } 
  }
  visited[0][0] = true;
  init();
  //   for (int i = 0; i < N; ++i) {
  //     for (int j = 0; j < M; ++j) {
  //       cout << visited[i][j] << " ";
  //     }
  //     cout << endl;
  //   }
  if (visited[N-1][M-1]) return 0.0;

  priority_queue<State> cur;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (visited[i][j]) {
	cur.push({i, j, 0});
      }
    } 
  }
  while(!cur.empty()) {
    State st = cur.top();
    cur.pop();
    if (st.r == N-1 && st.c == M-1) return st.t;
    if (st.t != 0 && visited[st.r][st.c]) continue;
    visited[st.r][st.c] = true;
    if (st.r != 0 && !visited[st.r - 1][st.c] && moveT[st.r][st.c] >= 0) {
      int time = max(moveT[st.r][st.c], st.t);
      cur.push({st.r - 1, st.c, time + (H - time >= F[st.r][st.c] + 20 ? 10 : 100)});
    }
    if (st.r != N-1 && !visited[st.r + 1][st.c] && moveB[st.r][st.c] >= 0) {
      int time = max(moveB[st.r][st.c], st.t);
      cur.push({st.r + 1, st.c, time + (H - time >= F[st.r][st.c] + 20 ? 10 : 100)});
    }
    if (st.c != 0 && !visited[st.r][st.c - 1] && moveL[st.r][st.c] >= 0) {
      int time = max(moveL[st.r][st.c], st.t);
      cur.push({st.r, st.c - 1, time + (H - time >= F[st.r][st.c] + 20 ? 10 : 100)});
    }
    if (st.c != M-1 && !visited[st.r][st.c + 1] && moveR[st.r][st.c] >= 0) {
      int time = max(moveR[st.r][st.c], st.t);
      cur.push({st.r, st.c + 1, time + (H - time >= F[st.r][st.c] + 20 ? 10 : 100)});
    }
  }
  return -1;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> H >> N >> M;
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < M; ++k) {
	cin >> C[j][k];
      }
    }
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < M; ++k) {
	cin >> F[j][k];
	visited[j][k] = false;
      }
    }
    printf("Case #%d: %.3f\n", i+1, solve() / 10);
  }
  return 0;
}
