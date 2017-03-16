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

int K,C,S;

void ReadInput() {
  cin >> K >> C >> S;
}

vector<LL> Calc() {
  vector<LL> vec;
  for(int i=0;i<K;i+=C) {
    LL res = 0;
    for(int j=i;j<min(i+C,K);++j) {
      res = K*res + j;
    }
    vec.push_back(res+1);
  }
  return vec;
}

int main(int argc, char **argv) {
  int ntc; cin >> ntc;
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    cout << "Case #" << tc << ":";
    if (size(res)>S) cout << " IMPOSSIBLE";
    else {
      for(auto x : res) cout << ' ' << x;
    }
    cout << '\n';
  }
}

