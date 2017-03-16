#include<cstdio>
#include<queue>
#include<algorithm>
#define infile "tide.in"
#define outfile "tide.out"
#define nMax 103
#define inf 1<<30
#define x first
#define y second
#define pp pair <int, int>

using namespace std;

const int ii[] = {-1, 0, 1, 0};
const int jj[] = {0, 1, 0, -1};

queue < pp > q;
double dp[nMax][nMax];
int f[nMax][nMax];
int h[nMax][nMax];
int w, n, m;

void read(int ma[nMax][nMax]) {
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      scanf("%d", &ma[i][j]);
    }
  }
}

void read() {
  scanf("%d %d %d", &w, &n, &m);
  read(h);
  read(f);
}

void solve() {

  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j <= m; ++j) {
      dp[i][j] = inf;
    }
  }

  dp[1][1] = 0;
  q.push(make_pair(1, 1));

  while(!q.empty()) {

    int x = q.front().x;
    int y = q.front().y;
    double he = w - dp[x][y] * 10;
    q.pop();

    for(int t = 0; t < 4; ++t) {
      int i = x + ii[t];
      int j = y + jj[t];

      if(i > 0 && i <= n && j > 0 && j <= m) {

        if(h[x][y] - 50 < f[i][j]) continue;
        if(max(f[x][y], f[i][j]) + 50 > h[i][j]) continue;

        double toWait = (he + 50 - h[i][j]) / 10;
        if(toWait < 0) toWait = 0;

        int cost = 1 * ((he - toWait * 10) - f[x][y] < 20 ? 10 : 1);

        if(dp[x][y] == 0 && toWait == 0) cost = 0;

        if(dp[x][y] + toWait + cost < dp[i][j]) {
          dp[i][j] = dp[x][y] + toWait + cost;
          q.push(make_pair(i, j));
        }
      }
    }
  }

}

void write(int t) {

  printf("Case #%d: %lf\n", t, dp[n][m]);
}

int main() {
  freopen(infile, "r", stdin);
  freopen(outfile, "w", stdout);

  int t;
  scanf("%d", &t);

  for(int test = 1; test <= t; ++test) {
    read();
    solve();
    write(test);
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}
