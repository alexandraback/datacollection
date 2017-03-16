#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#define rep(i,m,n) for(int i = m; i < (int)n; i++)
#define REP(i,n) rep(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()

using namespace std;
static const double EPS = 1e-9;
int INF = 1<<28;
typedef long long ll;
typedef pair<int,int> Pii;

long long r, t;

void input() {
  cin >> r >> t;
  return;
}

int solve() {
  input();
  int ans = 1;
  ll a0 =  2* r - 3;
  while ( 2 * ans * (ans + 1) + ans * a0 <= t) {
    ans++;
  }
  return ans;
}

int main() {
  int T; cin >> T;
  for (int i= 0; i < T; i++) {
    int ans = solve();
    cout << "Case #"<< i+1 << ": ";
    cout << ans-1 << endl;
  }
  
  
  return 0;
}
