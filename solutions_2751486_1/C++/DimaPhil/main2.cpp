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
    ll ans = 0;
    vi good, cnts, lens, begs;
    vpii cs;
    good.pb(-1);
    for (int i = 0; i < len;)
    {
      if (!vowel(s[i]))
      {
        int now = i, i0 = i;
        while (now < len && !vowel(s[now]))
          ++now;
        int cnt = now - i0;
        if (cnt >= n)
        {
          cnts.pb(i0 - good.back() - 1);
          lens.pb(now - i0);
          good.pb(now - 1);
          cs.pb(mp(i0, now - 1));
          begs.pb(i0);
        }
        i = now;
      }
      else
        ++i;
    }
    if (sz(cnts))
      cnts.pb(len - good.back() - 1);
    /*for (int i = 0; i < sz(cnts) - 1; i++)
    {
      ans += (ll)(cnts[i] + 1) * (cnts[i + 1] + 1 + lens[i] - n);
      for (int j = 1; j < lens[i]; j++)
      {
        int r = j + n - 1;
        if (r >= lens[i])
          break;
        ans += cnts[i + 1] + lens[i] - r;
      }
    }*/
    for (int i = 0; i < len; i++)
    {
      //eprintf("Ans = %I64d\n", ans);
      int j = lower_bound(all(begs), i) - begs.begin();
      //eprintf("%d\n", j);
      if (!j && j < sz(begs))
      {
        ans += (len - cs[j].fst - n + 1);
        continue;
      }
      if (j - 1 >= 0 && cs[j - 1].snd >= i)
      {
        int have = cs[j - 1].snd - i + 1;
        if (have >= n)
        {
          int l = i + n - 1;
          ans += len - l;
          continue;
        }
      } 
      if (j < sz(begs))
        ans += len - cs[j].fst - n + 1;
    }
    printf("%I64d\n", ans);
  }        
  #ifdef LocalHost
    eprintf("Time = %.5lf\n", double(clock()) / CLOCKS_PER_SEC);
  #endif
  return 0;
}

