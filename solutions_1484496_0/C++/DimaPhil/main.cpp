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

vi a;
vector <pair <int, vi> > lists;

void go(int n, int now, int now_sum, vi now_v)
{
  if (now == n)
  {
    lists.pb(mp(now_sum, now_v));
    return;
  }
  now_sum += a[now];
  now_v.pb(a[now]);
  go(n, now + 1, now_sum, now_v);
  now_sum -= a[now];
  now_v.pop_back();
  go(n, now + 1, now_sum, now_v);
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
    printf("Case #%d:\n", test + 1);
    int n;
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(all(a));
    lists.clear();
    go(n, 0, 0, vi(0, 0));
    sort(all(lists));
    bool out = 0;
    for (int i = 0; i < sz(lists) - 1; i++)
      if (lists[i].fst == lists[i + 1].fst)
      {
        out = 1;
        for (int j = 0; j < sz(lists[i].snd); j++)        
          printf("%d%c", lists[i].snd[j], " \n"[j == sz(lists[i].snd) - 1]);
        for (int j = 0; j < sz(lists[i + 1].snd); j++)        
          printf("%d%c", lists[i + 1].snd[j], " \n"[j == sz(lists[i + 1].snd) - 1]);
        break;
      }
    if (!out)
      puts("Impossible");
  }
  return 0;
}
