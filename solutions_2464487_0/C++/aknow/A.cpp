#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

//#define debug(...)
#define debug printf

u64 root(u64 c, u64 t) {
  long double s2 = (long double)c * c + 8 * t;
  return (sqrt((long double)s2) - c) / 4;
}

u64 fit(u64 k, u64 c, u64 t) {
  if (2 * k + c == t / k) return k;

  //cout << k << " " << c << " " << t << endl;

  if (2 * k + c <= t / k) {
    while (2 * k + c <= t / k) k++;
    return k - 1;
  }

  if (2 * k + c >= t / k) {
    while (2 * k + c >= t / k) k--;
    return k;
  }
}


int main() {
  int caseN;
  scanf("%d", &caseN);

  for (int cc = 1; cc <= caseN; ++cc) {
    printf("Case #%d: ", cc);

    u64 r, t;
    cin >> r >> t;

    u64 c = 2 * r - 1;
    u64 k = fit(root(c, t), c, t);
    cout << k;

    printf("\n");
  }

  return 0;
}

