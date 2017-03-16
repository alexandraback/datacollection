#include <bits/stdc++.h>

using namespace std;

/*
This one..
###
# #
##
 */

const char first[] = "RICHARD";
const char second[] = "GABRIEL";


vector<string> rotate(vector<string> g) {
  vector<string> gg(g[0].size(), string(g.size(), 0));
  for(int i = 0; i < (int)g.size(); ++i) {
    for(int j = 0; j < (int)g[i].size(); ++j) {
      gg[j][g[i].size() - i - 1] = g[i][j];
    }
  }
  return gg;
}

vector<string> reflect(vector<string> g) {
  for(int i = 0; i < (int)g.size(); ++i) {
    for(int j = 0; j + j < (int)g[i].size(); ++j) {
      swap(g[i][j], g[i][g[i].size() - j - 1]);
    }
  }
  return g;
}

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

// BRUTE FORCE!
namespace generate {

int n;
set<vector<string> > comb[7];

vector<string> trim(const vector<string> &g) {
  int minI = g.size(), maxI = 0;
  int minJ = g[0].size(), maxJ = 0;
  for(int i = 0; i < (int)g.size(); ++i) {
    for(int j = 0; j < (int)g[i].size(); ++j) {
      if(g[i][j] == '*') {
        minI = min(minI, i); maxI = max(maxI, i);
        minJ = min(minJ, j); maxJ = max(maxJ, j);
      }
    }
  }
  vector<string> r;
  for(int i = minI; i <= maxI; ++i) {
    r.push_back("");
    for(int j = minJ; j <= maxJ; ++j) {
      r.back() += g[i][j];
    }
  }
  return r;
}

void solve(vector<string> g, int rem) {
  if(rem == 0) {
    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 2; ++j) {
        if(comb[n].count(trim(g))) return;
        g = reflect(g);
      }
      g = rotate(g);
    }
    comb[n].insert(trim(g));
    return;
  }
  for(int i = 0; i < (int)g.size(); ++i) {
    for(int j = 0; j < (int)g[i].size(); ++j) {
      if(g[i][j] == '*') {
        for(int k = 0; k < 4; ++k) {
          int ii = i + di[k];
          int jj = j + dj[k];
          if(ii < 0 || ii >= (int)g.size() || jj < 0 || jj >= (int)g[0].size() || g[ii][jj] == '*') continue;
          g[ii][jj] = '*';
          solve(g, rem - 1);
          g[ii][jj] = '.';
        }
      }
    }
  }
}
void doIt() {
  for(n = 1; n < 7; ++n) {
    vector<string> g(n, string(n, '.'));
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        g[i][j] = '*';
        solve(g, n - 1);
        g[i][j] = '.';
      }
    }
  }
}
}

int x, r, c;
char work[22][22];

int dfs(int i, int j) {
  work[i][j] = '*';
  int res = 1;
  for(int k = 0; k < 4; ++k) {
    int ii = i + di[k];
    int jj = j + dj[k];
    if(ii < 0 || ii >= r || jj < 0 || jj >= c || work[ii][jj] == '*') {
      continue;
    }
    res += dfs(ii, jj);
  }
  return res;
}

bool check() {
  bool ok = true;
  for(int i = 0; i < r; ++i) {
    for(int j = 0; j < c; ++j) {
      if(work[i][j] == '*') {
        continue;
      }
      ok &= dfs(i, j) % x == 0;
    }
  }
  return ok;
}

int main() {
  freopen("D.in", "rt", stdin);
  freopen("D.out", "wt", stdout);
  generate::doIt();
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    scanf("%d %d %d", &x, &r, &c);
    printf("Case #%d: ", test);
    if(x > 6 || (x > r && x > c) || r * c % x > 0) {
      puts(first);
    }else if(x < 3) {
      puts(second);
    }else {
      bool willWin = true;
      for(auto g : generate::comb[x]) {
        bool found = false;
        for(int rot = 0; rot < 4; ++rot) {
          for(int ref = 0; ref < 2; ++ref) {
            for(int i = 0; i + (int)g.size() <= r; ++i) {
              for(int j = 0; j + (int)g[0].size() <= c; ++j) {
                memset(work, '.', sizeof work);
                for(int ii = 0; ii < (int)g.size(); ++ii) {
                  for(int jj = 0; jj < (int)g[ii].size(); ++jj) {
                    work[i + ii][j + jj] = g[ii][jj];
                  }
                }
                if(check()) {
                  found = true;
                  break;
                }
              }
              if(found) {
                break;
              }
            }
            if(found) {
              break;
            }
            g = reflect(g);
          }
          if(found) {
            break;
          }
          g = rotate(g);
        }
        if(!found) {
          willWin = false;
          break;
        }
      }
      puts(willWin ? second : first);
    }
  }
  return 0;
}
