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
char board[64][64];
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
  int i, j, k;
  FOR(i, r) printf("%s\n", board[i]);
  // sanity check
/*  k = 0;
  FOR(i, r) FOR(j, c) if (board[i][j] == 'c' || board[i][j] == '.') k++;
  assert(rem == k);*/
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
    first = 1;
    if (board[r-1][c-1] == '-') click(r-1, c-1);
    if (count() == rem) return 1;
/*    FOR(j, r)
      FOR(k, c)
      {
        first = 1;
        if (board[j][k] == '-')
        {
          click(j, k);
          if (count() == rem) return 1;
          createBoard(i);
        }
      }*/
  }
  return 0;
}

void brute() {
  int i, j, k, l, a, b;
  ZERO(board);
  FOR(i, r) FOR(j, c) board[i][j] = '*';
  FORI(i, 2, c)
    FORI(j, 2, i)
      FORI(k, 2, j)
        if (rem >= i + j + k && (rem - (i + j + k)) % c == 0 && (rem - (i + j + k)) / c <= r - 3) {
          l = (rem - (i + j + k)) / c;
          fprintf(stderr, "%d %d %d %d\n", l, i, j, k);
          FOR(a, l) FOR(b, c) board[a][b] = '.';
          FOR(b, i) board[l][b] = '.';
          FOR(b, j) board[l + 1][b] = '.';
          FOR(b, k) board[l + 2][b] = '.';
          board[0][0] = 'c';
          return;
        }
  printf("Impossible\n");
}

int main()
{
  int t, tt, i, j, k, l;
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
    else if (r == 1 || c == 1) {
      printf("c"); rem--;
      FOR(j, c - 1) if (rem > 0) { printf("."); rem--; } else printf("*"); printf("\n");
      FOR(i, r - 1) { FOR(j, c) if (rem > 0) { printf("."); rem--; } else printf("*"); printf("\n"); }
    }
    else if (rem == 2 || rem == 3 || rem == 5 || rem == 7) {
      printf("Impossible\n");
    }
    else if (r == 2) {
      if (rem % 2) printf("Impossible\n");
      else {
        FOR(i, r) FOR(j, c) board[i][j] = '*';
        FOR(j, rem / 2) board[0][j] = board[1][j] = '.';
        board[0][0] = 'c';
        printBoard();
      }
    }
    else if (c == 2) {
      if (rem % 2) printf("Impossible\n");
      else {
        printf("c.\n"); rem -= 2;
        FOR(j, r - 1) if (rem > 0) { printf("..\n"); rem -= 2; } else printf("**\n");
      }
    }
    else if (rem % 2 == 0 && rem / 2 <= r) {
      FOR(i, r) FOR(j, c) board[i][j] = '*';
      FOR(i, rem / 2) board[i][0] = board[i][1] = '.';
      board[0][0] = 'c';
      printBoard();
    }
    else if (rem % 2 == 0 && rem / 2 <= c) {
      FOR(i, r) FOR(j, c) board[i][j] = '*';
      FOR(i, rem / 2) board[0][i] = board[1][i] = '.';
      board[0][0] = 'c';
      printBoard();
    }
    else if (rem % 3 == 0 && rem / 3 <= r) {
      FOR(i, r) FOR(j, c) board[i][j] = '*';
      FOR(i, rem / 3) board[i][0] = board[i][1] = board[i][2] = '.';
      board[0][0] = 'c';
      printBoard();
    }
    else if (rem % 3 == 0 && rem / 3 <= c) {
      FOR(i, r) FOR(j, c) board[i][j] = '*';
      FOR(i, rem / 3) board[0][i] = board[1][i] = board[2][i] = '.';
      board[0][0] = 'c';
      printBoard();
    }
/*    else if (r <= 6 && c <= 5) {
      if (can()) printBoard();
      else printf("Impossible\n");
    }*/
    else {
      brute();
      printBoard();
    }
  }

  return 0;
}

