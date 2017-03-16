#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

#define REPN(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define RREPN(i, a, b) for(int i = (int)(b); i >= (int)(a); i--)
#define REP(i, n) REPN(i, 0, n)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

const int inf = INT_MAX / 3;
const double eps = 1e-8;

int memo[1000][1000];
int last[1000][1000];

const int dx[] = { 1, 0,-1, 0};
const int dy[] = { 0, 1, 0,-1};
const char* hoge = "ENWS";

int main() {

  int T;
  scanf("%d", &T);

  REPN(tc, 1, T + 1) {

    int X, Y;
    scanf("%d %d", &X, &Y);
    X += 500; Y += 500;

    memset(memo, -1, sizeof(memo));
    memset(last, -1, sizeof(last));
    queue<PII> q;
    q.push(PII(500, 500)); 
    memo[500][500] = 0;
    while(!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      // printf("x = %d y = %d\n", x - 500, y - 500);
      if(x == X && y == Y) {
        // printf("hoge\n");
        break;
      }
      REP(i, 4) {
        int step = memo[x][y] + 1;
        int nx = x + dx[i] * step, ny = y + dy[i] * step;
        // printf("(%d %d), %d\n", nx, ny, step);
        if(abs(nx - 500) > 500 || abs(ny - 500) > 500) continue;
        if(memo[nx][ny] >= 0) continue;
        q.push(PII(nx, ny));
        memo[nx][ny] = step;
        last[nx][ny] = i;
      }
    }

    string res = "";
    int x = X, y = Y;
    while(!(x == 500 && y == 500)) {
      int step = memo[x][y];
      int dir = last[x][y];
      //printf("%d %d %d dir=%d\n", x - 150, y - 150, step, dir);
      res = hoge[dir] + res;
      // printf("%s\n", res.c_str());
      x = x - dx[dir] * step;
      y = y - dy[dir] * step;
    }
    printf("Case #%d: %s\n", tc, res.c_str());
  }

  return 0;
}
