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
const int MAXN = 100005;

double p[MAXN];
double cor[MAXN];
int a, b;

double doSmall()
{
  int i, j, k;
  double ans, l;

  cor[0] = 1.0; // no chars written yet
  FOR(i, a) cor[i+1] = cor[i] * p[i];

  // enter right away
  ans = 1 + b + 1;

  FOR(i, a + 1) // start from j
  {
    l = cor[i] * (a - i + b - i + 1) + // right
        (1 - cor[i]) * (a - i + b - i + 1 + b + 1); // wrong
//    printf("%d: %lf\n", i, l);
    ans = min(ans, l);
  }

  return ans;
}

int main()
{
  int tc, t;
  int i, j, k;

  scanf("%d", &tc);
  FOR(t, tc)
  {
    scanf("%d %d", &a, &b);
    FOR(i, a) scanf("%lf", &p[i]);

    printf("Case #%d: ", t + 1);
    printf("%lf\n", doSmall());
  }
  return 0;
}

