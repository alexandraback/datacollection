#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
 
using namespace std;
 
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define UNIQUE(x) x.erase(unique(ALL(x)),x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

////////////////////////////////////////////////////////////

vector<int> sol;

LL flip(LL n) {
  LL res = 0;
  while (n > 0) {
    res *= 10;
    res += n % 10;
    n /= 10;
  }
  return res;
}

LL best(LL n) {
  if (n < 10) {
    return n;
  }
  
  LL prev = 9;
  while (10*prev+9 < n) prev = 10*prev+9;
  LL offset = best(prev) + 1;
  LL from = prev + 1;
  
  LL sol = n - from;
  for (LL i = 0; i*i <= 10 * n; i++) {
    LL middle = flip(from + i);
    if (middle <= n) {
      sol = min(sol, i + 1 + (n-middle));
    }
  }

  return offset + sol;
}

void solve () {
  LL n;
  cin >> n;
  cout << best(n);
}

void brute(int n) {
  sol = VI(n + 1, 0);
  queue<int> q;
  q.push(1);
  sol[1] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    //    cout << x << " : " << sol[x] << endl;
    if (x+1 <= n && !sol[x+1]) {
      sol[x+1] = sol[x] + 1;
      q.push(x+1);
    }
    LL f = flip(x);
    if (!sol[f]) {
      sol[f] = sol[x] + 1;
      q.push(f);
    }
  }
  // REP(i,100) cout<<i<<"->"<<sol[i]<<endl;
  REP(i,7) {
    int x = (int) pow(10, i);
    cout<<x<<"->"<<sol[x]<<endl;
  }
}

int main () {

  int runs;
  cin >> runs;

  brute(1000000);

  for (int run=1; run<=runs; run++) {
    cout << "Case #" << run << ": ";
    solve();
    cout << endl;
  }

  return 0;
}
