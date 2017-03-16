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

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  int tests;
  scanf("%d", &tests);
  for (int cnum = 1; cnum <= tests; cnum++) {
    printf("Case #%d: ", cnum);
    int k, c, s;
    cin >> k >> c >> s;
    if (s == k) {
      ll block = 1;
      for (int i = 1; i < c; i++)
        block *= k;
      for (int i = 0; i < k; i++) {
        cout << block * i + 1 << ' ';
      }
      cout << "\n";
    } else assert(0);
  }

  return 0;
}

/* solution ends */