#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
//{{{Commonly used macro
//-----------------------By cylixstar-----------------------//
#define REP(i, n) for (int n_##__LINE__= (n), i = 0; i < n_##__LINE__; ++i)
#define FOR(i, f, t) for (__typeof__(f) f_##__LINE__=(f), t_##__LINE__=(t), i = f_##__LINE__; i <= t_##__LINE__; ++i)
#define TR(c, it) for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define SZ(a) ((int)(a).size())
#define CLR(a, v) do { memset(a, v, sizeof(a)); } while(0)
#define DBG(a) do { std::cout << "[" << __FUNCTION__ << "]" << #a << ": " << a << endl; } while(0)

template<typename T>
inline void checkMax(T& a, const T& b) {
  if (a < b) a = b;
}

template<typename T>
inline void checkMin(T& a, const T& b) {
  if (a > b) a = b;
}

//}}}
const int kMaxN = 100 + 10;

struct Node {
  int is_col, val, idx;
  Node(int c, int v, int i):is_col(c), val(v), idx(i){}
  Node(){}
  bool friend operator < (const Node &p1,const Node& p2) {
    return p1.val > p2.val;
  }
};
int n, m;
bool remv[2][kMaxN];
int lawn[kMaxN][kMaxN];
pair<int, pair<int, int> > cell_list[kMaxN * kMaxN];

int check(int x, int y) {
  bool is_col = true;
  REP (i, n) {
    if (remv[0][i]) continue;
    if (lawn[i][y] != lawn[x][y]) {
      is_col = false;
      break;
    }
  }
  if (is_col) return 1;
  REP (j, m) {
    if (remv[1][j]) continue;
    if (lawn[x][j] != lawn[x][y]) return 2;
  }
  return 0;
}

void pre() {
  sort(cell_list, cell_list + n * m);
  fill(remv[0], remv[0] + n, false);
  fill(remv[1], remv[1] + m, false);
}
void go() {
  REP (i, n * m) {
    pair<int, int> pos = cell_list[i].second;
    //printf("%d %d %d\n", cell_list[i].first, pos.first, pos.second);
    int x, y;
    x = pos.first, y = pos.second;
    if (remv[0][x] || remv[1][y]) continue;
    int t = check(x, y);
    if (t == 2) {
      puts("NO");
      return;
    }
    if (t==0) remv[0][x] = true;
    else remv[1][y] = true;
  }
  puts("YES");
}
int main() {
  int n_case;
  scanf("%d", &n_case);
  REP (idx_case, n_case) {
    printf("Case #%d: ", idx_case + 1);
    scanf("%d%d", &n, &m);
    int x;
    REP (i, n) REP (j, m) {
      scanf("%d", &x);
      lawn[i][j] = x;
      cell_list[i * m + j] = make_pair(x, make_pair(i, j));
    }
    pre();
    go();
  }
  return 0;
}

