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
  int S; cin >> S;
  int p; cin >> p;
  int A[N]; loop(i,N) cin >> A[i];

  int Q[N+1][S+1];
  loop(i,S+1) Q[0][i] = 0;

  for (int i = 1; i <= N; ++i) {
    int x = A[i-1]/3;
    for (int s = 0; s <= S; ++s) {
      Q[i][s] = max(Q[i-1][s] + (x + (A[i-1]%3!=0) >= p),
                    s && A[i-1] > 1 ? Q[i-1][s-1] + (x + 1 + (A[i-1]%3==2) >= p) : -1);
      //printf("Q[%d][%d] = %d\n", i, s, Q[i][s]);
    }
  }

  int q = -1;
  loop(i,S+1) q = max(q, Q[N][i]);

  printf("Case #%d: %d\n", casenum, Q[N][S]);

}

int main() {
  int T; cin >> T;
  loop(i,T) solve(i+1);
  return 0;
}

