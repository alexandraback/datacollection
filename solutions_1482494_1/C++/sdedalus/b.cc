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
  int N; cin >> N;
  vector<int> a(N), b(N); loop(i,N) cin >> a[i] >> b[i];

  set<int> c1, c2;
  int S = 0;

  int Count = 0;
  while (true) {
    if (c2.size() == N)
      break;

    int bmin = (1<<20), bind = -1;
    loop(i,N) if (c2.find(i) == c2.end() && bmin > b[i] && b[i] <= S)
      bmin = b[i], bind = i;
    if (bind >= 0) {
      c2.insert(bind);
      S += 1 + (c1.find(bind) == c1.end());
      // printf("Completed level %d(2) (got %d stars)\n", bind+1,  1 + (c1.find(bind) == c1.end()));
      c1.insert(bind);
      Count++;
      continue;
    }

    int amin = (1<<20), abmax = -1, aind = -1;
    loop(i,N) if (c1.find(i) == c1.end() && abmax < b[i] && a[i] <= S)
                  amin = a[i], aind = i, abmax = b[i];
    if (aind >= 0) {
      c1.insert(aind);
      S++;
      // printf("Completed level %d(1) (got 1 star)\n", aind+1);
      Count++;
      continue;
    } else {
      Count = -1;
      break;
    }
  }

  if (Count >= 0)
    printf("Case #%d: %d\n", casenum, Count);
  else
    printf("Case #%d: Too Bad\n", casenum);
}

int main() {
  int T; cin >> T;
  loop(i,T) solve(i+1);
  return 0;
}

