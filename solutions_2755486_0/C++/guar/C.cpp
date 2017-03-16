#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define FOR(i,a,b) for(int i(a); i <= b; ++i)
#define FORD(i,a,b) for(int i(a); i >= b; --i)
#define REP0(i,n) FOR(i,0,n-1)
#define REP1(i,n) FOR(i,1,n)
#define PU push_back
#define PO pop_back
#define MP make_pair
#define A first
#define B second
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define SZ(s) (int)((s).size())
#define CL(a) memset((a),0,sizeof(a))
#define MAX(X,Y) X = max((X),(Y))
#define MIN(X,Y) X = min((X),(Y))
#define FORIT(X,Y) for(typeof((Y).begin()) X=(Y).begin(); X!=(Y).end(); ++X)
#define VI vector <int>
#define ll long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define INF 1000000000

using namespace std;

bool isCon(char c) {
  return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}
struct attack {
  int d;
  int w, e;
  int s;
  attack(int _d, int _w, int _e, int _s) : d(_d), w(_w), e(_e), s(_s) {}
  attack() {}
};
bool compare(const attack &lhs, const attack &rhs) {
  if (lhs.d == rhs.d)
    return lhs.s < rhs.s;
  return lhs.d < rhs.d;
}
void build(map<int,int> &wall, vector<attack> &att, VI &hl) {
  REP0(i,SZ(hl)) {
    FOR(p,att[hl[i]].w,att[hl[i]].e-1)
      wall[p] = MAX(wall[p],att[hl[i]].s);
  }
}
void onecase(int t) {
  int N;
  cin >> N;
  int *d = new int[N];
  int *n = new int[N];
  int *w = new int[N];
  int *e = new int[N];
  int *l = new int[N];
  int *s = new int[N];
  int *dd = new int[N];
  int *dp = new int[N];
  int *ds = new int[N];
  REP0(i,N) {
    cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
    l[i] = e[i]-w[i];
  }
  vector<attack> att;
  REP0(i,N) {
    attack a = attack(d[i],w[i],e[i],s[i]);
    att.PU(a);
    REP1(j,n[i]-1) {
      a.d += dd[i];
      a.w += dp[i];
      a.e += dp[i];
      a.s += ds[i];
      att.PU(a);
    }
  }
  sort(ALL(att),compare);
  map<int, int> wall;
  int success = 0;
  bool rebuild = false;
  VI hl;
  REP0(i,SZ(att)) {
 //   cout << att[i].d<< endl;// << " " << att[i].w << " " << att[i].e << " " << att[i].s << endl;
    bool hit = false;
    FOR(j,att[i].w,att[i].e-1) {
      if (wall[j] < att[i].s) {
        hit = true;
        break;
      }
    }
    if (hit) {
      success++;
      rebuild = true;
      hl.PU(i);
    }
    if (rebuild && i < SZ(att)-1 && att[i+1].d != att[i].d) {
        build(wall,att,hl);
//        cout << "built " << wait << " " << i << endl;
        rebuild = false;
    }
  }

  cout << "Case #" << t << ": " << success << endl;
}

int main() {
//  freopen("test.in", "r", stdin);
  int ntc;
  cin >> ntc;
  REP1(t,ntc) onecase(t);
}
