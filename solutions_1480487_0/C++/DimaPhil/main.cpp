#define TASKNAME "text"

#include <cstdio>
#include <iostream>

#include <cmath>
#include <algorithm>
#include <functional>

#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>

#include <ctime>
#include <cassert>

#include <map>
#include <set>
#include <vector>
 
#define EPS 1e-9
#define INF int(1e9)
#define INFLONG (long long)(1e18)
#define sqr(a) ((a) * (a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#ifdef WIN32
  #define I64d "%I64d"
#else
  #define I64d "%lld"
#endif
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <ll> vl;
typedef vector <vl> vvl; 
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

inline bool check(const vi &a, double m, int id)
{
  int n = sz(a);
  double sum = 0;
  int s = 0;
  for (int i = 0; i < n; i++)
    s += a[i];
  for (int i = 0; i < n; i++)
  {
    if (i == id)
      continue;
    double t = (a[id] + s * m / 100.0 - a[i]) / s;
    sum += max(t, 0.0);
  }
  return (sum + m / 100 <= 1);
}

int main()
{
  #ifdef LocalHost
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif  
  int t;
  scanf("%d", &t);
  for (int test = 0; test < t; test++)
  {
    printf("Case #%d: ", test + 1);
    int n;
    scanf("%d", &n);
    vi s(n, 0);
    for (int i = 0; i < n; i++)
      scanf("%d", &s[i]);
    for (int i = 0; i < n; i++)
    {
      double l = 0, r = 100;
      for (int it = 0; it < 1000; it++)
      {
        double m = (l + r) / 2;
        //cout << m << " " << check(s, m, i) << '\n';
        if (check(s, m, i))
          l = m;
        else
          r = m;
      }
      printf("%.10lf%c", l, " \n"[i == n - 1]);
    }
  }
  return 0;
}
                