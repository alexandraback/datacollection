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

bool f (char c) {
  return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

char s[MAXN];
int d[MAXN];
int n, L;

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t; scanf("%d\n", &t);
  for (int test = 1; test <= t; test++) 
  {    
    scanf("%s %d\n", s, &n);
    L = int(strlen(s));

    int cnt = f(s[L - 1]) ? 1 : 0;
    if  (n == 1 && cnt == 1)
      d[L - 1] = L - 1;
    else
      d[L - 1] = -1;

    for (int i = L - 2; i >= 0; i--)
      if  (f(s[i])) {
        cnt++;
        if  (cnt >= n)
          d[i] = i + n - 1;
        else
          d[i] = d[i + 1];
      } else {
        d[i] = d[i + 1];
        cnt = 0;
      }

    ll ans = 0;
    for (int i = 0; i < L; i++)
      if  (d[i] != -1)
        ans += ll(L - d[i]);

    printf("Case #%d: %I64d\n", test, ans);
  }
  return 0;
}
