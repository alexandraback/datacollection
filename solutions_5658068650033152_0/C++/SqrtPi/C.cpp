#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <regex>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

#define FORI(i,n) for(int i=0; i<(int)(n); ++i)
#define FORIB(i,b,n) for(int i=(int)(b); i<(int)(n); ++i)
#define FORIR(i,n) for(int i=(int)((n)-1); i>=0; --i)
#define FORIBR(i,b,n) for(int i=(int)((n)-1); i>=(int)(b); --i)
#define MP(a,b) make_pair(a,b)
#define MT(a...) make_tuple(a)
#define ALL(L) (L).begin(),(L).end()
#define ALLR(L) (L).rbegin(),(L).rend()
#define SZ(L) (L).size()
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SORTED_PAIR(a,b) MIN(a,b),MAX(a,b)
#define INF (1<<29)
#define EPS (1e-9)

typedef unsigned int uint;
typedef unsigned long long ull;
typedef signed long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

void solve(int t) {
  int n, m, k, cnt = 0;
  cin >> n >> m >> k;
  vvi b(n, vi(m, 0)); //0: Empty, 1: Filled, -1: Out
  for(int i = 0; i < n; ++i) {
    if(b[i][0] != 1) ++cnt;
    b[i][0] = 1;
    if(b[i][m - 1] != 1) ++cnt;
    b[i][m - 1] = 1;
  }
  for(int i = 0; i < m; ++i) {
    if(b[0][i] != 1) ++cnt;
    b[0][i] = 1;
    if(b[n - 1][i] != 1) ++cnt;
    b[n - 1][i] = 1;
  }
  int res = cnt;
  for(int x = n * m; x > k; --x) {
    int mx = 0, my = 0, mv = 100;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        int v = 0;
        if(b[i][j] == 1) {
          if(i > 0 && b[i-1][j] == 0) ++v;
          if(j > 0 && b[i][j-1] == 0) ++v;
          if(i < n - 1 && b[i+1][j] == 0) ++v;
          if(j < m - 1 && b[i][j+1] == 0) ++v;
          if(v < mv) {
            mv = v;
            mx = i; my = j;
          }
        }
      }
    }
    b[mx][my] = -1;
    --cnt;
    if(mx > 0 && b[mx-1][my]==0) { b[mx-1][my] = 1; ++cnt; }
    if(my > 0 && b[mx][my-1]==0) { b[mx][my-1] = 1; ++cnt; }
    if(mx < n - 1 && b[mx+1][my]==0) { b[mx+1][my] = 1; ++cnt; }
    if(my < m - 1 && b[mx][my+1]==0) { b[mx][my+1] = 1; ++cnt; }
    res = min(res, cnt);
  }
  printf("Case #%d: %d\n", t + 1, res);
}

int main() {
  int T;
  scanf("%d", &T);
  FORI(t,T){
    solve(t);
  }
}
