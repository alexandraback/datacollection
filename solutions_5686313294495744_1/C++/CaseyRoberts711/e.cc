/*
#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:16777216")
#endif
*/
// #include<bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <map>
#include <unordered_map>
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
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi(n) fo(i, n)
#define fj(n) fo(j, n)
#define fk(n) fo(k, n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))
//#define lgLowestBit(x) __builtin_ctz(x)
#define bitCount(x) __builtin_popcount(x)
//#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
//#define me (*this)
//#define PQ(t) priority_queue< t, vector< t >, greater< t > >
//#define CLR(a, v) memset(a, v, sizeof(a))
//#define UNIQUE(a) srt(a), a.resize(unique(all(a))-a.begin())
//#define RAND (((double)rand()/RAND_MAX) + ((double)rand()/RAND_MAX/RAND_MAX))
//#define assert(cond,msg) if(!(cond)){ fprintf(stderr, "assert failed at line %d: %s\n", __LINE__, msg); exit(1); }
/*
char systemBuffer[1<<10];
#define execute(...) {\
  sprintf(systemBuffer, __VA_ARGS__); \
  system(systemBuffer); \
}

#ifdef LOCAL
  #define debug(msg, ...) fprintf(stderr, msg, __VA_ARGS__)
#else
  #define debug(msg, ...)
#endif
*/
typedef long long ll;
typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector< vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef vector< double > vd;
typedef vector< vd > vvd;
typedef vector< ll > vll;
typedef vector< bool > vb;

const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f){ return (t>f) ? (t=f, 1) : 0; }
template<class T> int chmax(T &t, T f){ return (t<f) ? (t=f, 1) : 0; }

/* 
struct timeval startTime, finishTime;
double timeElapsed(){
  gettimeofday(&finishTime, NULL);
  int top = finishTime.tv_sec-startTime.tv_sec-(startTime.tv_usec > finishTime.tv_usec);
  int bot = finishTime.tv_usec-startTime.tv_usec;
  if(bot < 0)
    bot += 1e6;
  return top+bot/1e6;
}
*/
inline int getint() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}




vector<unordered_map<string, int>> _map;
int tokenize(string& s, int i) {
  if (!_map[i].count(s)) {
    int t = sz(_map[i]);
    _map[i][s] = t;
  }
  return _map[i][s];
}

// a is an adjList, cap is an adjMat
ll dinic(vvi &a, vvi &cap, int s, int t){

  // initialise
  ll totFlow = 0;
  int n = sz(a);
  vi q(n), prev(n); // for bfs

  while(true){
    vi prev(n, -1);
    int qf = 0, qb = 0;
    prev[q[qb++] = s] = -2;

    // find an augmenting path
    while(qb > qf && prev[t] == -1)
      for(int u=q[qf++], i=0, v; i < sz(a[u]); ++i)
        if(prev[v = a[u][i]] == -1 && cap[u][v])
          prev[q[qb++] = v] = u;

    // see if we're done
    if(prev[t] == -1) break;

    // try finding more paths
    fo(z,n) if(cap[z][t] && prev[z] != -1){
      int f = cap[z][t];
      for(int v=z, u=prev[v]; u>=0; v=u, u=prev[v])
        f = min(f, cap[u][v]);
      if(!f) continue;

      cap[z][t] -= f;
      cap[t][z] += f;
      for(int v=z, u=prev[v]; u>=0; v=u, u=prev[v]){
        cap[u][v] -= f;
        cap[v][u] += f;
      }
      totFlow += f;
    }
  }
  return totFlow;
}

void myCode() {

  int ttt = getint();
  fo(tt, ttt) {
    _map = vector<unordered_map<string, int>>(2);
    int n = getint();
    vii a;
    fi(n) {
      string s;
      cin >> s;
      int x = tokenize(s, 0);
      cin >> s;
      int y = tokenize(s, 1);
      a.pb(ii(x, y));
    }
    int half = sz(_map[0]);
    int source = half + sz(_map[1]);
    int sink = source + 1;
    vvi g(sink + 1, vi());
    vvi cap(sink + 1, vi(sink + 1, 0));
    fi(half) {
      g[source].pb(i);
      g[i].pb(source);
      cap[source][i] = 1;
    }
    fr(i,half,source) {
      g[i].pb(sink);
      g[sink].pb(i);
      cap[i][sink] = 1;
    }
    fi(sz(a)) {
      g[a[i].first].pb(half + a[i].second);
      g[half + a[i].second].pb(a[i].first);
      cap[a[i].first][half + a[i].second] = 1;
    }
    int ret = sz(a) - (source - dinic(g, cap, source, sink));
    printf("Case #%d: %d\n", tt + 1, ret);
  }

}

int main() {
/*
  // seed the random number generator with microseconds
  gettimeofday(&startTime, NULL);
  srand(startTime.tv_usec);
*/
  myCode();
  return 0;
}










