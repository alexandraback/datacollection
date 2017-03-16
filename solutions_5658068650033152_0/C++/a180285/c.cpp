/*****************************************
NAME    : wei.huang
PROJECT : 
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
const int N = 20               ;
const int M = 1               ;
const ll P = 10000000097ll    ;

void read() {

}

void print() {

}

int mp[N];
int r, c, k;

void init() {
  MEM(mp);
}

int bits(int x) {
  int ans = 0;
  while (x) {
    ans++;
    x ^= x & -x;
  }
  return ans;
}

void fillmp(int x) {
  init();
  for (int i = 0; i < r * c; i++) {
    int musk = (1 << i);
    if (0 == (x & musk)) {
      continue;
    }
    int x = i / c;
    int y = i % c;
    mp[x] |= (1 << y);
  }
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0,  0,-1, 1};

int check() {
  int ans = k;
  for (int x = 1; x < r - 1; x++) {
    for (int y = 1; y < c - 1; y++) {
      if (0 == (mp[x] & (1<<y))) {
        continue;
      }
      bool sub = true;
      for (int t = 0; t < 4; t++) {
        int tx = x + dx[t];
        int ty = y + dy[t];
        if (0 == (mp[tx] & (1 << ty))) {
          sub = false;
        }
      }
      ans -= sub;
    }
  }
  return ans;
}

void putout() {
  puts("");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j< c; j++) {
      putchar((mp[i] & (1 <<j)) ? 'x' : ' ');
    }
    puts("");
  }
}

void doit() {
  init();
  cin >> r >> c >> k;
  int n = r * c;
  int ans = k;
  for (int i = 0; i < (1 << n); i++) {
    if (bits(i) == k) {
      fillmp(i);
      checkmin(ans, check());
      if (5 == ans) {
        // putout();
      }
    }
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


