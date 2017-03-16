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
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > 0)
      for (int i = 0; i < x; i++)
        printf("WE");
    else
      for (int i = 0; i < -x; i++)
        printf("EW");
    if (y > 0)
      for (int i = 0; i < y; i++)
        printf("SN");
    else
      for (int i = 0; i < -y; i++)
        printf("NS");
    printf("\n");
  }
  #ifdef LocalHost
    eprintf("Time = %.5lf\n", double(clock()) / CLOCKS_PER_SEC);
  #endif
  return 0;
}

