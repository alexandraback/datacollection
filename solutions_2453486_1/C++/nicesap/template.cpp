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


const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

char s[5][5];

bool ok(int u, int v, char c) {
  if (u < 0 || u >= 4 || v < 0 || v >= 4) return false;
  return s[u][v] == c || s[u][v] == 'T';
}

void solve() {
  for(int i = 0; i < 4; i++)
    scanf("%s", s[i]);

  bool full = true;

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      full &= s[i][j] != '.';
      if (s[i][j] == 'X' || s[i][j] == 'O') {

        for(int t = 0; t < 8; t++) {
          int l = 1;
          for(int d = 1; d <= 4; d++) {
            if (ok(i + d * dx[t], j + d * dy[t], s[i][j])) {
              l++;
            } else {
              break;
            }
          } 

          for(int d = 1; d <= 4; d++) {
            if (ok(i - d * dx[t], j - d * dy[t], s[i][j])) {
              l++;
            } else {
              break;
            }
          } 

          if (l == 4) {
            printf("%c won\n", s[i][j]);
            return;
          }
        }
      }
    }
  }
  if (full)
    puts("Draw");
  else
    puts("Game has not completed");
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