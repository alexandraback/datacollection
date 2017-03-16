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
//#define bitCount(x) __builtin_popcount(x)
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



ll toInt(const vi& a) {
  ll ret = 0;
  fi(sz(a)) 
    ret = 10 * ret + a[i];
  return ret;
}

// top down
vi parse() {
  vi ret;
  string s;
  cin >> s;
  fi(sz(s))
    ret.pb(s[i] == '?' ? -1 : s[i] - '0');
  return ret;
}

void dfs(vi& a, vi& b, ll& retA, ll& retB, vi& ret_a, vi& ret_b) {
  bool aBigger = false, bBigger = false;
  fi(sz(a)) {
    if (a[i] == -1 || b[i] == -1) {
      int ta = a[i], tb = b[i];
      if (aBigger) {
        if (a[i] == -1) a[i] = 0;
        if (b[i] == -1) b[i] = 9;
        dfs(a, b, retA, retB, ret_a, ret_b);
      } else if (bBigger) {
        if (a[i] == -1) a[i] = 9;
        if (b[i] == -1) b[i] = 0;
        dfs(a, b, retA, retB, ret_a, ret_b);
      } else {
        if (a[i] == -1 && b[i] == -1) {
          a[i] = 0;
          b[i] = 0;
          dfs(a, b, retA, retB, ret_a, ret_b);
          a[i] = 1;
          dfs(a, b, retA, retB, ret_a, ret_b);
          a[i] = 0;
          b[i] = 1;
          dfs(a, b, retA, retB, ret_a, ret_b);
        } else if (a[i] == -1) {
          for (int j = max(0, b[i] - 1); j <= min(9, b[i] + 1); ++j) {
            a[i] = j;
            dfs(a, b, retA, retB, ret_a, ret_b);
          }
        } else { // b[i] == -1
          for (int j = max(0, a[i] - 1); j <= min(9, a[i] + 1); ++j) {
            b[i] = j;
            dfs(a, b, retA, retB, ret_a, ret_b);
          }
        }
      }
      a[i] = ta, b[i] = tb;
      return;
    } else if (!aBigger && !bBigger && a[i] != b[i]) {
      aBigger = a[i] > b[i];
      bBigger = b[i] > a[i];
    }
  }
  ll tmpA = toInt(a), tmpB = toInt(b);
  // cerr << tmpA << " " << tmpB << endl;
  if (abs(tmpA - tmpB) < abs(retA - retB) ||
      (abs(tmpA - tmpB) == abs(retA - retB) && tmpA < retA) ||
      (abs(tmpA - tmpB) == abs(retA - retB) && tmpA == retA && tmpB < retB)) {
    retA = tmpA;
    retB = tmpB;
    ret_a = a;
    ret_b = b;
  }
}

void myCode() {

  int ttt = getint();
  fo(tt, ttt) {
    ll retA = 1LL << 62, retB = 0;
    vi ret_a, ret_b;
    vi a = parse();
    vi b = parse();
    dfs(a, b, retA, retB, ret_a, ret_b);
    printf("Case #%d: ", tt + 1);
    for (int i : ret_a)
      printf("%d", i);
    printf(" ");
    for (int i : ret_b)
      printf("%d", i);
    printf("\n");
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










