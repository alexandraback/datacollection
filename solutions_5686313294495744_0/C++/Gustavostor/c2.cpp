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

#define maxm 100100
#define maxn 100100

int to[maxm], ant[maxm], adj[maxn], z;
#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++

const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

map<string, int> ids1, ids2;
int sz1, sz2;
int deg[100100];
bool can[100100];
char str[100100];
int cas = 1;
pii v[30];
int n;
int pd[1<<17];

int go(int msk) {
  if (msk == (1<<n)-1) return 0;
  int &ans = pd[msk];
  if (~ans) return ans;
  int mark1[20], mark2[20];
  cl(mark1, 0);
  cl(mark2, 0);
  rp(i,n) if ((msk>>i)&1) {
    mark1[v[i].st] = 1;
    mark2[v[i].nd] = 1;
  }
  ans = 0;
  rp(i,n) if (!((msk>>i)&1)) {
    if (!mark1[v[i].st] || !mark2[v[i].nd]) {
      ans = max(ans, go(msk|(1<<i)));
    } else {
      ans = max(ans, 1 + go(msk|1<<i));
    }
  }
  return ans;
}

void proc() {
  ids1.clear(), ids2.clear();
  sz1 = sz2 = 0;
  sc(n);
  rp(i,n) {
    scs(str);
    if (ids1.count(str) == 0) ids1[str] = sz1++;
    int a = ids1[str];
    scs(str);
    if (ids2.count(str) == 0) ids2[str] = sz2++;
    int b = ids2[str];
    v[i] = mp(a,b);
  }
  cl(pd,-1);
  printf("Case #%d: %d\n", cas++, go(0));
}

int main() {
  int t; sc(t);
  while (t--) {
    proc();
  }
  return 0;
}






