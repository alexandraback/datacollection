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


const int maxn = 401;
int keys[maxn];


struct bitset {
  ll x[4];
  bitset() {
    memset(x, 0, sizeof x);
  }

  inline void set(int k) {
    x[k / 64] |= 1ll << (k & 63);
  }

  inline void unset(int k) {
    x[k / 64] &= ~(1ll << (k & 63));
  }

  inline bool is_set(int k) {
    return x[k / 64] >> (k & 63) & 1;
  }

  inline bool operator < (const bitset & t) const {
    int i = 0;
    while (i < 4 && x[i] == t.x[i])
      i++;
    return i == 4 ? 0 : x[i] < t.x[i];
  }
};

set<bitset> already;

int k, n;
int stack[maxn];
int need[maxn];
int get[maxn][maxn];
int g_len[maxn];

bitset now;
bool go(int m) {
  if (m == n) {
    for(int i = 0; i < n; i++) {
      printf("%d ",stack[i]);
    }
    puts("");
    return true;
  }

  if (already.count(now)) return false;
  already.insert(now);

  for(int i = 0; i < n; i++) {
    if (now.is_set(i)) continue;

    if (keys[need[i]] > 0) {
      keys[need[i]]--;
      now.set(i);
      for(int j = 0; j < g_len[i]; j++) {
        keys[get[i][j]]++;
      }

      stack[m] = i + 1;
      if (go(m + 1)) {
        return true;
      }
     
      for(int j = 0; j < g_len[i]; j++) {
        keys[get[i][j]]--;
      }
      now.unset(i);
      keys[need[i]]++;
    }
  }
  return false;
}


void solve() {
  memset(keys, 0, sizeof keys);
  scanf("%d %d", &k, &n);
  
  for(int i = 0; i < k; i++) {
    int x;
    scanf("%d",&x);
    x--;
    keys[x]++;
  }

  for(int i = 0; i < n; i++) {
    scanf("%d",&need[i]), need[i]--;
    scanf("%d",&g_len[i]);
    for(int j = 0; j < g_len[i]; j++) 
      scanf("%d",&get[i][j]), get[i][j]--;
  }

  already.clear();
  now = bitset();

  if (!go(0)) {
    puts("IMPOSSIBLE");
  }
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