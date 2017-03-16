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
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;

int c[30];

bool pal (ll a) {
  int len = 0;
  while (a > 0) { c[len++] = a % 10ll; a /= 10ll; }
  for (int i = 0; i < len / 2; i++)
    if  (c[i] != c[len - 1 - i]) return false;
  return true;
}

bool check (ll r, int st, int l) {
  int len = 0;
  while (st > 0) { c[len++] = st % 10; st /= 10; }
  reverse(c, c + len);

  int i = l == 1 ? len - 2 : len - 1; int j = len;
  while (i >= 0) c[j++] = c[i--];
  len = j;

  ll val = 0;
  for (int i = 0; i < len; i++) {
    val = val * 10ll + c[i];
  }

  if  (val * val <= r && pal(val * val)) return true;
  return false; 
}

int get (ll r) {
  int ans = 0;

  for (int a = 1; a < 10; a++) {
    ans += check(r, a, 0);
    ans += check(r, a, 1);

    for (int b = 0; b < 10; b++) {
      ans += check(r, a * 10 + b, 0);
      ans += check(r, a * 10 + b, 1);

      for (int c = 0; c < 10; c++) {
        ans += check(r, a * 100 + b * 10 + c, 0);
        ans += check(r, a * 100 + b * 10 + c, 1);

        for (int d = 0; d < 10; d++)
          ans += check(r, d + c * 10 + b * 100 + a * 1000, 1);
      }
    }
  }

  return ans;
}

int brut (ll l, ll r) {
  int ans = 0;
  for (ll i = 1; i * i <= r; i++)
    if  (l <= i * i && pal(i) && pal(i * i)) ans++;
  return ans;
}

ll a, b;
 
int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int t; scanf("%d", &t);
  for (int test = 1; test <= t; test++) {
    scanf("%I64d %I64d", &a, &b);
    printf("Case #%d: %d\n", test, max(0, get(b) - get(a - 1)));
  }
   
  return 0;
}
