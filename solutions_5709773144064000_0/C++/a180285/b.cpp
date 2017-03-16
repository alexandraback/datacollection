/*****************************************
NAME    : wei.huang
PROJECT : Problem B. Cookie Clicker Alpha
LANG    : C++
2014    , renren-inc
*****************************************/

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))
# define pb(a)      push_back(a)

# define Foreach(it, v)     for(__typeof((v).begin()) it = (v).begin(); (v).end() != it; ++it)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;


template<class T> inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template<class T> inline void checkmax(T &a, T b) {
  if (a < b) a = b;
}

const int oo = 1 << 30          ;
const double eps = 1e-7       ;
const int N = 1               ;
const int M = 1               ;
const ll P = 10000000097ll    ;

void read() {

}

void print() {

}

void doit() {
  double C, F, X;
  cin >> C >> F >> X;

  double a1, a2, b1, b2;
  double y0;
  a2 = 2;
  b2 = 0;
  do {
    a1 = a2;
    b1 = b2;
    double x1 = (C - b1) / a1;
    double k = a1 + F;
    a2 = k;
    b2 = - x1*k;
    y0 = (a1*b2 - a2*b1) / (a1 - a2);
  } while (y0 < X);
  // cout << endl << "a:" << a1 << " b:" << b1 << endl;
  double ans = (X - b1) / a1;
  printf("%.7f\n", ans);
}

int main(int argc, char const *argv[]) {
#ifdef Hw
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    printf("Case #%d: ", i);
    read();
    doit();
    print();
  }

  return 0;
}

/**



**/


