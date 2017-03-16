#include<iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef vector<int> VI;
typedef pair<LL,LL> PLL;
typedef vector<pair<int,int> > VPII;
typedef vector<LL> VLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef long double LD;
typedef vector<char> VC;

#define PI 3.14159265358979323
#define EE 2.71828182845
#define EPS 10e-10
#define INF 10000000

inline LL MAX(LL a, LL b){ return a < b ? b : a;}
inline LL MIN(LL a, LL b){ return a < b ? a : b;}

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define FORD(i,n)     for(int i=(n)-1;i>=0;i--)

#define MP make_pair
#define PB push_back

PLL simplify(PLL p){
  LL d = 2;
  while(d*d < p.second){
    while(p.first % d == 0 && p.second % d == 0) p.first /= d, p.second /= d;
    d++;
  }
  return p;
}

void solve(int tc){
  char cc;
  LL P, Q;
  cin >> P >> cc >> Q;
  while((P % 2 == 0)&& (Q % 2 == 0)) P/=2, Q/=2;
  LL c = 1;
  cout << "Case #" << tc << ": ";
  PLL pp = simplify(MP(P,Q));
  P = pp.first;
  Q = pp.second;
  while(c <= Q){
    if (c == Q) break;
    c *= 2;
  }
  if (c != Q){
    cout << "impossible" << endl;
    return;
  }
  
  int g = 0;
  c = Q;
  while(c > P){
    g++;
    c /= 2;
  }
  cout << g << endl;
}

int main(){
  int TT;
  cin >> TT;
  FOR(tt, TT) solve(tt+1);
  return 0;
}
