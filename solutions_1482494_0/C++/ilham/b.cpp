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
const int MAXN = 1024;
const int MAXM = 59049; // 3 ^ 10

int n, n2;
pii s[MAXN];
int done[MAXN];
int visit[MAXM];
int click[MAXN];
int best = 2 * MAXN;

int encode()
{
  int i, j = 0;
  FOR(i, n) j = j * 3 + done[i];
  return j;
}

void recurse(int c, int k)
{
  int i, j;

  if (c == n2) { best = min(best, k); }
  else if ((k < best) && k < visit[j = encode()])
  {
    visit[j] = k;
//    click[c] = k;
    FOR(i, n) if (done[i] != 2 && c >= s[i].SE)
    {
      j = done[i];
      done[i] = 2;
      recurse(c + (j == 1 ? 1 : 2), k + 1);
      done[i] = j;
    }
    FOR(i, n) if (done[i] == 0 && c >= s[i].FI && c < s[i].SE)
    {
      j = done[i];
      done[i] = 1;
      recurse(c + 1, k + 1);
      done[i] = j;
    }
  }
}

void doSmall()
{
  int i;
  n2 = 2 * n;
  ZERO(done);
  FOR(i, MAXM) visit[i] = 2 * MAXN;
//  FOR(i, MAXN) click[i] = 2 * MAXN;
  recurse(0, 0);
}

int main()
{
  int tc, t;
  int i, j, k;
  scanf("%d", &tc);
  FOR(t, tc)
  {
    scanf("%d", &n);
    FOR(i, n) scanf("%d %d", &s[i].FI, &s[i].SE);
    sort(s, s+n);
//    printf("%d\n", n);
    printf("Case #%d: ", t + 1);
    doSmall();
    if (best != 2 * MAXN) printf("%d\n", best);
    else printf("Too Bad\n");
    best = 2 * MAXN;
  }
  return 0;
}

