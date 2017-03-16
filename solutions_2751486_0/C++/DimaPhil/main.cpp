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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <ll> vll;
typedef vector <vll> vvll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <pii> vpii;

/* Template constants */

const int INF = 1e9;
const ll INFLONG = 1e18;
const double EPS = 1e-9;

/* Constants */

const int maxn = 1e6 + 100;

char s[maxn];
int n;

inline bool vowel(char c)
{
  return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  /* Precalc */

  int tests_count;
  scanf("%d\n", &tests_count);
  for (int test_number = 1; test_number <= tests_count; ++test_number)
  {
    printf("Case #%d: ", test_number);
    /* Clear all! */
    
    /* Solution */
    scanf(" %s", s);
    int len = strlen(s);
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
      int mx = 0, now = 0;
      bool last = 0;
      for (int j = i; j < len; j++)
      {
        if (!vowel(s[j]))
        {
          if (last)
            ++now;
          else
            now = 1, last = 1;
        }
        else
          now = 0, last = 0;
        if (mx < now)
          mx = now;
        if (mx >= n)
          ++ans;
      }
    }
    printf("%d\n", ans);
  }
  #ifdef LocalHost
    eprintf("Time = %.5lf\n", double(clock()) / CLOCKS_PER_SEC);
  #endif
  return 0;
}

