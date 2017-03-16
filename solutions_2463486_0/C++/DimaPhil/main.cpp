#define TASKNAME "text"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
 
#define EPS 1e-9
#define INF int(1e9)
#define INFLONG (long long)(1e18)
#define sqr(a) ((a) * (a))
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri                               
#define mp make_pair
#define pb push_back
#define next dlkjdslfkdj
#define prev dsdflksdfjl
#define hash lkdfjldskfj
#define pi 3.1415926535897932384626433832795
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

const int maxc = 1e7 + 100;

inline bool is_palindrome(ll x)
{
  static int digits[20];
  int size = 0;
  while (x)
    digits[size++] = x % 10, x /= 10;
  int p1 = 0, p2 = size - 1;
  while (p1 < p2 && digits[p1] == digits[p2])
    ++p1, --p2;
  return p1 >= p2;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  /* Precalc */
  vi es;
  es.pb(0);
  for (int i = 1; i < maxc; ++i)
  {
    if (is_palindrome(i))
      es.pb(i);
  }
  eprintf("Precalc finished - %.5lf\n", double(clock()) / CLOCKS_PER_SEC);

  int tests_count;
  scanf("%d\n", &tests_count);
  for (int test_number = 1; test_number <= tests_count; ++test_number)
  {
    printf("Case #%d: ", test_number);
    /* Clear all! */
    
    /* Solution */
    ll L, R;
    scanf("%I64d%I64d", &L, &R);
    int l = 0, r = sz(es);
    while (l < r - 1)
    {
      int m = (l + r) >> 1;
      if ((ll)es[m] * es[m] < L)
        l = m;
      else
        r = m;
    }
    if (++l >= sz(es))
    {
      printf("0\n");
      continue;
    }
    ll x;
    int ans = 0;
    for (int i = l; i < sz(es) && (x = (ll)es[i] * es[i]) <= R; ++i)
      if (is_palindrome(x))
        ++ans;
    printf("%d\n", ans);
  }
  return 0;
}


