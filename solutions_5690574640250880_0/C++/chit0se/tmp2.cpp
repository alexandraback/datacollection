#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define pb         push_back
#define all(a)     (a).begin(),(a).end()
#define sz(a)      (int)((a).size())
#define rep(i,n)   for(int i=0; i<n; ++i)
#define REP(i,j,k) for(int i=j; i<k; ++i)
#define each(a,b)  for (__typeof((a).begin()) b=(a).begin(); b!=(a).end(); b++)

typedef long long ll;
typedef vector<string> CS;

int dy[8] = {-1, -1, -1,  0,  0,  1,  1,  1};
int dx[8] = {-1,  0,  1, -1,  1, -1,  0,  1};

int r, c, m;

bool OK(int y, int x) {
  return (y >= 0 && x >= 0 && y < r && x < c);
}

void check(CS &g, CS &h, int sy, int sx) {
  queue<int> q;
  q.push(sy);
  q.push(sx);

  while (!q.empty()) {
    int y = q.front(); q.pop();
    int x = q.front(); q.pop();
    if (h[y][x] != '.') continue;

    int a = 0;
    rep (i, 8) {
      int ny = y + dy[i], nx = x + dx[i];
      if (OK(ny, nx)) a += (g[ny][nx]=='*');
    }
    h[y][x] = a+'0';
    if (a > 0) continue;
    rep (i, 8) {
      int ny = y + dy[i], nx = x + dx[i];
      if (OK(ny, nx)) {
        if(h[ny][nx] == '.') {
          q.push(ny);
          q.push(nx);
        }
      }
    }
  }
}

bool solve () {
  rep (p, 1<<(r*c)) {
    int e = 0;
    CS g(r,  string(c, '.'));

    rep (i, r) rep (j, c) if ((p>>(i*c+j))&1) {
      g[i][j] = '*';
      e++;
    }

    if (e!=m) continue;

    rep (y, r) rep (x, c) {
      CS h2(r, string(c, '.'));
      if (g[y][x] != '*') {

        check(g, h2, y, x);

        rep (i, r) rep (j, c) {
          if (g[i][j]=='*') h2[i][j] = '9';
        }
        int e2 = 0;
        rep (i, r) rep (j, c) e2 += (h2[i][j]=='.');
        if (e2 == 0) {
          g[y][x] = 'c';
          rep (i, r) cout << g[i] << endl;
          return true;
        }
      }
    }
  }
  return false;
}

int main () {
  int T; cin >> T;
  rep (t, T) {
    cin >> r >> c >> m;
    bool bad = (r>1&&c>1&&(r*c-m<4));
    if (r*c-m==1) bad = false;
    cout << "Case #" << t+1 << ": " << endl;
    if (bad || !solve()) cout << "Impossible" << endl;
  }
  return 0;
}

