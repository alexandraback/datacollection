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

char x[128];
char board[4][4];
char res[4][128] = { "X won", "Draw", "O won", "Game has not completed" };

int check(char p)
{
  int i, j, ct;
  FOR(i, 4)
  {
    ct = 0;
    FOR(j, 4) if (board[i][j] == p || board[i][j] == 'T') ct++;
    if (ct == 4) return 1;
  }
  FOR(i, 4)
  {
    ct = 0;
    FOR(j, 4) if (board[j][i] == p || board[j][i] == 'T') ct++;
    if (ct == 4) return 1;
  }
  ct = 0;
  FOR(i, 4) if (board[i][i] == p || board[i][i] == 'T') ct++;
  if (ct == 4) return 1;
  ct = 0;
  FOR(i, 4) if (board[i][3 - i] == p || board[i][3 - i] == 'T') ct++;
  if (ct == 4) return 1;

  return 0;
}

int calc()
{
  int i, j;
  if (check('X')) return 0;
  if (check('O')) return 2;
  FOR(i, 4) FOR(j, 4) if (board[i][j] == '.') return 3;
  return 1;
}

int main()
{
  int n, i, j, k;

  gets(x);
  n = atoi(x);
  FOR(i, n)
  {
    FOR(j, 4)
    {
      gets(x);
      FOR(k, 4) board[j][k] = x[k];
    }
    gets(x);
    printf("Case #%d: %s\n", i + 1, res[calc()]);
  }
  return 0;
}

