/*****************************************
NAME    : wei.huang
PROJECT : Problem D. Deceitful War
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
const int N = 1024               ;
const int M = 1               ;
const ll P = 10000000097ll    ;

vector<double> a, b;
int n;

vector<double> input() {
  vector<double> ret;
  for (int i=0; i<n; i++) {
    double x;
    cin >> x;
    ret.push_back(x);
  }
  sort(ret.begin(), ret.end());
  return ret;
}

void read() {
  cin >> n;
  a = input();
  b = input();
}

void print() {

}

int War() {
  int score = 0;
  set<double> ken(b.begin(), b.end());
  for (auto i : a) {
    auto it = ken.lower_bound(i);
    if (it == ken.end()) {
      score++;
    } else {
      ken.erase(it);
    }
  }
  return score;
}

int DWar() {
  int score = 0;
  set<double> ken(b.begin(), b.end());
  for (auto i : a) {
    auto it = ken.lower_bound(i);
    if (it == ken.begin()) {
      it = ken.end();
    } else {
      score++;
    }
    ken.erase(--it);
  }
  return score;
}

void doit() {
  int y = DWar();
  int z = War();
  printf("%d %d\n", y, z);
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


