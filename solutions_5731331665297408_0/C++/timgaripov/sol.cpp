#include <cstdio>
#include <cassert>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100;
const int maxl = 10;
const int maxans = 1000;


int n, m;

char s[maxn][maxl];
char ans[maxans], cur[maxans];


vector<int> g[maxn];
bool was[maxn];
bool fs;


pair<int, int> st[2 * maxn];
int stl;
void brute(int cnt, int stl, int u) {
    //printf("VERTEX %d(%d)[%s]\n", u, cnt, cur);
    if (cnt == n) {            
      //printf("STR %s\n", cur);
      if (fs || (strcmp(cur, ans) < 0)) {
        fs = false;
        int x = strlen(cur);
        for (int i = 0; i < x; i++)
          ans[i] = cur[i];
        ans[x] = 0;
      }
      return;
    }
    for (int i = 0; i < int(g[u].size()); i++) {
      int v = g[u][i];
      pair<int, int> p = make_pair(v, u);
      if ((stl > 0) && (st[stl - 1] == p)) {
        pair<int, int> x = st[stl - 1];
        brute(cnt, stl - 1, v);
        st[stl - 1] = x;
      }
      if (was[v])
        continue;
      was[v] = true;
      for (int j = 0; j < 5; j++)
        cur[cnt * 5 + j] = s[v][j];
      cur[cnt * 5 + 5] = 0;      
      p = make_pair(u, v);
      st[stl] = p;
      brute(cnt + 1, stl + 1, v);
      was[v] = false;
    }
}

int main() {
  
  
  int tests;
  assert(scanf("%d", &tests) == 1);
  for (int test = 0; test < tests; test++) {
    printf("Case #%d: ", test + 1);
    assert(scanf("%d %d", &n, &m) == 2);
    for (int i = 0; i < n; i++) {
      assert(scanf(" %s", s[i]) == 1);
      //printf("CODE %s\n", s[i]);
      g[i].clear();
      was[i] = false;
    }
    for (int i = 0; i < m; i++) {
      int x, y;
      assert(scanf("%d %d", &x, &y) == 2);
      x--; y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    fs = true;
    for (int i = 0; i < n; i++) {
      was[i] = true;
      for (int j = 0; j < 5; j++)
        cur[j] = s[i][j];
      cur[5] = 0;
      //printf("BRUTE %d\n", i);   
      brute(1, 0, i);
      was[i] = false;
    }
    printf("%s\n", ans);
  }
  
  return 0;
}