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
/*-----------TEMPLATE---------------*/


const int N = 2000;
vector<int>x[N];

int s[N],s2[N];

bool go(int v, int p, int start)
{
  s2[v]++;
  if(p != start)
    s[v]++;
      
  if (s2[v] >= 2) 
    return true;

  if (s2[v] >= 2)
    return (sz(x[v]) > 0);


  bool ok = false;
  forn(i,sz(x[v]))
    ok |= go(x[v][i],v,start);

  return ok;
}


int main() 
{
  srand(time(NULL));
  #define TASK ""
  #ifdef HOME
  assert(freopen(TASK "in", "rt", stdin));
  assert(freopen(TASK "out", "wt", stdout));
  #endif

  int t=1,T;
  for(scanf("%d",&T);t<=T;t++)
  {
    int n;
    scanf("%d",&n);
    bool ok = false;
    forn(i,n)
    {
      x[i].resize(0);
      int m;
      scanf("%d",&m);
      forn(j,m)
      {
        int w;
        scanf("%d",&w);
        w--;
        x[i].pb(w);
      }
    }

    forn(i,n)
    {
      memset(s,0,sizeof s);
      memset(s2,0,sizeof s2);
      if(go(i,i,i))
      {
        ok = true;
        break;
      }
    }  

    printf("Case #%d: ",t);
    if(ok)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}