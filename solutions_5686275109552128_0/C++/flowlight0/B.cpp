#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(auto i = (c).begin(); i != (c).end(); ++i)
#define BIT(n, m) (((n) >> (m)) & 1)

typedef long long ll;

const ll inf = 1e15;
const ll mod = 1000 * 1000 * 1000 + 7;
const double eps = 1e-9;

void solve(){
  int D;
  cin >> D;
  vector<int> P(D);
  REP(i, D){
    cin >> P[i];
  }
  sort(ALL(P));

  int res = P[D - 1];
  
  REP2(p, 1, P[D - 1] + 1){
    vector<int> L;
    REP(i, D) if (P[i] > p){
      L.push_back(P[i] - p);
    }
    sort(ALL(L), greater<int>());
    
    int move_count = 0;
    REP(i, L.size()){
      move_count += (L[i] + p - 1) / p;
    }
    res = min(res, p + move_count);
  }
  cout << res << endl;
}
 
int main(){
  int T;
  cin >> T;
  REP(t, T){
    printf("Case #%d: ", t + 1);
    solve();
  }
  return 0;
}
