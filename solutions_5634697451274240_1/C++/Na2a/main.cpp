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

int solve(string s) {
  if (s.empty()) return 0;
  char t = s.back();
  string p = s.substr(0, (int) s.size() - 1);
  if (t == '+') {
    return solve(p);
  }
  if (t == '-') {
    //reverse(p.begin(), p.end());
    for (auto &it : p) {
      it = (it == '+') ? '-' : '+';
    }
    return solve(p) + 1;
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
    printf("Case #%d: ", cnum);
    string s;
    cin >> s;
    cout << solve(s) << "\n";
    cerr << "case " << cnum << " is done\n";
  }

  return 0;
}

/* solution ends */