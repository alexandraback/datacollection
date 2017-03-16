#include<cstdio>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<iostream>

#define SC(a) scanf("%d", &a)
#define SCC(a) scanf("%c", &a)
#define SC2(a, b) scanf("%d%d", &a, &b)
#define SC3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define PR(a) printf("%d\n", a)
#define FORE(a, b, c) for(int c=int(a); c<= int(b); ++c)
#define FORD(a, b, c) for(int c=int(a); c>= int(b); --c)
#define FORIT(cont_t, cont, it) for(cont_t::iterator it = cont.begin(); it != cont.end(); ++it) 
#define ALL(a) a.begin(), a.end()

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define itr iterator

#define dbg if(0) 
#define prd dbg printf
#define koniec dbg {SCC(c);SCC(c);} return 0;

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef long long ll;
typedef double ld;
typedef unsigned int uint;

const int sto = 103;
const ld duzo = 100000000;

char c;
int n, tn, h, m, t1[sto][sto], t2[sto][sto];
ld vis[sto][sto];
queue<pi> que;

struct comp {
  bool operator() ( pi p1, pi p2) const {
  ld rozn = vis[p1.xx][p1.yy] - vis[p2.xx][p2.yy];
  return rozn < 0 || (rozn == 0 && p1 < p2);
}
};
  
int move_type(ld h1, int i1, int j1, int i2, int j2) {
  if(t2[i2][j2] - t1[i2][j2] < 50) return 0;
  if(t2[i2][j2] - t1[i1][j1] < 50) return 0;
  if(t2[i1][j1] - t1[i2][j2] < 50) return 0;
  
  int out = 0;
  if(h1 - t1[i1][j1] >= 20) out = 1;
  else out = 10;
  if(t2[i2][j2] - h1 < 50) out =- out;
  return out;
}

bool correct(pi par, int dx, int dy) {
  if(par.xx+dx < 1 || par.xx+dx > n) return 0;
  if(par.yy+dy < 1 || par.yy+dy > m) return 0;
  return 1;
}

void compute(int ti) {
  SC3(h,n,m);
  FORE(1, n, i)
    FORE(1, m, j)
      SC(t2[i][j]);
  FORE(1, n, i)
    FORE(1, m, j)
      SC(t1[i][j]);
  FORE(1, n, i)
    FORE(1, m, j)
      vis[i][j] = duzo;
  
  que = queue<pi>();
  que.push(mp(1,1));
  vis[1][1] = 0;
  
  set<pi, comp> dij;
  
  while(!que.empty()) {
    pi now = que.front();
    que.pop();
    FORE(-1, 1, dx) FORE(-1, 1, dy) if(dx != 0 || dy != 0) if(dx == 0 || dy == 0)
      if(correct(now, dx, dy) && vis[now.xx+dx][now.yy+dy] != 0) {
        int move = move_type(h, now.xx, now.yy, now.xx+dx, now.yy+dy);
        if(move > 0) {
          que.push(mp(now.xx+dx, now.yy+dy));
          vis[now.xx+dx][now.yy+dy] = 0;
          prd("Visit1 %d %d\n", now.xx+dx, now.yy+dy);
        }
        if(move < 0) {
          pi now2 = mp(now.xx+dx, now.yy+dy);
          if (dij.find(now2) != dij.end()) dij.erase(now2);
          ld h1 = t2[now.xx+dx][now.yy+dy] - 50;
          vis[now.xx+dx][now.yy+dy] = min(vis[now.xx+dx][now.yy+dy], move_type(h1, now.xx, now.yy, now.xx+dx, now.yy+dy) + (h - h1) / 10);
          dij.insert(now2);
          prd("Visit2 %d %d %f (%d) \n", now.xx+dx, now.yy+dy, vis[now.xx+dx][now.yy+dy], move_type(h1, now.xx, now.yy, now.xx+dx, now.yy+dy));
        }
      }
  }
  
  while(!dij.empty()) {
    pi now = *dij.begin();
    prd("now %d %d\n", now.xx, now.yy);
    dij.erase(now);
    FORE(-1, 1, dx) FORE(-1, 1, dy) if(dx != 0 || dy != 0) if(dx == 0 || dy == 0)
      if(correct(now, dx, dy)) {
        ld h1 = h - vis[now.xx][now.yy] * 10;
        ld h2 = t2[now.xx+dx][now.yy+dy] - 50;
        int move = move_type(h1, now.xx, now.yy, now.xx+dx, now.yy+dy);
        ld propo = duzo;
        if(move > 0) propo = vis[now.xx][now.yy] + move;
        if(move < 0) propo = move_type(h2, now.xx, now.yy, now.xx+dx, now.yy+dy) + (h - h2) / 10;
        
        pi now2 = mp(now.xx+dx, now.yy+dy);
        if(propo < vis[now.xx+dx][now.yy+dy]) {
          if (dij.find(now2) != dij.end()) dij.erase(now2);
          vis[now.xx+dx][now.yy+dy] = propo;
          dij.insert(now2);
          prd("Visit3 %d %d %ld\n", now.xx+dx, now.yy+dy, vis[now.xx+dx][now.yy+dy]);
        }
      }
  }
  
  ld out;
  if(h - vis[n][m] * 10 >= t1[n][m] + 20) out = vis[n][m] + 1;
  else out = vis[n][m] + 10;
  
  cout << "Case #" << ti << ": " << vis[n][m] << endl;
}

int main() {
  SC(tn);
  FORE(1, tn, ti)
    compute(ti);
  return 0;
}

