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

inline int getInt(){
    int a;
    return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

inline double getDouble(){
    double a;
    return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"),-1.0);
}

inline double myRand(){
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

/*****************************************************************************
 ************************* Problem Specific Code *****************************
 *****************************************************************************/

// END_CUT

const double PI = 2*acos(0.0);

int m, n, d, si, sj;
char board[35][35];

int doit(){
  si = 2*si-1;
  sj = 2*sj-1;
  m  = 2*(m-2);
  n  = 2*(n-2);
  d  = 2*d;

  vd thetas;
  int ret=0;

  fr(i,0,101) fr(j,0,101){
    double mi = 2*((i+1)/2)*m + ( (i&1) ? -si : si ) - 50*m;
    double mj = 2*((j+1)/2)*n + ( (j&1) ? -sj : sj ) - 50*n;
    if(sqr(mi-si)+sqr(mj-sj) < sqr(d)+1e-6 && sqr(mi-si)+sqr(mj-sj) > 1e-6)
      thetas.pb(atan2(mi-si, mj-sj));
  }
  srt(thetas);
/*
  if(m==2 && n==2 && d==4){
    fi(sz(thetas))
      if(i==0 || thetas[i] > thetas[i-1]+EPS)
        fprintf(stderr, "%lf ", thetas[i]);
    fprintf(stderr, "\n");
  }
*/
  // first shot is okay, if not like the last shot
  if(!thetas.empty() && thetas[0] > thetas.back()-2*PI+EPS) 
    ret=1;
  // every other shot must make sure it is not identical to someone
  fr(i,1,sz(thetas)) 
    if(thetas[i] > thetas[i-1]+EPS)
      ++ret;

/*
  fprintf(stderr, "si=%d, sj=%d, m=%d, n=%d, d=%d\n", si, sj, m, n, d);

  // get all possible shots in order
  fr(nu,-50,51) fr(nl,-50,51) fr(du,-1,2) fr(dl,-1,2){
    // if shot is within distance
    double ddu = 4*sqr(nu*si + (nu+du)*(m-si));
    double ddl = 4*sqr(nl*sj + (nl+dl)*(n-sj));
    // try all 4 quadrants, don't worry about counting double
    if(ddu+ddl < sqr(d)+1e-6 && ddu+ddl > EPS){
      if(du<=0 && dl>=0) thetas.pb(atan2(sqrt(ddu), sqrt(ddl)));
      if(du<=0 && dl<=0) thetas.pb(atan2(sqrt(ddu), -sqrt(ddl)));
      if(du>=0 && dl>=0) thetas.pb(atan2(-sqrt(ddu), sqrt(ddl)));
      if(du>=0 && dl<=0) thetas.pb(atan2(-sqrt(ddu), -sqrt(ddl)));
    }
  }
  srt(thetas);

  if(m==4 && n==2 && d==16){
    fi(sz(thetas)) if(i==0 || thetas[i]>thetas[i-1]+EPS)
      fprintf(stderr, "%lf ", thetas[i]); 
    fprintf(stderr, "\n");
  }

  // first shot is okay, if not like the last shot
  if(!thetas.empty() && thetas[0] > thetas.back()-2*PI+EPS) 
    ret=1;
  // every other shot must make sure it is not identical to someone
  fr(i,1,sz(thetas)) 
    if(thetas[i] > thetas[i-1]+EPS)
      ++ret;
*/
  return ret;

}

void myCode(){
  int ttt=getInt();
  fo(tt,ttt){
    m=getInt(); n=getInt(), d=getInt();
    fi(m){
      string s=getToken();
      fj(n){
        board[i][j] = s[j];
        if(board[i][j]=='X'){ si=i; sj=j; }
      }
    }
    printf("Case #%d: %d\n", tt+1, doit());
  }
}

int main() {
    srand(time(NULL));
    myCode();
    return 0;
}
