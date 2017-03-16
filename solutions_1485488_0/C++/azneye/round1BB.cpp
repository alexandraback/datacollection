/* 
 * 
 * File:   round1BB.cpp
 * Author: Andy Huang
 * Created on May 5, 2012, 11:27 AM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>

using namespace std;

struct Node {
  int x;
  int y;

  Node(int x, int y) : x(x), y(y) {
  }

};

const int INF = 1000000;
const double eps = 1e-6;
int inith, row, col;
int ceilh[110][110];
int floorh[110][110];
bool moi[110][110];
double ans[110][110];
const char dx[] = {0, 1, 0, -1};
const char dy[] = {1, 0, -1, 0};
queue<Node> q;
vector<Node> start;

double bfs() {
  for (unsigned int i = 0; i < start.size(); i++) {
    int x = start[i].x;
    int y = start[i].y;
    ans[x][y] = 0;
    q.push(Node(x, y));
  }
  while (!q.empty()) {
    Node cur = q.front();
    q.pop();
    //cout << cur.x << "," << cur.y << ":" << ans[cur.x][cur.y] << endl;
    if (cur.x == col && cur.y == row)
      return ans[col][row];
    for (int i = 0; i < 4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      int curwater = inith - (int) (10.0 * ans[cur.x][cur.y] + eps);
      if (curwater < 0)
        curwater = 0;
      double ntime = ans[cur.x][cur.y];
      if (ceilh[nx][ny] - floorh[nx][ny] < 50 || ceilh[nx][ny] - floorh[cur.x][cur.y] < 50
              || ceilh[cur.x][cur.y] - floorh[nx][ny] < 50)
        continue;
      if (ceilh[nx][ny] - curwater >= 50) {
        if (curwater - floorh[cur.x][cur.y] >= 20)
          ntime += 1;
        else
          ntime += 10;
        if (ntime < ans[nx][ny]) {
          ans[nx][ny] = ntime;
          q.push(Node(nx, ny));
        }
      }
      else {
        ntime += (curwater - max(0, ceilh[nx][ny] - 50)) / 10.0;
        curwater = max(0, ceilh[nx][ny] - 50);
        if (curwater - floorh[cur.x][cur.y] >= 20)
          ntime += 1;
        else
          ntime += 10;
        if (ntime < ans[nx][ny]) {
          ans[nx][ny] = ntime;
          q.push(Node(nx, ny));
        }
      }
    }
  }
  return -1337.29;
}

void dfs(int x, int y) {
  moi[x][y] = true;
  start.push_back(Node(x, y));
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (ceilh[nx][ny] - floorh[nx][ny] < 50 || ceilh[nx][ny] - floorh[x][y] < 50
            || ceilh[x][y] - floorh[nx][ny] < 50)
      continue;
    if (ceilh[nx][ny] - inith >= 50 && !moi[nx][ny]) {
      dfs(nx, ny);
    }
  }
}

void solve() {
  scanf("%d %d %d", &inith, &row, &col);
  for (int i = 0; i < 110; i++) {
    for (int j = 0; j < 110; j++) {
      ceilh[i][j] = floorh[i][j] = INF;
      moi[i][j] = false;
      ans[i][j] = INF;
    }
  }
  for (int i = 1; i <= row; i++)
    for (int j = 1; j <= col; j++)
      scanf("%d", &ceilh[j][i]);
  for (int i = 1; i <= row; i++)
    for (int j = 1; j <= col; j++)
      scanf("%d", &floorh[j][i]);
  while (!q.empty())
    q.pop();
  start.clear();
  dfs(1, 1);
//  for (unsigned int i = 0; i < start.size(); i++)
//    cout << start[i].x << "," << start[i].y << endl;
  printf("%.8f\n", bfs());
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++) {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
