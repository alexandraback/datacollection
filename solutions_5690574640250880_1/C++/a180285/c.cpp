/*****************************************
NAME    : wei.huang
PROJECT : Problem C. Minesweeper Master
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
const int N = 64               ;
const int M = 1               ;
const ll P = 10000000097ll    ;

char mp[N][N];
bool Impossible;
bool trans;
int r, c, m;

void read() {
  cin >> r >> c >> m;
}

void print() {

  // if (Impossible) {
  //   if (trans) {
  //     swap(r, c);
  //   }
  //   // printf("%d %d %d\n", r, c, m);
  // }
  // return ;

  if (Impossible) {
    puts("Impossible");
    return ;
  }

  if (trans) {
    for (int i=0; i<c; i++) {
      for (int j=0; j<r; j++) {
        putchar(mp[j][i]);
      }
      puts("");
    }
  } else {
    for (int i=0; i<r; i++) {
      for (int j=0; j<c; j++) {
        putchar(mp[i][j]);
      }
      puts("");
    }
  }
}

char & getMp(int id) {
  return mp[id/c][id%c];
}

bool doit() {
  int left = r*c - m;

  trans = (r < c);

  if (trans) {
    swap(r, c);
  }

  if (left == 1) {
    for (int i=0; i<r*c; i++) {
      getMp(i) = '*';
    }
    getMp(0) = 'c';
    return true;
  } else if (left >= 2*c) {
    for (int i=0; i<left; i++) {
      getMp(i) = '.';
    }
    for (int i=left; i<r*c; i++) {
      getMp(i) = '*';
    }
    getMp(0) = 'c';

    if (left % c == 1) {
      if (2 == c) {
        return false;
      } else if (3 == c && 2 == left / c) {
        return false;
      } else {
        int x1 = left;
        int x2 = c * (left / c) - 1;
        swap(getMp(x1), getMp(x2));

        if (2 == left / c) {
          x1 += 1;
          x2 -= c;
          swap(getMp(x1), getMp(x2));
        }

        return true;
      }
    } else {
      return true;
    }
  } else if (left >= 4) { // left < 2*c
    for (int i=0; i<left; i++) {
      mp[i%2][i/2] = '.';
    }
    for (int i=left; i<2*c; i++) {
      mp[i%2][i/2] = '*';
    }
    for (int i=2*c; i<r*c; i++) {
      getMp(i) = '*';
    }
    getMp(0) = 'c';

    if (left % 2 == 1) {
      if (left >= 9) {
        int x1 = 2 * c; // '*'
        int x2 = left - 1; // '.'
        for (int i = 0; i < 3; i++) {
          swap(getMp(x1), mp[x2%2][x2/2]);
          x1++;
          x2--;
        }
        return true;
      } else {
        return false;
      }
    }

    return true;
  } else { // left = 2, 3 but c != 1
    return false;
  }

}

int main(int argc, char const *argv[]) {
#ifdef Hw
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int T;
  cin >> T;

  for (int i=1; i<=T; i++) {
    printf("Case #%d:\n", i);
    read();
    Impossible = ! doit();
    print();
  }

  return 0;
}

/**



**/


