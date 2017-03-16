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
 
#define EPS (1e-9)
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
    fprintf(stderr, "Processing test %d:\n", test_number);
    /* Clear all! */
    
    /* Solution */
    std::string s;
    cin >> s;
    std::map<char, int> cnt;
    for (char c : s) {
      cnt[tolower(c)]++;
    }
    std::vector<int> dc(10, 0);
    dc[0] = cnt['z'];
    for (int i = 0; i < dc[0]; i++) {
      cnt['z']--;
      cnt['e']--;
      cnt['r']--;
      cnt['o']--;
    }
    dc[2] = cnt['w'];
    for (int i = 0; i < dc[2]; i++) {
      cnt['t']--;
      cnt['w']--;
      cnt['o']--;
    }
    dc[8] = cnt['g'];
    for (int i = 0; i < dc[8]; i++) {
      cnt['e']--;
      cnt['i']--;
      cnt['g']--;
      cnt['h']--;
      cnt['t']--;
    }
    dc[3] = cnt['h'];
    for (int i = 0; i < dc[3]; i++) {
      cnt['t']--;
      cnt['h']--;
      cnt['r']--;
      cnt['e']--;
      cnt['e']--;
    }
    dc[4] = cnt['r'];
    for (int i = 0; i < dc[4]; i++) {
      cnt['f']--;
      cnt['o']--;
      cnt['u']--;
      cnt['r']--;
    }
    dc[6] = cnt['x'];
    for (int i = 0; i < dc[6]; i++) {
      cnt['s']--;
      cnt['i']--;
      cnt['x']--;
    }
    dc[5] = cnt['f'];
    for (int i = 0; i < dc[5]; i++) {
      cnt['f']--;
      cnt['i']--;
      cnt['v']--;
      cnt['e']--;
    }
    dc[7] = cnt['v'];
    for (int i = 0; i < dc[7]; i++) {
      cnt['s']--;
      cnt['e']--;
      cnt['v']--;
      cnt['e']--;
      cnt['n']--;
    }
    dc[1] = cnt['o'];
    for (int i = 0; i < dc[1]; i++) {
      cnt['o']--;
      cnt['n']--;
      cnt['e']--;
    }
    dc[9] = cnt['i'];
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j < dc[i]; j++) {
        cout << i;
      }
    }
    cout << endl;
  }
  return 0;
}

