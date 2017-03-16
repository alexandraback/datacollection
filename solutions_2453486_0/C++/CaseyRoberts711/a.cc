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





const int N = 4;
char board[N][N];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int same(char a, char b){
  if(b=='T')
    swap(a,b);
  return a==b || (a=='T' && b!='.');
}

void myCode() {
  int ttt=getint();
  fo(tt,ttt){

    int winX=0, winO=0, open=0;
    fi(4){
      string s;
      cin >> s;
      fj(4)
        board[i][j] = s[j];
    }

    fi(4)
      fj(4)
        if(board[i][j]=='.')
          open = 1;

    fi(4){
      int isO=1, isX=1;
      fj(4){
        if(board[i][j]=='.' || board[i][j]=='O')
          isX = 0;
        if(board[i][j]=='.' || board[i][j]=='X')
          isO = 0;
      }
      if(isX)
        winX = 1;
      if(isO)
        winO = 1;
    }

    fj(4){
      int isO=1, isX=1;
      fi(4){
        if(board[i][j]=='.' || board[i][j]=='O')
          isX = 0;
        if(board[i][j]=='.' || board[i][j]=='X')
          isO = 0;
      }
      if(isX)
        winX = 1;
      if(isO)
        winO = 1;
    }

    int isO=1, isX=1;
    fi(4){
      if(board[i][i]=='.' || board[i][i]=='X')
        isO = 0;
      if(board[i][i]=='.' || board[i][i]=='O')
        isX = 0;
    }
    if(isX)
      winX = 1;
    if(isO)
      winO = 1;

    isO=1;
    isX=1;
    fi(4){
      if(board[i][3-i]=='.' || board[i][3-i]=='X')
        isO = 0;
      if(board[i][3-i]=='.' || board[i][3-i]=='O')
        isX = 0;
    }
    if(isX)
      winX = 1;
    if(isO)
      winO = 1;

    if(winX || winO)
      printf("Case #%d: %c won\n", tt+1, winX ? 'X' : 'O');
    else
      printf("Case #%d: %s\n", tt+1, open ? "Game has not completed" : "Draw");

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

