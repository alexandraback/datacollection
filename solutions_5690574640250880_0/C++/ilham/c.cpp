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

int r, c, n, m, rem;
int zeroes[5];
char board[5][8];
int first;

inline int inside(int rr, int cc) { return rr >= 0 && rr < r && cc >= 0 && cc < c; }

void createBoard(int code)
{
  int i, j, k;
  FOR(i, n)
    board[i / c][i % c] = ((code >> i) % 2) ? '*' : '-';
}

void printBoard()
{
  int i;
  FOR(i, r) printf("%s\n", board[i]);
}

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1};

int canExpand(int rr, int cc)
{
  int i, a, b;
  FOR(i, 8)
  {
    a = rr + dx[i];
    b = cc + dy[i];
    if (inside(a, b) && board[a][b] == '*') return 0;
  }
  return 1;
}

void click(int rr, int cc)
{
  int i, a, b;
  if (first) { board[rr][cc] = 'c'; first = 0; }
  else board[rr][cc] = '.';
  if (canExpand(rr, cc))
    FOR(i, 8)
    {
      a = rr + dx[i];
      b = cc + dy[i];
      if (inside(a, b) && board[a][b] == '-') click(a, b);
    }
}

int count()
{
  int x = 0, i, j;
  FOR(i, r) FOR(j, c) if (board[i][j] == 'c' || board[i][j] == '.') x++;
  return x;
}

int can()
{
  int i, j, k;
  FOR(i, 1 << n) if (bitcount(i) == m) {
    createBoard(i);
//    printBoard();
//    break;
    FOR(j, r)
      FOR(k, c)
      {
        first = 1;
        if (board[j][k] == '-')
        {
          click(j, k);
          if (count() == rem) return 1;
          createBoard(i);
        }
      }
  }
  return 0;
}

int main()
{
  int t, tt, i, j;
  scanf("%d", &tt);
  FOR(t, tt)
  {
    scanf("%d %d %d", &r, &c, &m);
    n = r * c;
    rem = n - m;
    ZERO(board);

    printf("Case #%d:\n", t + 1);
    fprintf(stderr, "%d %d %d\n", r, c, m);
    if (rem == 1)
    {
      printf("c");
      FOR(j, c - 1) printf("*"); printf("\n");
      FOR(i, r - 1) { FOR(j, c) printf("*"); printf("\n"); }
    }
    else
    {
      if (can())
        FOR(i, r) printf("%s\n", board[i]);
      else printf("Impossible\n");
    }
  }

  return 0;
}

