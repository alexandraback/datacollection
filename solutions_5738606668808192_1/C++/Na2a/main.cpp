/* solution begins */

#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define pii pair<int, int>

#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int INF = (int) 1e9 + 7;
const int MAXN = (int) 2e5 + 7;

int n, k;
int a[33];

int s;
int ans[1010][33];
vector<ll> d[1010];

ll mod[111];
ll prod[111];

ll get(ll x) {
  for (int i = 2; i <= min(x - 1, 100ll); i++)
    if (x % i == 0)
      return i;
  return -1;
}

void rec(int pos) {
  if (s >= k)
    return;
  if (pos == n) {
    vector<ll> tmp;
    bool bad = 0;
    for (int base = 2; base <= 10; base++) {
      for (int i = 2; i <= 100; i++) {
        mod[i] = 0;
        prod[i] = 1;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 2; j <= 100; j++) {
          mod[j] = (mod[j] + a[i] * prod[j]) % j;
          prod[j] = (prod[j] * base) % j;
        }
      }
      ll x = -1;
      for (int i = 2; i <= 100; i++) {
        if (mod[i] == 0) {
          x = i;
          break;
        }
      }
      if (x == -1) {
        bad = true;
        break;
      }
      tmp.pb(x);
    }
    if (!bad) {
      for (int i = 0; i < n; i++)
        ans[s][i] = a[n - i - 1];
      for (auto it : tmp)
        d[s].pb(it);
      s++;
    }
  } else {
    for (int i = 0; i < 2; i++) {
      if ((pos == 0 || pos == n - 1) && !i)
        continue;
      a[pos] = i;
      rec(pos + 1);
    }
  }
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  int tests;
  scanf("%d", &tests);
  for (int cnum = 1; cnum <= tests; cnum++) {
    printf("Case #%d: \n", cnum);
    cin >> n >> k;
    rec(0);
    for (int c = 0; c < k; c++) {
      for (int i = 0; i < n; i++)
        printf("%d", ans[c][i]);
      for (auto it : d[c])
        printf(" %d", it);
      puts("");
    }
  }

  return 0;
}

/* solution ends */