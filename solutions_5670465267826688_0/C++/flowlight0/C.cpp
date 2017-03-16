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

int table[][5] = {
  {0,  0,  0,  0,  0},
  {0,  1,  2,  3,  4},
  {0,  2, -1,  4, -3},
  {0,  3, -4, -1,  2},
  {0,  4,  3, -2, -1},
};

int sign(int v){
  return v > 0 ? 1 : -1;
}

void solve(){
  int L, X;
  cin >> L >> X;
  string S_;
  cin >> S_;
  
  vector<int> V_;
  REP(i, L){
    if (S_[i] == 'i') V_.push_back(2);
    if (S_[i] == 'j') V_.push_back(3);
    if (S_[i] == 'k') V_.push_back(4);
  }
  vector<int> V;
  REP(i, X) REP(j, L){
    V.push_back(V_[j]);
  }

  int mul = 1;
  REP(i, V.size()){
    mul = sign(mul) * table[abs(mul)][V[i]];
  }
  
  if (mul == -1){
    size_t pos = 0;
    int val = 1;
    
    // stage 1
    while (pos < V.size() && val != 2){
      val = sign(val) * table[abs(val)][V[pos++]];
    }
    if (pos == V.size()) goto NOTFOUND;
    
    while (pos < V.size() && val != 4){
      val = sign(val) * table[abs(val)][V[pos++]];
    }
    if (pos == V.size()) goto NOTFOUND;

    cout << "YES" << endl;
    return;
  }
  
 NOTFOUND:
  cout << "NO" << endl;
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
