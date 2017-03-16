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




const int N = 20;
int dp[1<<N][N], yo[1<<N][N];
vi keys[1<<N][N];

int chest[N];
vi reward[N];

int haveKey(vi &a, int x){
  fi(sz(a))
    if(a[i] == x)
      return 1;
  return 0;
}

void myCode() {
  int ttt=getint();
  fo(tt,ttt){

    int nk=getint(), n=getint();
    fi(n){
      fj(1<<n){
        dp[j][i] = yo[j][i] = 0;
        keys[j][i] = vi();
      }
      chest[i] = -1;
      reward[i] = vi();
    }
    fi(nk)
      keys[0][0].pb(getint());
    fi(n){
      chest[i] = getint();
      nk = getint();
      fj(nk)
        reward[i].pb(getint());
    }

    // base case
    fi(n)
      if(haveKey(keys[0][0], chest[i])){
        dp[1<<i][i] = INF;
        int passed = 0;
        fo(s,sz(keys[0][0]))
          if(passed || keys[0][0][s] != chest[i])
            keys[1<<i][i].pb(keys[0][0][s]);
          else
            passed = 1;
        fo(s,sz(reward[i]))
          keys[1<<i][i].pb(reward[i][s]);
      }

    // tsp
    fi(1<<n)
      fj(n) if(i & (1<<j)) if(dp[i][j])
        fk(n) if(!(i & (1<<k))) if(!dp[i|(1<<k)][k]) if(haveKey(keys[i][j],chest[k])){
          dp[i|(1<<k)][k] = 1;
          int passed = 0;
          fo(s,sz(keys[i][j]))
            if(passed || keys[i][j][s] != chest[k])
              keys[i|(1<<k)][k].pb(keys[i][j][s]);
            else
              passed = 1;
          fo(s,sz(reward[k]))
            keys[i|(1<<k)][k].pb(reward[k][s]);
        }

    // lex
    fi(n)
      if(dp[(1<<n)-1][i])
        yo[(1<<n)-1][i] = 1;
    fd(i,1<<n)
      fj(n) if(i&(1<<j))
        fk(n) if(!(i&(1<<k)))
          if(dp[i][j] && yo[i|(1<<k)][k])
            yo[i][j] = 1;
    fi(n)
      if(yo[1<<i][i])
        yo[0][0] = 1;

    if(!yo[0][0])
      printf("Case #%d: IMPOSSIBLE\n", tt+1);
    else{
      printf("Case #%d:", tt+1);
      int bitset = 0;
      while(bitset != (1<<n)-1)
        fi(n)
          if(!(bitset&(1<<i)) && yo[bitset|(1<<i)][i]){
            printf(" %d", i+1);
            bitset |= 1<<i;
            break;
          }
      printf("\n");
    }
/*
    int found = -1;
    fi(n)
      if(dp[(1<<n)-1][i])
        found = i;
    if(found == -1)
      printf("Case #%d: IMPOSSIBLE\n", tt+1);
    else{
      int bitset = (1<<n)-1, loc = found;
      vi ret;
      while(bitset){
        ret.pb(loc+1);
        int p = dp[bitset][loc]-1;
        bitset -= 1<<loc;
        loc = p;
      }
      printf("Case #%d:", tt+1);
      fd(i,sz(ret))
        printf(" %d", ret[i]);
      printf("\n");
    }
*/
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

