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

const int maxn = 10;

int n;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
char a[maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int tests_count;
  scanf("%d\n", &tests_count);
  for (int test_number = 1; test_number <= tests_count; ++test_number)
  {
    printf("Case #%d: ", test_number);
    /* Clear all! */
    
    /*Solution*/
    n = 4;
    bool not_ended = 0;
    for (int i = 0; i < n; i++)
    {
      gets(a[i]);
      for (int j = 0; j < n; j++)
        not_ended |= a[i][j] == '.';
    }
    bool out = 0;
    for (int i = 0; i < 4 && !out; i++)
      for (int j = 0; j < 4 && !out; j++)
        for (int it = 0; it < 8; it++)
        {
          if (a[i][j] != 'X' && a[i][j] != 'O')
            continue;
          int x0 = i, y0 = j, x = x0, y = y0;
          int cnt = 0;
          while (x >= 0 && x < n && y >= 0 && y < n && (a[x][y] == a[x0][y0] || a[x][y] == 'T'))
            x += dx[it], y += dy[it], ++cnt;
          if (cnt == 4)
          {
            printf("%c won\n", a[x0][y0]);
            out = 1;
            break;
          }
        }
    if (!out)
      printf("%s\n", not_ended ? "Game has not completed" : "Draw");
    gets(a[0]);
  }
  return 0;
}

