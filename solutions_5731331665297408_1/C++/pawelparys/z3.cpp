#include <string>
#include <cstring>
#include <vector>
#include <cassert>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define FORD(a,b,c) for(int a=(b); a>=(c); --a)
#define INIT(i,v) __typeof(v) i = (v)
#define FOREACH(i,v) for(INIT(i, (v).begin()); i!=(v).end(); ++i)
#define MP make_pair
#define PB push_back
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long LL;
 
template<class T>
inline int size(const T&t){return t.size();}

#define INF 1000000000
 
//////////////////////////////////////////

int N;
vi sas[50];
string kody[50];
int kol[50];
int sc_len, sciezka[50], nr_na_sciezce[50], bylem[50], dfs_tab[50];

void init() {
  int s = 0;
  REP(a, N) {
    if (kol[a]==0)
      s = a;
    nr_na_sciezce[a] = -1;
    bylem[a] = 0;
  }
  sc_len = 1;
  sciezka[0] = s;
  nr_na_sciezce[s] = 0;
  bylem[s] = 1;
  printf("%s", kody[s].c_str());
}

int dfs(int w) {
  if (nr_na_sciezce[w]>=0)
    return nr_na_sciezce[w];
  if (bylem[w] || dfs_tab[w])
    return INF;
  dfs_tab[w] = 1;
  int res = INF;
  FOREACH(it, sas[w])
    res = min(res, dfs(*it));
  return res;
}

void dalej() {
  REP(a, N)
    dfs_tab[a] = 0;
  int najnizszy = 0;
  REP(a, N)
    if (!bylem[a] && !dfs_tab[a])
      najnizszy = max(najnizszy, dfs(a));
  assert(najnizszy<INF);
  int best = INF;
  int best_v = 0, best_h = 0;
  FOR(a, najnizszy, sc_len-1) {
    int w = sciezka[a];
    FOREACH(it, sas[w])
      if (!bylem[*it] && kol[*it]<=best) {
        best = kol[*it];
        best_v = *it;
        best_h = a; // zapisze sie najwieksze a
      }
  }
  printf("%s", kody[best_v].c_str());
  FOR(a, best_h+1, sc_len-1)
    nr_na_sciezce[sciezka[a]] = -1;
  sc_len = best_h+2;
  sciezka[best_h+1] = best_v;
  nr_na_sciezce[best_v] = best_h+1;
  bylem[best_v] = 1;
}

void licz() {
  init();
  REP(ttt, N-1)
    dalej();
}

void sortuj() {
  pair<string, int> tab[50];
  REP(a, N)
    tab[a] = MP(kody[a], a);
  sort(tab, tab+N);
  REP(a, N)
    kol[tab[a].second] = a;
}

int main(int argc, char **) {
  int TT;
  scanf("%d", &TT);
  REP(tt, TT) {
    int M;
    scanf("%d%d", &N, &M);
    REP(a, N) {
      char buf[6];
      scanf("%s", buf);
      kody[a] = buf;
      sas[a].clear();
    }
    REP(a, M) {
      int x, y;
      scanf("%d%d", &x, &y);
      --x;
      --y;
      sas[x].PB(y);
      sas[y].PB(x);
    }
    printf("Case #%d: ", tt+1);
    sortuj();
    licz();
    printf("\n");
  }
}


