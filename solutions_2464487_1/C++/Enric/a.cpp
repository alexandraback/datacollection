#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define x first
#define y second
#define PB push_back
#define REP(i,n) for (int i = 0; i < int(n); ++i)
#define FORE(i,a,b) for (int i = int(a); i <= int(b); ++i)
#define MP      make_pair
#define PB      push_back
#define SZ(v)   (v).size()
#define ALL(v)  (v).begin(),(v).end()
#define FOREACH(it,v) \
                       for (typeof( v.begin() ) it = v.begin(); it!=v.end(); ++it)
#define debug(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;
typedef vector<char> Vc;
typedef vector<Vc> Mc;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<ll> Vll;
typedef vector<Vll> Mll;
typedef vector<P> Vp;
typedef vector<Vp> Mp;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

typedef queue<int> Q;
typedef priority_queue<int> PQ;

template <class Ta, class Tb> inline Tb cast(Ta a) {stringstream ss; ss << a; Tb b; ss >> b; return b; };

const double EPS = 1e-9;
const int INF = 1000000000;
const int diri[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dirj[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

ld ev(ld n) { //0+2+4+...+2n
  return n*(n+1);
}

ld f(ld r, ld n) {
  return n+2.*(r*n + ev(n-1));
}

int main() {
  
  /*vector<ld> v;
  ld ar=0,zr=1;
  ld armax = 2*1e18;
  while (ar<=armax) {
    ar+=f(zr,zr+1);
    zr+=2;
  }*/
  
  int t; cin >> t;
  for (int cas=1;cas<=t;++cas) {
    ld r,p;
    cin >> r >> p;
    ll a=0,b=10000000000LL,m;
    while(b-a>1) {
      //cerr << a << ", " << b << endl;
      m=(a+b)/2;
      if (f(r,m) > p ) b=m;
      else a=m;
    }

    cout << "Case #" << cas << ": " << a << endl;
  }
}
