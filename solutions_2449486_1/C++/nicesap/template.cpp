/*-----------TEMPLATE---------------*/
//#pragma comment(linker, "/STACK:16777216")

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define forab(i, a, b) for (int i = (int)(a); i < ((int)(b)); ++i)
#define forit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define forn(i, n) for (int i = 0; i < ((int)(n)); ++i)
#define forabok(i, a, b, ok) for (int i = (int)(a); i < ((int)(b)) && (ok); ++i)
#define foritok(it, v, ok) for (typeof((v).begin()) it = (v).begin(); it != (v).end() && (ok); ++it)
#define fornok(i, n, ok) for (int i = 0; i < ((int)(n)) && (ok); ++i)
#define mp make_pair
#define pb push_back
#define sz(a) ((int)((a).size()))
#define X first
#define Y second
#define ibits(x) __builtin_popcount(x)
#define lbits(x) __builtin_popcountll(x)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

/*-----------TEMPLATE---------------*/


const int maxn = 200;
int a[maxn][maxn];
int b[maxn][maxn];

bool ver[maxn];
bool gor[maxn];

void solve() {
  int n,m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      scanf("%d", &a[i][j]), b[i][j] = 100;

  bool ok = true;
  for(int h = 100; ok && h >= 0; h--) {
    for(int i = 0; i < n; i++) {
      gor[i] = true;
      for(int j = 0; j < m; j++)
        gor[i] &= a[i][j] <= h;
    }

    for(int j = 0; j < m; j++) {
      ver[j] = true;
      for(int i = 0; i < n; i++)
        ver[j] &= a[i][j] <= h;
    }

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if (gor[i] || ver[j])
          b[i][j] = h;
        else {
          if (a[i][j] <= h) {
            ok = false;
          }
        }
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      ok &= a[i][j] == b[i][j];

  if (ok) puts("YES");
  else    puts("NO");
}

int main() 
{
  srand(time(NULL));
  #define TASK ""
  #ifdef HOME
  assert(freopen(TASK "in", "rt", stdin));
  assert(freopen(TASK "out", "wt", stdout));
  #endif

  int tests;
  scanf("%d",&tests);
  for(int test = 1; test <= tests; test++) {
    printf("Case #%d: ",test);
    solve();
  }
  return 0;
}