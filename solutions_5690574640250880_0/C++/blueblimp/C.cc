#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())
#define FORI(i,v) FOR(i,SZ(v))
typedef long double ld;
typedef long long ll;

//#define dlog printf
#define dlog(...)

int out_R,out_C,out_M;
char out_grid[64][64];

bool transpose;
int R,C,E;
char grid[64][64];

bool compute()
{
  FOR(r,R) FOR(c,C) grid[r][c] = '*';

  grid[0][0] = 'c';

  if (E == 1) {
    return true;
  }

  if (R == 1) {
    for (int c = 1; c < E; ++c) {
      grid[0][c] = '.';
    }
    return true;
  } else if (R == 2) {
    if (E < 4) return false;
    if (E%2 != 0) return false;

    grid[1][0] = '.';
    for (int c = 1; c < E/2; ++c) {
      for (int r = 0; r < R; ++r) {
        if (r || c) grid[r][c] = '.';
      }
    }
    return true;
  } else {
    assert(R >= 3);

    if (E < 4) return false;
    if (E == 5 || E == 7) return false;

    grid[0][1] = grid[1][0] = grid[1][1] = '.';
    if (E == 4) {
      return true;
    }

    grid[0][2] = grid[1][2] = '.';
    if (E == 6) {
      return true;
    }

    assert(E >= 8);
    grid[2][0] = grid[2][1] = '.';

    int rem = E - 8;
    for (int c = 3; c < C; ++c) {
      if (rem < 2) break;
      grid[0][c] = grid[1][c] = '.';
      rem -= 2;
    }
    for (int r = 3; r < R; ++r) {
      if (rem < 2) break;
      grid[r][0] = grid[r][1] = '.';
      rem -= 2;
    }

    for (int r = 2; r < R; ++r) {
      if (rem == 0) break;
      for (int c = 2; c < C; ++c) {
        if (rem == 0) break;
        grid[r][c] = '.';
        --rem;
      }
    }
    assert(rem == 0);

    return true;
  }
}

void doit(int cas)
{
  scanf(" %d %d %d", &out_R, &out_C, &out_M);
  assert(1 <= out_R && out_R <= 50);
  assert(1 <= out_C && out_C <= 50);
  assert(0 <= out_M && out_M < out_R*out_C);

  transpose = out_R > out_C;

  if (transpose) {
    R = out_C;
    C = out_R;
  } else {
    R = out_R;
    C = out_C;
  }
  E = R * C - out_M;
  dlog("R=%d, C=%d, E=%d\n", R, C, E);

  bool possible = compute();

  printf("Case #%d:\n", cas);

  if (!possible) {
    printf("Impossible\n");
    return;
  }

  if (transpose) {
    FOR(r,R) FOR(c,C) {
      out_grid[c][r] = grid[r][c];
    }
  } else {
    FOR(r,R) FOR(c,C) {
      out_grid[r][c] = grid[r][c];
    }
  }

  FOR(r, out_R) {
    FOR(c, out_C) {
      printf("%c", out_grid[r][c]);
    }
    printf("\n");
  }

  int mines = 0;
  FOR(r,R) FOR(c,C) {
    if (grid[r][c] == '*') ++mines;
  }
  assert(mines == out_M);
}

int T;
int main() {
  scanf(" %d", &T);
  assert(1 <= T && T <= 230);
  FOR(cas,T) doit(cas+1);
  return 0;
}
