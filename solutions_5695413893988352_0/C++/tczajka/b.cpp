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

string A, B;

void ReadInput() {
  cin >> A >> B;
  assert(size(A)==size(B));
}

struct Result {
  bool found;
  string aa, bb;
  LL diff;
};

map<pair<int,int>, Result> cache;

bool Better(const Result &a, const Result &b) {
  if (a.found != b.found) return a.found;
  if(a.diff != b.diff) return a.diff < b.diff;
  if(a.aa != b.aa) return a.aa < b.aa;
  return a.bb < b.bb;
}

LL Power(LL a, int b) {
  LL res = 1;
  REP(i,b) res *= a;
  return res;
}

Result Calc(const int pos, const int cmp) {
  const pair<int,int> h = {pos, cmp};
  if(cache.count(h)) return cache[h];
  Result res;
  if (pos == size(A)) {
    res.found = true;
    res.aa = "";
    res.bb = "";
    res.diff = 0;
  } else {
    res.found = false;
    res.aa = "";
    res.bb = "";
    res.diff = 0;

    for(char dA = '0'; dA <= '9'; ++dA) {
      if(A[pos] != '?' && A[pos] != dA) continue;
      for(char dB = '0'; dB <= '9'; ++dB) {
        if(B[pos] != '?' && B[pos] != dB) continue;

        int cmp2;
        if(cmp!=0) cmp2 = cmp;
        else if(dA < dB) cmp2 = -1;
        else if(dA > dB) cmp2 = 1;
        else cmp2 = 0;

        const Result res2 = Calc(pos+1, cmp2);
        if(res2.found) {
          Result res3;
          res3.found = true;
          res3.aa = string(1, dA) + res2.aa;
          res3.bb = string(1, dB) + res2.bb;
          if(cmp2 <= 0) {
            res3.diff = Power(10, size(res2.aa)) * (dB - dA) + res2.diff;
          } else {
            res3.diff = Power(10, size(res2.aa)) * (dA - dB) + res2.diff;
          }
          if (Better(res3, res)) res = res3;
        }
      }
    }
  }
  cache[h] = res;
  return res;
}

Result Calc() {
  cache.clear();
  auto res = Calc(0, 0);
  assert(res.found);
  return res;
}

int main(int argc, char **argv) {
  int ntc; cin >> ntc;
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    cout << "Case #" << tc << ": " << res.aa << ' ' << res.bb << "\n";
  }
}

