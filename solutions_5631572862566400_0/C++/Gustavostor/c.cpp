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

#define maxn 2010

int mark[maxn], entry[maxn], f[maxn], sz[maxn];
bool isCyc[maxn];
int ans;
stack<int> stk;
void dfs(int u) {
  mark[u] = 1;
  stk.push(u);
  if (mark[f[u]] == 1) {
    int cyc = 1;
    while (!stk.empty() && stk.top() != f[u]) {
      int v = stk.top(); stk.pop();
      cyc++;
      isCyc[v] = 1;
    }
    isCyc[f[u]] = 1;
    stk.pop();
    ans = max(ans, cyc);
  } else if (mark[f[u]] == 2) {
    if (isCyc[f[u]]) entry[u] = f[u], sz[u] = 1;
    else entry[u] = entry[f[u]], sz[u] = sz[f[u]]+1;
  } else {
    dfs(f[u]);
    if (!isCyc[u]) {
      if (isCyc[f[u]]) entry[u] = f[u], sz[u] = 1;
      else entry[u] = entry[f[u]], sz[u] = sz[f[u]]+1;
    }
  }
  mark[u] = 2;
}

int n;
int R[maxn];
int calc1() {
  int tmp = 0;
  cl(R,0);
  rp(i,n) {
    if (!isCyc[i]) {
      int a = entry[i];
      if (a == f[f[a]]) R[a] = max(R[a], sz[i]);
    }
  }
  cl(mark,0);
  rp(i,n) {
    if (isCyc[i] && f[f[i]] == i && !mark[i]) {
      tmp += 2 + R[i] + R[f[i]];
      mark[i] = 1;
      mark[f[i]] = 1;
    }
  }
  return tmp;
}

int main() {
  int cas = 1;
  int t; sc(t);
  while (t--) {
    sc(n);
    rp(i,n) sc(f[i]), f[i]--;

    ans = 0;
    cl(entry,-1);
    cl(sz,0);
    cl(isCyc,0);
    cl(mark,0);
    rp(i,n) if (!mark[i]) {
      dfs(i);
    }

    rp(i,n) fr(j,i+1,n) if (!isCyc[i] && !isCyc[j]) {
      if (entry[i] != entry[j]) {
        int a = entry[i];
        int b = entry[j];
        if (f[a] == b && f[b] == a) {
          ans = max(ans, sz[i] + sz[j] + 2);
        }
      }
    }

    ans = max(ans, calc1());

    printf("Case #%d: %d\n", cas++, ans);
  }
  return 0;
}






