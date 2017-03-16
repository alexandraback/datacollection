#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL; typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }

unsigned Digits(int x) {
  unsigned digs = 0;
  while(x) {
    digs |= 1u << (x%10);
    x /= 10;
  }
  return digs;
}

int F(int n) {
  if(n==0) return -1;
  unsigned seen = 0;
  for(int x=n;;x+=n) {
    assert(x < INF);
    seen |= Digits(x);
    if(seen == (1u<<10)-1u) return x;
  }
}

int theN;

void ReadInput() {
  theN = rint();
}

int Calc() {
  return F(theN);
}

void CheckMax() {
  int m = 0;
  FOR(n,1,1000000) m = max(m, F(n)/n);
  DEBUG(m);
}

int main(int argc, char **argv) {
  int ntc = rint();
  FOR(tc,1,ntc) {
    ReadInput();
    auto res = Calc();
    cout << "Case #" << tc << ": ";
    if(res==-1) cout << "INSOMNIA\n";
    else cout  << res << "\n";
  }
}
