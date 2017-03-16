/*****************************************************************************
 *************************** Macros and Typedefs *****************************
 *****************************************************************************/

// #pragma stacksize 1M twice
// #pragma comment(linked, "/STACK:16777216")

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <time.h>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi(n) fo(i,n)
#define fj(n) fo(j,n)
#define fk(n) fo(k,n)
#define fd(i,n) for(int i=(int)(n)-1; i>=0; --i)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)a; i<(int)b; ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define srt(x) sort(all(x))
#define go(x,it) for(typeof((x).begin()) it=(x).begin(); it!=(x).end(); ++it)
#define PQ(t) priority_queue< t, vector<t>, greater<t> >
#define x first
#define y second
#define me (*this)
#define CLR(a,v) memset(a, v, sizeof(a))

typedef long long ll;
typedef long double ld;

typedef pair< int,int > ii;
typedef vector< ii > vii;
typedef vector< vii > vvii;

typedef vector< int > vi;
typedef vector< vi > vvi;

typedef vector< double > vd;
typedef vector< vd > vvd;

typedef vector< ll > vll;
typedef vector< vll > vvll;

typedef vector< string > vs;

/*****************************************************************************
 ****************************** My Methods ***********************************
 *****************************************************************************/

// my stuff
const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
int bit_count(int x){ return x==0 ? 0 : 1+bit_count(x&(x-1)); }
inline int low_bit(int x){ return x&-x; } // 0011 0100 return 0000 0100
inline int sign(double x){ return x<-EPS ? -1 : x>EPS ? 1 : 0; }
inline int sign(int x){ return (x>0)-(x<0); }

/*****************************************************************************
 **************************** Scanner Methods ********************************
 *****************************************************************************/

inline int getint(){
    int a;
    return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

inline double getdouble(){
    double a;
    return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"),-1.0);
}

inline double myrand(){
    return ((double)rand()/RAND_MAX) + ((double)rand()/RAND_MAX/RAND_MAX);
}

/*
 *  // does not get the new line
 *  getline(cin, s);
 *
 *  srt(a); a.resize(unique(all(a))-a.begin());
 *
 *  // remember, only do this for 0 and -1, INF etc may not work
 *  memset(dp, 0, sizeof(dp));
 *
 *  struct comp_1{
 *      bool operator()(const ii &a, const ii &b) const{
 *          return a.x!=b.x ? a.x<b.x : a.y<b.y;
 *      }
 *  };
 *
 *  sprintf(buf, "%s%d%s%d%s\n", "Hell", 0, " W", 0, "rld!");
 *
 *  (map<int,int>::iterator it = cache.begin(); it!=cache.end(); ++it)
 */

const int BUF_SIZE = 10;
char buf[BUF_SIZE];

inline string gettoken(){
    return scanf("%s", buf) ? buf : (fprintf(stderr, "trying to read\n"),"");
}

// does not return the new line
inline string getLine(){
    string ret;
    getline(cin, ret);
    // getline(cin, ret, ':'); // to use ':' as the delimiter
    return ret;
}

/*****************************************************************************
 ************************* Problem Specific Code *****************************
 *****************************************************************************/

// END_CUT

double pos(double p, double v, double t){
  return p + v*t;
}

int withinbefore(int i, int j, vd &p, vd &v, double t){
  return (abs(pos(p[i], v[i], t)-pos(p[j], v[j], t)) <= 5-EPS);
}

int withinafter(int i, int j, vd &p, vd &v, double t){
  return (abs(pos(p[i], v[i], t)-pos(p[j], v[j], t)) <= 5+EPS);
}

void myCode(int tt){

  // get input
  int n=getint();
  vi lanes(n,0);
  vd v(n,0), p(n,0);
  fi(n){
    char c = gettoken()[0];
    lanes[i] = (c=='L' ? 0 : 1);
    v[i] = getint();
    p[i] = getint();
  }

  // find out who could start in either lane
  fi(n){
    int ok = 1;
    fj(n) if(i!=j){
      if(abs(p[i]-p[j])<5)
        ok = 0;
    }
    if(ok)
      lanes[i] = 2;
  }
  
  // get times for sweep
  vd times;
  fj(n) fi(j) if(v[i] != v[j]){
    // how much i is in front, divided by how fast j is gaining
    double t0 = (p[i]-p[j]-5)/(v[j]-v[i]);
    double t1 = (p[i]-p[j]+5)/(v[j]-v[i]);
    times.pb(t0);
    times.pb(t1);
  }
  srt(times); times.resize(unique(all(times))-times.begin());
  reverse(all(times));
  while(!times.empty() && times.back() < EPS) times.pop_back();
  reverse(all(times));

  int fail = 0;
  double failTime = 0;
  // sweep that shit
  fo(t,sz(times)){
/*
    fprintf(stderr, "lanes at time %.3lf:\n", times[t]);
    fi(sz(lanes))
      fprintf(stderr, "%d ", lanes[i]);
    fprintf(stderr, "\n");
*/
    // free people
    fi(n){
      int ok=1;
      fj(n) if(i!=j && withinbefore(i, j, p, v, times[t]))
        ok = 0;
      if(ok)
        lanes[i] = 2;
    }
/*
    fprintf(stderr, "lanes at time %.3lf:\n", times[t]);
    fi(sz(lanes))
      fprintf(stderr, "%d ", lanes[i]);
    fprintf(stderr, "\n");
*/
    // place constraints on people
    int update = 1;
    while(update){
      update = 0;
      fj(n) fi(j) if(withinafter(i, j, p, v, times[t])){
        if(lanes[i] != 2 || lanes[j] != 2){
          if(lanes[i]==2 || lanes[j]==2)
            update = 1;
          if(lanes[i] == lanes[j] && !fail){ // one is not 2, this means same and both not 2
            fail = 1;
            failTime = times[t];
          }
          if(lanes[i] != 2)
            lanes[j] = 1-lanes[i];
          if(lanes[j] != 2)
            lanes[i] = 1-lanes[j];
        }else{ // lanes[i] == 2 && lanes[j] == 2
          lanes[i] = v[i] < v[j] ? 0 : 1;
          lanes[j] = v[i] < v[j] ? 1 : 0;
        }
      }
    }

  }
/*
  fprintf(stderr, "\n\n");
*/
  if(fail)
    printf("Case #%d: %.8lf\n", tt, failTime);
  else
    printf("Case #%d: Possible\n", tt);

}

int main() {
    srand(time(NULL));
    int ttt=getint();
    fo(tt,ttt)
      myCode(tt+1);
    return 0;
}
