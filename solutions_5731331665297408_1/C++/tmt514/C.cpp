#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())
typedef long long LL;

char zip[105][105];
string zz[105];
vector<int> a[105];
int u[105]={}, ucs=0;
int v[105]={}, vcs=0;
string ret = "";

int oneflag = 0;
int go(int x) {
  v[x] = vcs;
  int ret=1;
  FOR(it, a[x]) {
    if(u[*it] == 1) oneflag = 1;
    if(u[*it] == 0 && v[*it] != vcs) ret += go(*it);
  }
  return ret;
}

int lev[105], n, m;
void handle(int x, int depth=0) {
  lev[depth] = x;
  u[x] = 1;
  ret += zz[x];
  while(true) {
    //printf("x = %d; ret=%s\n", x, ret.c_str());

    vector<int> possible;
    for(int j=depth;j>=0;j--) {
      int bad = 0;
      for(int i=1;i<=n;i++) if(u[i]==0) {
        ++vcs; oneflag = 0;
        go(i);
        if(!oneflag) { bad = 1; break; }
      }
      if(bad) break;
      FOR(it, a[lev[j]]) if(u[*it] == 0) possible.push_back(*it);
      u[lev[j]] = 2;
    }

    for(int j=0;j<=depth;j++) u[lev[j]] = 1;

    for(int i=0;i<SZ(possible);i++) for(int j=i+1;j<SZ(possible);j++) {
      if(zz[possible[i]] > zz[possible[j]])
        swap(possible[i], possible[j]);
    }

    if(SZ(possible)) {
      int ok = 0;
      FOR(it, a[possible[0]]) if(*it == x) ok = 1;
      if(ok) {
        handle(possible[0], depth+1);
        continue;
      }
    }
    break;
  }

  u[x] = 2;
}

int cs=0;
void solve() {
  scanf("%d%d", &n, &m);
  for(int i=1;i<=n;i++) {
    scanf("%s", zip[i]);
    zz[i] = (string) zip[i];
  }
  for(int i=1;i<=n;i++) a[i].clear();
  for(int i=0;i<m;i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }

  int S = 1; for(int i=1;i<=n;i++) if(zz[S] > zz[i]) S = i;

  for(int i=1;i<=n;i++) u[i] = 0;
  ret = "";

  handle(S);
  assert(SZ(ret) == n*5);

  printf("Case #%d: %s\n", cs, ret.c_str());
}

int main(void) {
  int T;
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  return 0;
}
