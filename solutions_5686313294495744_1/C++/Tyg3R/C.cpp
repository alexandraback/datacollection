#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int,int>

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

map<string,int> m1,m2;

int mp1(string s) {
  if(!m1.count(s)) m1.insert(MP(s,m1.size()));
  return m1[s];
}

int mp2(string s) {
  if(!m2.count(s)) m2.insert(MP(s,m2.size()));
  return m2[s];
}

vi g[1007];

int main ()
{
  DRI(T);
  FOR(t,0,T) {
    m1.clear();
    m2.clear();
    DRI(N);
    FOR(i,0,N) g[i].clear();
    FOR(i,0,N) {
      string a,b;
      cin >> a >> b;
      g[mp1(a)].PB(mp2(b));
    }
    VVI M(N);
    FOR(i,0,N) M[i].resize(N,0);
    FOR(i,0,N) {
      FOR(j,0,g[i].size()) {
        int u = g[i][j];
        M[i][u] = 1;
        //DEB(i);
        //DEB(u);
      }
    }
    VI r,c;
    int p = BipartiteMatching(M,r,c);
    //DEB(p);
    //DEB(m1.size());
    //DEB(m2.size());
    int res = N - p - (m1.size()-p) - (m2.size()-p);
    printf("Case #%d: %d\n", t+1, res);
  }
  return 0;
}
