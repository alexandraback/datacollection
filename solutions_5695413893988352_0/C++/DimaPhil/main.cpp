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

int ans;
std::string ansA, ansB;

void go(std::string &a, std::string &b, int pos) {
  if (pos == a.size()) {
    int A = stoi(a);
    int B = stoi(b);
    if (abs(A - B) == ans) {
      if (A < stoi(ansA) || (A == stoi(ansA) && B < stoi(ansB))) {
        ansA = a;
        ansB = b;
      }
    }
    if (abs(A - B) < ans) {
      ans = abs(A - B);
      ansA = a;
      ansB = b;
    }
    return;
  }
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      bool xx = false, yy = false;
      if (a[pos] == '?') {
        a[pos] = char(i + '0');
        xx = true;
      }
      if (b[pos] == '?') {
        b[pos] = char(j + '0');
        yy = true;
      }
      go(a, b, pos + 1);
      if (xx) a[pos] = '?';
      if (yy) b[pos] = '?';
    }
  }
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
    fprintf(stderr, "Processing test %d:\n", test_number);
    /* Clear all! */
    
    /* Solution */
    std::string c, j;
    cin >> c >> j;
    ans = int(1e9);
    ansA = -1, ansB = -1;
    go(c, j, 0);
    cout << ansA << ' ' << ansB << '\n';
  }
  return 0;
}

