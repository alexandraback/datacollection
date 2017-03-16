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
typedef set<int> Si;

typedef queue<int> Q;
typedef priority_queue<int> PQ;

template <class Ta, class Tb> inline Tb cast(Ta a) {stringstream ss; ss << a; Tb b; ss >> b; return b; };
typedef pair<int, P> PP;

const double EPS = 1e-9;
const int INF = 1000000000;
const int diri[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dirj[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main() {
  int t; cin >> t;
  for (int cas=1;cas<=t;++cas) {
    int r,n,m,k;
    cin >> r >> n >> m >> k;
    //r=100, n=3, m=5, k=7
    map<PP, Si> pos;
    FORE(a,2,m) FORE(b,2,m) FORE(c,2,m) if (a<=b and b<=c) { //no repeteixo sets
      //nums que tria(a,b,c)
      PP p = PP(a,P(b,c));
      Vi w(3); //v(1<<3,1);
      Si v;
      w[0]=a;w[1]=b; w[2]=c;
      REP(mask,(1<<3)) {
        int prod=1;
        REP(j,3) if ((mask>>j)&1) prod*=w[j];
        v.insert(prod);
      }
      //v[mask] producte del subset
      pos[p]=v;
    }
    cout << "Case #" << cas << ":"<< endl;
    REP(que,r) {
      Vi w(k);//k=7
      REP(j,k) cin >> w[j];
      vector<PP> sol;
      for (map<PP,Si>::iterator it=pos.begin();it!=pos.end();++it) {
        PP p = it->first;
        Si v = it->second;
        bool ok=1;
        REP(j,k) if (not v.count(w[j])) ok=0;
        if (ok) sol.push_back(p);
      }
      if (!sol.size()) cout <<"222" << endl; //no passa mai
      else cout << sol[0].x << sol[0].y.x << sol[0].y.y << endl;
    }
  }
}
