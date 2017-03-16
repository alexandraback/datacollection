#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

const ld EPS = 1e-9;

/*
  1 -> 0
  i -> 1
  j -> 2
  k -> 3
  -k -> 3^4
*/
int small_mult[4][4] = {
  { 0,   1,   2,   3 },
  { 1, 0^4,   3, 2^4 },
  { 2, 3^4, 0^4,   1 },
  { 3,   2, 1^4, 0^4 }
};

int mult[8][8];

int my_sign(int a) {
  return (a & 4) ? -1 : +1;
}

int my_abs(int a) {
  if  (my_sign(a) == -1) {
    a ^= 4;
  }
  return a;
}

void precalc() {
  forn(a, 8) forn(b, 8) {
    int s = my_sign(a) * my_sign(b);
    int res = small_mult[my_abs(a)][my_abs(b)];
    if  (s == -1) {
      res ^= 4;
    }
    mult[a][b] = res;
  } 
}

const char all_ch[5] = "1ijk";

int code(char c) {
  forn(i, 4) {
    if  (all_ch[i] == c) {
      return i;
    }
  }
  assert(false);
  return -1;
}

const int MAXN = 2e5 + 10;
char buf[MAXN];
int a[MAXN];
int n;
int L;
ll X;

void read() {
  cin >> L >> X;
  scanf("\n");
  gets(buf);
  forn(i, L) {
    a[i] = code(buf[i]);
  }
}

bool old() {
  ll new_x = X;
  for (int i = 63; i >= 2; --i) {
    ll pw2 = 1ll << i;
    if  (new_x - pw2 >= 20) {
      new_x -= pw2;
    }
  }
  n = L * new_x;
  for (int i = L; i < n; ++i) {
    a[i] = a[i % L];
  }

  int mul = 0;
  bool was1 = false;
  bool was2 = false;
  forn(i, n) {
    mul = mult[mul][a[i]];
    if  (mul == 1) {
      was1 = true;
    }
    if  (was1 && mul == 3) {
      was2 = true;
    }
  }

  return was2 && mul == (0^4);
}

bool solve() {
  n = L * X;
  for (int i = L; i < n; ++i) {
    a[i] = a[i % L];
  }

  int mul = 0;
  bool was1 = false;
  bool was2 = false;
  forn(i, n) {
    mul = mult[mul][a[i]];
    if  (mul == 1) {
      was1 = true;
    }
    if  (was1 && mul == 3) {
      was2 = true;
    }
  }
  
  return was2 && mul == (0^4);
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  precalc();

  int T;
  scanf("%d", &T);
  forn(tt, T) {    
    read();
    printf("Case #%d: ", tt + 1);
    puts(old() ? "YES" : "NO");
    cerr << "ready " << tt + 1 << '\n';
  }

  return 0;
}
