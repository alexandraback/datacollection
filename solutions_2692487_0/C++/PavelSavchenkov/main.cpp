#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = int(1e6) + 10;

bool cmp (int a, int b) {
  return a > b;
}

int a;
int b[MAXN];
int n;

void go () {
  while (n > 0 && b[n] > b[n - 1]) {
    b[n - 1] += b[n];
    n--;
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t; scanf("%d", &t);

  for (int test = 1; test <= t; test++) {
    scanf("%d %d", &a, &n);

    forn(i, n) scanf("%d", &b[i]);

        if  (a <= 1) {
      printf("Case #%d: %d\n", test, n);
      continue;  
    }

    sort(b, b + n, cmp);

    b[n] = a;

    int res = n; int add = 0;
    while (1) {
      go();

      res = min(res, n + add);

      if  (n == 0) break;

      while (b[n] <= b[n - 1]) {
        b[n] += b[n] - 1;
        add++;
      }
    }

    printf("Case #%d: %d\n", test, res); 
  }

  return 0;
}
