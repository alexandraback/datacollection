#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long ll;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
bool ISINT(double x){return fabs(x-(int)round(x))<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define EREP(i,a,b) for(int i=a;i<=b;i++)
#define erep(i,n) EREP(i,0,n)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

int r, n, m, k;
int t[100];
int card[100];

bool solve(){
  int okBit = 0;

  for(int i = 0; i < (1 << n); i++){
    int mul = 1;

    for(int j = 0; j < n; j++){
      if(!(i & (1 << j))) continue;
      mul *= card[j];
    }

    for(int j = 0; j < k; j++){
      if(t[j] != mul) continue;
      okBit |= (1 << j);
    }
  }

  return okBit == (1 << k) - 1;
}

bool decideCard(int idx){
  if(idx == n){
    return solve();
  }

  for(int i = 2; i <= m; i++){
    card[idx] = i;
    if(decideCard(idx + 1)) return true;
  }

  return false;
}

int main(void){
  int TTT;
  cin >> TTT;
  cout << "Case #1:" << endl;
  cin >> r >> n >> m >> k;

  for(int SET = 1; SET <= r; SET++){
    for(int i = 0; i < k; i++){
      cin >> t[i];
    }

    decideCard(0);

    for(int i = 0; i < n; i++){
      cout << card[i];
    }
    cout << endl;
  }
}
