#include <set>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define REP(i,t) for(int i=0; i<(t); i++)
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORL(i,s,t) for(L i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
#define EPS 1e-6
#define EQ(a, b) (fabs((a) - (b)) <= EPS)
#define POS(a) ((a) >= EPS)
#define NEG(a) ((a) <= -EPS)
#define BG(a, b) ((a) - (b) >= EPS)
#define LS(a, b) ((b) - (a) >= EPS)
#define CLR(a, x) memset( a, x, sizeof( a ) )
#define PI (atan(1.0) * 4)
#define SQ(x) ((x) * (x))
#define DIST(x1, y1, x2, y2) (sqrt(SQ((x1) - (x2)) + SQ((y1) - (y2))))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define LOG2(x) (log(x) / log(2))
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double, double> Pd;
typedef pair<int, int> Pi;
typedef pair<LL, LL> Pl;

struct tri {
  int a, b, c;
  tri(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
};

int r, n, m, k;
int pro[20];

bool valid(int a, int b, int c, map<int, int>& p) {
  for (map<int, int>::iterator itr = p.begin(); itr != p.end(); itr++) {
    int x = itr->first;
    if (x != a && x != b && x != c && x != a * b && x != a * c && x != b * c && x != a * b * c)
      return false;
  }
  return true;
}

int sim(tri& t, map<int, int>& p) {
  int hit = 0;
  //cout << "simulating " << t.a << " " << t.b << " " << t.c << endl;
  REP(i, 10000) {
    map<int, int> local;
    REP(j, k) {
      int x = 1;
      if (rand() & 1)
        x *= t.a;
      if (rand() & 1)
        x *= t.b;
      if (rand() & 1)
        x *= t.c;
      local[x]++;
    }
    for (map<int, int>::iterator itr = local.begin(); itr != local.end(); itr++) {
      //cout << itr->first << " " << itr->second << " , ";
      hit += min(itr->second, p[itr->first]);
    }
    //cout << endl;
  }
  //cout << "hit: " << hit << endl;
  return hit;
}

void solve() {
  map<int, int> p;
  vector<tri> v;
  REP(i, k)
    if (pro[i] != 1)
      p[pro[i]]++;
  if (p.size() == 0) {
    REP(i, n)
      cout << 2;
    return;
  }
  FOR(a, 2, m + 1)
    FOR(b, a, m + 1)
      FOR(c, b, m + 1)
        if (valid(a, b, c, p)) {
          v.push_back(tri(a, b, c));
        }
  int best = 0;
  int besti = 0;
  REP(i, v.size()) {
    int hit = sim(v[i], p);
    if (hit > best) {
      best = hit;
      besti = i;
    }
  }
  cout << v[besti].a << v[besti].b << v[besti].c;
}

int main()
{
  int t;
  cin >> t;
  FOR(tt, 1, t + 1) {
    cout << "Case #" << tt << ":"; 
    cout << endl;
    cin >> r >> n >> m >> k;
    REP(i, r) {
      REP(j, k)
        cin >> pro[j];
      solve();
      cout << endl;
    }
  }
  return 0;
}

