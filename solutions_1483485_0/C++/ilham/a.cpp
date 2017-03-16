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

char x[] = "ynficwlbkuomxsevzpdrjgthaq";

int main()
{
  int i, j, k, t;
  int n;
  char z[128];

  gets(z);
  n = atoi(z);
  FOR(t, n)
  {
    gets(z);
    j = strlen(z);
    printf("Case #%d: ", t + 1);
    FOR(i, j)
    {
      if (z[i] == ' ') printf(" ");
      else
        FOR(k, 26) if (x[k] == z[i])
        {
          printf("%c", (char) (k + 'a'));
          break;
        }
    }
    printf("\n");
  }

/*  char x[128], y[128];
  int n, i, j, k;
  char t[256];
  int z[26], a[26];
  ZERO(z); ZERO(a);
  FOR(i, 256) t[i] = 'Z';
  gets(x);
  n = atoi(x);
  FOR(i, n)
  {
    gets(x); gets(y);
    k = strlen(x);
    FOR(j, k) { t[y[j]] = x[j]; z[y[j] - 'a'] = 1; a[x[j] - 'a'] = 1;}
  }
  FORI(i, 'a', 'z') printf("%c", t[i]);
  printf("\n");
  FOR(i, 26) if (!z[i]) printf("%c\n", i + 'a');
  FOR(i, 26) if (!a[i]) printf("%c\n", i + 'a'); */
  return 0;
}

