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

const int maxn = 1010;

struct Attack
{
  int time_attack;
  int tribe, day;
  Attack() {}
  Attack(int a, int b, int c) {time_attack = a, tribe = b, day = c;}
};

inline bool operator < (const Attack &a, const Attack &b) {return mp(a.time_attack, a.tribe) < mp(b.time_attack, b.tribe);}

int n;
int cnt[maxn];
int d[maxn];
int l[maxn], r[maxn];
int strength[maxn];
int delta_p[maxn], delta_s[maxn], delta_d[maxn];
                   
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
    scanf("%d", &n);
    vector <Attack> attacks;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d%d%d%d%d%d", &d[i], &cnt[i], &l[i], &r[i], &strength[i], &delta_d[i], &delta_p[i], &delta_s[i]);
      l[i] <<= 1;
      r[i] <<= 1;
      delta_p[i] <<= 1;
      for (int j = 0; j < cnt[i]; j++)
        attacks.pb(Attack(d[i] + delta_d[i] * j, i, j));
    }
    sort(all(attacks));
    int ans = 0;
    map <int, int> height;
    for (int i = 0; i < sz(attacks);)
    {
      int i0 = i;
      while (i < sz(attacks) && attacks[i].time_attack == attacks[i0].time_attack)
        ++i;
      map <int, int> need;
      for (int j = i0; j < i; j++)
      {
        int tribe = attacks[j].tribe;
        int day = attacks[j].day;
        int S = strength[tribe] + day * delta_s[tribe];
        int L = l[tribe] + delta_p[tribe] * day;
        int R = r[tribe] + delta_p[tribe] * day;
        //eprintf("Tribe = %d, Day = %d, S = %d, L = %d, R = %d\n", tribe, attacks[j].time_attack, S, L, R);
        bool success = 0;
        for (int it = L; it <= R; it++)
          if (height[it] < S)
          {
            success = 1;
            break;
          }
        ans += success;
        if (success)
          for (int it = L; it <= R; it++)
            need[it] = max(height[it], max(need[it], S));
      }
      for (map <int, int>::iterator it = need.begin(); it != need.end(); it++)
      {
        int h = it->fst;
        int val = it->snd;
        height[h] = val;
      }
      //eprintf("Attacks = %d\n", ans);
    }
    printf("%d\n", ans);
  }
  #ifdef LocalHost
    eprintf("Time = %.5lf\n", double(clock()) / CLOCKS_PER_SEC);
  #endif
  return 0;
}

