/*****************************************
NAME    : wei.huang
PROJECT : Problem A. Part Elf
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

ll gcd(ll a, ll b) {
  return 0 == b ? a : gcd(b, a % b);
}

void doit() {
  ll f, g;
  scanf("%lld/%lld\n", &f, &g);

  ll Gcd = gcd(f, g);
  f /= Gcd;
  g /= Gcd;

  if (0 != (g ^ (g & -g))) {
    puts("impossible");
    return;
  }
  // printf("f:%lld g:%lld\n", f, g);
  int ans = 0;
  while (0 == (g & f)) {
    ans++;
    g >>= 1;
  }
  printf("%d\n", ans);
}

int main(int argc, char const *argv[]) {

  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    read();
    doit();
    print();
  }

  return 0;
}

/**



**/


