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

const int maxn = 200;

int n, m;
int need[maxn][maxn], now[maxn][maxn];

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
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        scanf("%d", &need[i][j]), now[i][j] = 100;
    for (int i = 0; i < n; i++)
    {
      int mx = 0;
      for (int j = 0; j < m; j++)
        mx = max(mx, need[i][j]);
      for (int j = 0; j < m; j++)
        now[i][j] = min(now[i][j], mx);
    }
    for (int i = 0; i < m; i++)
    {
      int mx = 0;
      for (int j = 0; j < n; j++)
        mx = max(mx, need[j][i]);
      for (int j = 0; j < n; j++)
        now[j][i] = min(now[j][i], mx);
    }
    bool ok = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        ok &= need[i][j] == now[i][j];
    printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}

