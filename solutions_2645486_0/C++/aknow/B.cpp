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

int E, R, N;
int v[10005];
int total_gain;

void read() {
  cin >> E >> R >> N;
  for (int i = 0; i < N; ++i)
    cin >> v[i];
}

void solve(int begin, int end, int begin_energy, int end_energy) {
  if (begin >= N) return;
  if (begin >= end) return;

  //printf("solve for %d - %d, energy %d, %d\n", begin, end, begin_energy, end_energy);

  int *pmax = max_element(v + begin, v + end);
  int kth = distance(v, pmax);

  // reserve all energy for kth.
  // check how much we have
  int have = min(begin_energy + R * (kth - begin), E);

  // check how much we should left
  int remain = max(0, end_energy - R * (end - kth));
  int use = have - remain;

  total_gain += use * v[kth];
  //printf("max = %d, use = %d\n", kth, use);

  solve(begin, kth, begin_energy, have);
  solve(kth + 1, end, remain + R, end_energy);
}

int main() {
  int caseN;
  scanf("%d", &caseN);

  for (int cc = 1; cc <= caseN; ++cc) {
    printf("Case #%d:", cc);

    read();
    total_gain = 0;
    solve(0, N, E, 0);

    printf(" %d\n", total_gain);
  }

  return 0;
}

