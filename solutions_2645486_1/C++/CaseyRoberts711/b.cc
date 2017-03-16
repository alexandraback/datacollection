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



/*
const int N = 17;
ll a[1<<(N+1)]; // range of queries is 0..(1<<N)-1

void init(int n){
  fi(1<<(N+1))
    a[i] = INF;
}

// the node i represents the range [l,r), we want to query the range [p,q)
ll _query(int i, int l, int r, int p, int q){
  // node is out of range
  if(l>=q || r<=p)
    return INF;
  // node is entirely in range
  if(l>=p && r<=q)
    return a[i];
  // gotta recurse
  return min(_query(2*i, l, (l+r)/2, p, q), _query(2*i+1, (l+r)/2, r, p, q));
}

ll query(int p, int q){
  return _query(1, 0, 1<<N, p, q);
}

void update(int i, ll x){
  i += 1<<N;
  a[i] = x;
  i /= 2;
  while(i){
    a[i] = min(a[2*i], a[2*i+1]);
    i /= 2;
  }
}
*/
void myCode() {
  int ttt=getint();
  fo(tt,ttt){

    // input
    ll e=getint(), r=getint(), n=getint();
    chmin(r, e);
    vii v;
    fi(n)
      v.pb(ii(getint(), i));
    fi(n)
      if(v[i].x < 0)
        v[i].x = 0;
    srt(v);
    reverse(all(v));

    // we add the r going between indices
    ll ret = 0;
    set<ii> endEnergy, startEnergy;
    endEnergy.insert(ii(-1, e-r));
    startEnergy.insert(ii(n, r));
    fi(sz(v)){
      set<ii>::iterator it_lo, it_hi;
      it_lo = endEnergy.lower_bound(ii(v[i].y, -1));
      --it_lo;
      it_hi = startEnergy.lower_bound(ii(v[i].y+1, -1));
      ll avail = min(e,it_lo->y + r*(v[i].y - it_lo->x));
      ll leave = max(0LL,it_hi->y - r*(it_hi->x - v[i].y));
      endEnergy.insert(ii(v[i].y, leave));
      startEnergy.insert(ii(v[i].y, avail));
      ll use = avail - leave;
      ret += use * v[i].x;
    }

    printf("Case #%d: %lld\n", tt+1, ret);
    
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

