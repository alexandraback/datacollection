#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:16777216")
#endif

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
// #include <sys/time.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi(n) fo(i, n)
#define fj(n) fo(j, n)
#define fk(n) fo(k, n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)a; i<(int)b; i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define x first
#define y second
#define me (*this)
#define PQ(t) priority_queue< t, vector< t >, greater< t > >
#define CLR(a, v) memset(a, v, sizeof(a))
#define UNIQUE(a) srt(a), a.resize(unique(all(a))-a.begin())
#define RAND (((double)rand()/RAND_MAX) + ((double)rand()/RAND_MAX/RAND_MAX))
#define assert(cond,msg) if(!(cond)){ fprintf(stderr, "assert failed at line %d: %s\n", __LINE__, msg); exit(1); }

typedef long long ll;
typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector< vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< double > vd;
typedef vector< vd > vvd;
typedef vector< ll > vll;
typedef vector< string > vs;
typedef vector< bool > vb;
const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f){ return (t>f) ? (t=f, 1) : 0; }
template<class T> int chmax(T &t, T f){ return (t<f) ? (t=f, 1) : 0; }

inline int getint() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}





int isPal(ll x){
  vi a;
  while(x){
    a.pb(x%10);
    x /= 10;
  }
  int pal = 1;
  fd(i,sz(a)/2)
    if(a[i] != a[sz(a)-1-i])
      pal = 0;
  return pal;
}

ll sqrt(ll x){
  ll lo=0, hi=min(ll(1e8),x+1);
  while(hi-lo > 1){
    ll mid = (lo+hi)/2;
    if(mid*mid > x)
      hi = mid;
    else
      lo = mid;
  }
  return lo;
}

int fns(ll x){
  ll s = sqrt(x);
  return s*s==x && isPal(x) && isPal(s);
}

int _fns[1<<24], sum[1<<24];

void myCode() {

  fr(i,1,1<<24)
    if(isPal(i) && isPal(ll(i)*i)){
      _fns[i] = 1;
    }
  sum[0] = _fns[0];
  fr(i,1,1<<24)
    sum[i] = sum[i-1] + _fns[i];

  int ttt=getint();
  fo(tt,ttt){
    ll a, b;
    cin >> a >> b;
    int sa=sqrt(a), sb=sqrt(b);
    if(sa*sa != a)
      ++sa;
    printf("Case #%d: %d\n", tt+1, sum[sb]-sum[sa-1]);
  }
}

int main() {
/*
  // seed the random number generator with microseconds
  struct timeval tv;
  gettimeofday(&tv, NULL);
  srand(tv.tv_usec);
*/
  myCode();
  return 0;
}

