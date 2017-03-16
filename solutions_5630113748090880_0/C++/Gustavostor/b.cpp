#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
   
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define fre(a,b) for(int a = adj[b]; ~a; a = ant[a])

#define iter(a) __typeof((a).begin())
#define fore(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++

const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

vi v[110];
int h[55][55], q[55][55];
int n;

bool fillColumn(int i, int j, int k) {
  for (int l = 0; l < n; l++) {
    if (h[l][j] != -1 && h[l][j] != v[k][l]) return 0;
    if (j > 0 && h[l][j-1] != -1 && v[k][l] <= h[l][j-1]) return 0;
    if (l > 0 && h[l-1][j] != -1 && v[k][l] <= h[l-1][j]) return 0;
  }
  for (int l = 0; l < n; l++) {
    q[l][j]++;
    h[l][j] = v[k][l];
  }
  return 1;
}

void eraseColumn(int i, int j, int k) {
  for (int l = 0; l < n; l++) {
    q[l][j]--;
    if (q[l][j] == 0) h[l][j] = -1;
  }
}

bool fillRow(int i, int j, int k) {
  for (int l = 0; l < n; l++) {
    if (h[i][l] != -1 && h[i][l] != v[k][l]) return 0;
    if (l > 0 && h[i][l-1] != -1 && v[k][l] <= h[i][l-1]) return 0;
    if (i > 0 && h[i-1][l] != -1 && v[k][l] <= h[i-1][l]) return 0;
  }
  for (int l = 0; l < n; l++) {
    q[i][l]++;
    h[i][l] = v[k][l];
  }
  return 1;
}

void eraseRow(int i, int j, int k) {
  for (int l = 0; l < n; l++) {
    q[i][l]--;
    if (q[i][l] == 0) h[i][l] = -1;
  }
}

bool checkAll() {
  set<pii> aff;
  rp(i,n) {
    aff.insert(mp(i,0));
    aff.insert(mp(i,1));
  }
  rp(k,2*n-1) {
    bool era = 0;
    rp(i,n) {
      if (aff.count(mp(i,0)) == 0) continue;
      rp(l,n) if (v[k][l] != h[i][l]) goto fim;
      aff.erase(mp(i,0));
      era = 1;
      goto fiim;
      fim:;
    }
    if (!era) {
      rp(i,n) {
        if (aff.count(mp(i,1)) == 0) continue;
        rp(l,n) if (v[k][l] != h[l][i]) goto fim2;
        aff.erase(mp(i,1));
        era = 1;
        goto fiim;
        fim2:;
      }
    }
    fiim:;
    if (!era) return 0;
  }
  pii a = *aff.begin();
  if (a.nd == 0) {
    rp(i,n) printf(" %d", h[a.st][i]);
  } else {
    rp(i,n) printf(" %d", h[i][a.st]);
  }
  puts("");
  return 1;
}

int use[200];
pii U[200];
bool bt(int i, int j) {
  if (j >= n) return bt(i+1, 0);
  if (i >= n) return checkAll();
  if (~h[i][j]) return bt(i, j+1);

  set<pii> tmp;
  rp(k,2*n-1) {
    if (!use[k]) {
      tmp.insert(mp(v[k][i], k));
      tmp.insert(mp(v[k][j], k));
    }
  }
  for (auto t : tmp) {
    int k = t.nd;
    if (t.st == v[k][i] && fillColumn(i, j, k)) {
      use[k] = 1;
      U[k] = mp(j,1);
      if (bt(i, j+1)) return 1;
      eraseColumn(i, j, k);
      use[k] = 0;
    }
    if (t.st == v[k][j] && fillRow(i, j, k)) {
      use[k] = 1;
      U[k] = mp(i,0);
      if (bt(i, j+1)) return 1;
      eraseRow(i, j, k);
      use[k] = 0;
    }
  }
  return 0;
}

int main() {
  int t; sc(t);
  int cas = 1;
  while (t--) {
    sc(n);
    rp(i,2*n-1) v[i].clear();
    int minf = oo, bi = -1;
    rp(i,2*n-1) {
      rp(j,n) {
        int x; sc(x);
        v[i].pb(x);
      }
    }
    cl(q,0);
    cl(h,-1);
    cl(use,0);
    printf("Case #%d:", cas++);
    bt(0,0);
  }
  return 0;
}




