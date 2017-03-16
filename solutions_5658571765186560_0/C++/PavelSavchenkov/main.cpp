#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

const ld EPS = 1e-9;

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

int a[6][6];
int field[22][22];
bool was[22][22];
int x, n, m;

int dfs(int i, int j) {
  int sz = 1;
  was[i][j] = true;
  forn(k, 4) {
    int ii = i + di[k];
    int jj = j + dj[k];

    if  (0 <= ii && ii < n && 0 <= jj && jj < m && !was[ii][jj] && !field[ii][jj]) {
      sz += dfs(ii, jj);
    } 
  }
  return sz;
}

int dfs2(int i, int j) {
  was[i][j] = true;
  int sz = 1;
  forn(k, 4) {
    int ii = i + di[k];
    int jj = j + dj[k];

    if  (0 <= ii && ii < x && 0 <= jj && jj < x && !was[ii][jj] && a[ii][jj]) {
      sz += dfs2(ii, jj);
    } 
  }
  return sz;
}

bool one_comp() {
  memset (was, false, sizeof was);
  forn(i, x) forn(j, x) {
    if  (a[i][j] && !was[i][j]) {
      int sz = dfs2(i, j);
      return sz == x;
    }
  }
  return false;
}

bool is_bad_field() {
  memset (was, false, sizeof was);
  forn(ii, n) forn(jj, m) {
    if  (!was[ii][jj] && !field[ii][jj]) {
      int sz = dfs(ii, jj);
      if  (sz % x) {
        return true;
      }
    }
  }
  return false;
}

int na[6][6];

void rotate90() {
  forn(i, x) forn(j, x)
    na[j][i] = a[i][j];
  forn(i, x) forn(j, x / 2) swap(na[i][j], na[i][x - j - 1]);
  forn(i, x) forn(j, x) a[i][j] = na[i][j];  
}

bool can_win(int i, int j, int have) {
  if  (have > x) {
    return false;
  }

  if  (j == x) {
    ++i;
    j = 0;
  }

  if  (have == x) {
    if  (!one_comp()) {
      return false;
    }
/*    
    forn(ii, x) {
      forn(jj, x) {
        printf("%d", a[ii][jj]);
      }
      puts("");
    }
    puts("");
*/    

    bool bad_field = true;
    forn(it, 4) {
      forn(i0, n) forn(j0, m) {
        memset (field, 0, sizeof field);
        bool placed = true;
        forn(ii, x) forn(jj, x) {
          if  (a[ii][jj]) {
            int ni = i0 + ii;
            int nj = j0 + jj;
            if  (ni >= n || nj >= m) {
              placed = false;
              break;
            }
            field[ni][nj] = 1;
          }            
        }

        if  (!placed) {
          continue;
        }

        if  (!is_bad_field()) {
          bad_field = false;
        }
      }
      
      rotate90();
    }

    return bad_field;
  }

  if  (i == x) {
    return false;    
  }
  
  if  (j == 0 && i > 1) {
    bool was = false;
    forn(jj, x) {
      if  (!a[i - 1][jj]) {
        was = false;
        continue;
      }
      was |= a[i - 2][jj];
      if  ((jj == x - 1 || !a[i - 1][jj + 1]) && !was) {
        return false;
      }
    }
  }
  

  if  (can_win(i, j + 1, have)) {
    return true;
  }

  a[i][j] = 1;
  bool res = can_win(i, j + 1, have + 1);
  a[i][j] = 0;
  return res;

}

bool solve() {
  if  (x >= 7) {
    return true;
  }

  memset (a, 0, sizeof a);
  return can_win(0, 0, 0);
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  int T;
  scanf("%d", &T);
  forn(tt, T) {
    scanf("%d%d%d", &x, &n, &m);
    printf("Case #%d: ", tt + 1);
    puts(solve() ? "RICHARD" : "GABRIEL");
  }

  return 0;
}
