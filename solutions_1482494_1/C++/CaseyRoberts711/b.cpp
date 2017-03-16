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

/*
const int BUF_SIZE = 1001*1000;
char buf[BUF_SIZE];

inline string getToken(){
    return scanf("%s", buf) ? buf : (fprintf(stderr, "trying to read\n"),"");
}

// does not return the new line
inline string getLine(){
    string ret;
    getline(cin, ret);
    // getline(cin, ret, ':'); // to use ':' as the delimiter
    return ret;
}
*/

/*****************************************************************************
 ************************* Problem Specific Code *****************************
 *****************************************************************************/

// END_CUT

void myCode(){
  int ttt=getint();
  fo(tt,ttt){
    int n=getint();
    vii a;
    fi(n){
      int x=getint(), y=getint();
      a.pb(ii(y,x));
    }
    // sort by smallest y, heuristic
    srt(a);
    fi(n) a[i] = ii(a[i].y, a[i].x);
    
    int stars=0, turns=0;
    vi done(n, 0);

    int finished=0, bestMove=-1, moveType=3, highest=-1;
    while(!finished){

      finished = 1;
      bestMove = -1;
      highest = -1;

      fi(n){
        // note not done
        if(done[i]!=2)
          finished = 0;
        // yeehaw
        if(done[i]!=2 && a[i].y<=stars){
          bestMove = i;
          moveType = 0;
          break;
        }
        // pick a shit move
        if(done[i] == 0 && a[i].x<=stars && a[i].y > highest){
          moveType = 1;
          bestMove = i;
          highest = a[i].y;
        }
      }

      // fprintf(stderr, "bestMove = %d, stars = %d, turns = %d\n", bestMove, stars, turns);

      // make a move
      if(bestMove != -1){
        ++turns;
        if(moveType == 0){
          stars += 2-done[bestMove];
          done[bestMove] = 2;
        }else{
          ++stars;
          done[bestMove] = 1;
        }
      }
      // we fucked
      else{
        break;
      }

    }

    if(!finished)
      printf("Case #%d: Too Bad\n", tt+1);
    else
      printf("Case #%d: %d\n", tt+1, turns);

  }
}

int main() {
    srand(time(NULL));
    myCode();
    return 0;
}
