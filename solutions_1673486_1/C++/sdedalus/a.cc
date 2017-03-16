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

void solve(int casenum) {
  int A, B; cin >> A >> B;
  double p[A]; loop(i,A) cin >> p[i];

  double pb = 1;
  double r = B+2;

  for (int b = A; b >= 0; b--) {
    double rb = 2.0*b + B-A + pb + (1.-pb)*(B+2.);
    r = min(r, rb);
    if (b > 0) {
      pb *= p[A-b];
    }
  }

  printf("Case #%d: %.16f\n", casenum, r);
}

int main() {
  int T; cin >> T;
  loop(i,T) solve(i+1);
  return 0;
}

