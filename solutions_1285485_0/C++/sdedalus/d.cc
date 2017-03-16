#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>
#include <cstring>
using namespace std;

#define loop(i,n) for (int i = 0; i < (int)(n); ++i)
#define Bounded(x,a,b) ((a) <= (x) && (x) <= (b))
#define db(x) #x << " = " << x
#define pdb(x) printf("#x = %d\n",x);
#define All(x) x.begin(),x.end()
#define sz(x) x.size()
typedef vector<int> Vi;
typedef pair<int,int> Pii;
typedef vector<Vi> Adj;
typedef vector<bool> Vb;

typedef long long int Int;

inline int sign(int x) { return x==0 ? 0 : (x>0 ? 1 : -1); }

inline Int gcd(Int x, Int y) {
  if (x == 0 && y == 0) return 1;
  if (x == 0) return abs(y);
  return gcd(abs(y)%abs(x), abs(x));
}

void solve(int casenum) {
  int _H, _W, D; cin >> _H >> _W >> D;
  vector<string> A(_H);
  loop(i,_H) cin >> A[i];
  int Xi, Xj;
  loop(i,_H) loop(j,_W) if (A[i][j] == 'X')
    Xi = i, Xj = j;

  int H = _H-2, W = _W-2;

  Int a = -(2*Xj-1), b = 2*Xi-1, c = 2*W+a, d = b-2*H;
  //Int NI = 40 + (D+W-1)/W, NJ = 40 + (D+H-1)/H;
  Int NI = 60, NJ = 60;
  // printf("[%d,%d,%d] %lld, %lld, %lld, %lld\n", Xi, Xj, D, a, b, c, d);

  int Count = 0;

  set<Pii> forbid;
  forbid.insert(Pii(0,0));

  for (int i = -NI; i <= NI; ++i) for (int j = -NJ; j <= NJ; ++j) {
      Int xi = 4*W * sign(i) * (abs(i)/2) + 2 * (i>0?c:a) * (abs(i)%2==1);
      Int yi = 4*H * sign(j) * (abs(j)/2) + 2*(j>0?b:d) * (abs(j)%2==1);
      Int cx = b + i * 2*W, cy  = c + j*2*H;
      Int gg = gcd(xi,yi), gc = gcd(cx,cy);

      if (xi*xi + yi*yi <= 4*D*D
          && forbid.find(Pii(xi/gg, yi/gg)) == forbid.end()) {
        
        // printf("Room (%d,%d)\n", i, j);
        // printf("Can see self at (%.1f,%.1f)\n", xi/2., yi/2.);
        Count++;
        forbid.insert(Pii(xi/gg, yi/gg));
      }
      
      if (cx*cx + cy*cy <= D*D
          && forbid.find(Pii(cx/gc, cy/gc)) == forbid.end()) {
        // printf("Can see self in corner (%.1f,%.1f)\n", cx/2., cy/2.);
        Count++;
        forbid.insert(Pii(cx/gc, cy/gc));
      }
    }

  printf("Case #%d: %d\n", casenum, Count);
}

int main() {
  int T; cin >> T;
  loop(i,T) solve(i+1);
  return 0;
}

