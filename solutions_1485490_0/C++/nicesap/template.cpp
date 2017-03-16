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


const int N = 200;
ll a[N],b[N];
int A[N],B[N];


vector<int>bits(int x)
{
  vector<int> ans;
  forn(i,3)
    if(x>>i&1)
      ans.pb(i);
  return ans;
}


ll ans[N][N];

int n,m;

ll solve(vector<int>pr)
{
  vector<pair<ll,int> >na;
  forn(i,sz(pr))
  {
    if (sz(na)!=0 && na[sz(na)-1].Y == A[pr[i]])
    {
      na[sz(na)-1].X += a[pr[i]];
    } 
    else
    {
      na.pb(mp(a[pr[i]],A[pr[i]]));
    }
  }
  forn(i,N)
    forn(j,N)
      ans[i][j] = -(1ll<<60);

  ans[0][0] = 0;
  forn(i,sz(na))
  { 
    forn(j,m)
    {
      ll add = 0;
      for(int j2=j+1;j2<=m;j2++)
      {
        add += B[j2-1] == na[i].Y ? b[j2-1] : 0;
        ans[i+1][j2] = max(ans[i+1][j2], ans[i][j] + min(add, na[i].X));
      }
    }
  }
  return ans[sz(na)][m];
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
    scanf("%d %d",&n,&m);
    forn(i,n)
      scanf("%I64d%d",&a[i],&A[i]);
    forn(i,m)
      scanf("%I64d%d",&b[i],&B[i]);

    ll best = 0;
    forn(mask,8)
      best = max(best, solve(bits(mask)));
    printf("Case #%d: %I64d\n",t,best);
  }
return 0;
}