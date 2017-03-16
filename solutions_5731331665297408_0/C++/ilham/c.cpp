#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;
typedef vector<LL> vl;
typedef vector<double> vd;

#define FOR(i,n) for (i = 0; i < (n); i++)
#define FORI(i,a,b) for (i = (a); i <= (b); i++)
#define FORD(i,a,b) for (i = (a); i >= (b); i--)
#define FOREACH(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, -1, sizeof(a))
#define SZ(a) (a.size())
#define MP(a, b) make_pair(a, b)
#define SHL(a,b) ((a) << (b))
#define SHR(a,b) ((a) >> (b))
#define FI first
#define SE second
#define PB push_back

template<class T> int bitcount(T a) { int x = 0; while (a) { x += (a & 1); a >>= 1; } return x; }
template<class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T sqr(T a) { return a * a; } // NOTE: T must be enough to save sqr!
inline int parity(LL a) { return __builtin_parityl(a); }
inline int parity(int a) { return __builtin_parity(a); }
template<class T> T s2type(string s) { T res; istringstream in(s); in >> res; return res; }
template<class T> string toString(T n) { ostringstream out; out << n; return out.str(); }

const double PI = acos(-1.0);
const double EPS = 1e-11;

int n, m;
pii zc[64];
int vis[64];
char ans[256];
int canReach[64];
int cta;
int st[64]; // use stack!
int cts;
int conn[64][64];

void recordAns(int x)
{
  ans[cta + 0] = (x / 10000) + '0';
  ans[cta + 1] = (x / 1000) % 10 + '0';
  ans[cta + 2] = (x / 100) % 10 + '0';
  ans[cta + 3] = (x / 10) % 10 + '0';
  ans[cta + 4] = x % 10 + '0';
  cta += 5;
}

void dumpStack()
{
  int i;
  fprintf(stderr, "Stack dump\n");
  FOR(i, cts) fprintf(stderr, "%d ", st[i]);
  fprintf(stderr, "\n");
}

int stillReachable()
{
  int i, j, k;
  queue<int> q;
  ZERO(canReach);
  FOR(i, cts) q.push(st[i]);
//  dumpStack();
  while (!q.empty()) {
    i = q.front();
    q.pop();
    FOR(j, n) if (conn[i][j] && !vis[j] && !canReach[j]) {
      q.push(j);
      canReach[j] = 1;
    }
  }
  FOR(i, n) if (!vis[i] && !canReach[i]) return 0;
  return 1;
}

void doit()
{
  int i, j, k, l, vertex, canMove;

  ZERO(ans); cta = 0;
  ZERO(vis);

  // sort the zipcodes
  sort(zc, zc + n);
//  FOR(i, n) printf("%d -- %d\n", zc[i].SE, zc[i].FI);

  // initialize the stack with the vertex with the least zipcode
  vis[zc[0].SE] = 1;
  st[0] = zc[0].SE;
  cts = 1;
  recordAns(zc[0].FI);
  canMove = 1;

  // try each vertex lexicographically
  while (canMove) {
    FOR(i, n) if (!vis[zc[i].SE]) {
      vertex = zc[i].SE;
      FORD(j, cts - 1, 0) {
        if (conn[st[j]][vertex]) break; // visit vertex via the latest possible element in the stack
      }
      if (j == -1) continue; // not found
//      fprintf(stderr, "trying %d\n", vertex);
      // save old info
      k = cts;
      l = st[j + 1];
      // try new part
      cts = j + 2;
      st[j + 1] = vertex;
      vis[vertex] = 1;
      if (stillReachable()) {
//        fprintf(stderr, "successful! %d\n", vertex);
        recordAns(zc[i].FI);
        break;
      }
      else { // reintroduce old stack
//        fprintf(stderr, "unsuccessful! %d\n", vertex);
        cts = k;
        st[j + 1] = l;
        vis[vertex] = 0;
      }
    }
    if (i == n) canMove = 0;
  }

  assert(cta / 5 == n); // sanity check
}

int main()
{
  int T, t, i, j, k;

  scanf("%d", &T);
  FOR(t, T)
  {
    scanf("%d %d", &n, &m);
    ZERO(conn);
    FOR(i, n) { scanf("%d", &j); zc[i] = MP(j, i); }
    FOR(i, m) { scanf("%d %d", &j, &k); conn[j - 1][k - 1] = 1; conn[k - 1][j - 1] = 1; }
    doit();
    printf("Case #%d: %s\n", t + 1, ans);
  }
  return 0;
}

