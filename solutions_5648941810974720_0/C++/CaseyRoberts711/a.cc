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



int foo(const vi& a, char c) { return a[c - 'A']; }
void bar(char c, int n) { fi(n) printf("%c", c); }

void myCode() {

  int ttt = getint();
  fo(tt, ttt) {
    string s;
    std::cin >> s;
    vector<int> a(26, 0);
    fi(sz(s))
      a[s[i] - 'A'] += 1;
    printf("Case #%d: ", tt + 1);
    bar('0', foo(a, 'Z'));
    bar('1', foo(a, 'O') - foo(a, 'W') - foo(a, 'U') - foo(a, 'Z'));
    bar('2', foo(a, 'W'));
    bar('3', foo(a, 'T') - foo(a, 'W') - foo(a, 'G'));
    bar('4', foo(a, 'U'));
    bar('5', foo(a, 'V') - foo(a, 'S') + foo(a, 'X'));
    bar('6', foo(a, 'X'));
    bar('7', foo(a, 'S') - foo(a, 'X'));
    bar('8', foo(a, 'G'));
    bar('9', (foo(a, 'N') - foo(a, 'O') + foo(a, 'W') + foo(a, 'U') - foo(a, 'S') + foo(a, 'X') + foo(a, 'Z')) / 2);
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










