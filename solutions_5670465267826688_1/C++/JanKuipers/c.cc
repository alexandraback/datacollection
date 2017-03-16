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

const int inf = 999999999;

////////////////////////////////////////////////////////////

const int mul_table[4][4] = {
  { 1, 2, 3, 4},
  { 2,-1, 4,-3},
  { 3,-4,-1, 2},
  { 4, 3,-2,-1}};

int mul(int a, int b) {
  return a/abs(a) * b/abs(b) * mul_table[abs(a)-1][abs(b)-1];
}

void solve () {
  long long l,n;
  string x;
  cin>>l>>n>>x;
  int total_x = 1;
  for (int i=0; i<l; i++) total_x = mul(total_x, x[i]-'i'+2);
  int total_all = 1;
  for (int i=0; i<n%4; i++) total_all = mul(total_all, total_x);
  if (total_all != -1) {
    cout << "NO";
    return;
  }
  string y;
  for (int i=0; i<min(n, 10LL); i++) y+=x;
  int total = 1;
  bool i_found = false;
  for (int i=0; i<y.size(); i++) {
    total = mul(total, y[i]-'i'+2);
    if (!i_found && total == 2) {
      i_found = true;
      total = 1;
    }
    if (i_found && total == 3) {
      cout << "YES";
      return;
    }
  }  
  cout << "NO";
}

int main () {

  int runs;
  cin >> runs;

  for (int run=1; run<=runs; run++) {
    cout << "Case #" << run << ": ";
    solve();
    cout << endl;
  }

  return 0;
}
