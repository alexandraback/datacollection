#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = 110;
const int INF = (int) 1e9;

multiset <int> r[MAXN];
multiset <int> c[MAXN];
int n, m;
int a[MAXN][MAXN];
int cntr, cntc;

void prepare () {
  for (int i = 0; i < n; i++) {
    r[i].clear();

    for (int j = 0; j < m; j++)
      r[i].insert(a[i][j]);
  }

  for (int j = 0; j < m; j++) {
    c[j].clear();

    for (int i = 0; i < n; i++)
      c[j].insert(a[i][j]);
  }

  cntr = n;
  cntc = m;
}

int GetMinInRow (int i) {
  return r[i].empty() ? INF : *r[i].begin();
}

int GetMaxInRow (int i) {
  return r[i].empty() ? -INF : *r[i].rbegin();
}

int GetMaxInCol (int j) {
  return c[j].empty() ? -INF : *c[j].rbegin();
}

void EraseRow (int i, int val) {
  r[i].erase(r[i].find(val));  
}

void EraseCol (int j, int val) {
  c[j].erase(c[j].find(val));
}

void Erase (int i, int j) {
  if  (a[i][j] == -1) return;

  EraseCol(j, a[i][j]);
  EraseRow(i, a[i][j]);

  a[i][j] = -1; 
}

bool go () {
  if  (cntr == 1 || cntc == 1) return true;

  int mi = 200;
  for (int i = 0; i < n; i++)
    mi = min(mi, GetMinInRow(i));

  
  for (int i = 0; i < n; i++)
    if  (GetMaxInRow(i) == mi) {
      for (int j = 0; j < m; j++)
         Erase(i, j);
      cntr--;
      return go(); 
    }

 for (int j = 0; j < m; j++)
   if  (GetMaxInCol(j) == mi) {
     for (int i = 0; i < n; i++)
       Erase(i, j);
     cntc--;
     return go();
   }

 return false;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t; scanf("%d", &t);
  for (int test = 1; test <= t; test++) {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) 
      for (int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);

    prepare();
    
    printf("Case #%d: ", test);
    puts(go() ? "YES" : "NO");
  }
   
  return 0;
}
