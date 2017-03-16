#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }

LL Power(LL a, int b) {
  LL res = 1;
  REP(i,b) res *= a;
  return res;
}

int main(int argc, char **argv) {
  int ntc; cin >> ntc;
  FOR(tc,1,ntc) {
    int N, J;
    cin >> N >> J;
    cout << "Case #" << tc << ":\n";
    assert(N>=2 && N <= 32 && N%2==0 && J <= (1<<(N/2-2)));
    REP(idx, J) {
      string s = "1";
      REP(i,N/2-2) s += char('0' + ((idx>>(N/2-3-i))&1));
      s += '1';
      cout << s << s;
      FOR(i,2,10) cout << ' ' << (Power(i,N/2)+1);
      cout << '\n';
    }
  }
}

