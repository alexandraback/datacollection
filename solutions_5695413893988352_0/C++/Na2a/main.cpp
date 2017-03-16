/* no greedy easy life */

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <ctime>

#define pii pair<int, int>
  
#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef double ld;

typedef vector<int> vi;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int INF = (int) 1e9 + 7;
const int MAXN = (int) 3e5 + 7;

string a, b;
int ans;
int len;

int pw[] = {1, 10, 100, 1000};

bool ok(string s, int x) {
  int i = len - 1;
  while (i >= 0 && (s[i] - '0' == x % 10 || s[i] == '?')) {
    i--;
    x /= 10;
  }
  return i == -1;
}

int main() {                                       
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif                                                                                          
  
  int t;
  cin >> t;
  for (int cs = 1; cs <= t; cs++) {
    printf("Case #%d: ", cs);
    cin >> a >> b;
    len = a.size();
    ans = INF;
    pii res;
    for (int l = 0; l < pw[len]; l++) {
      for (int r = 0; r < pw[len]; r++) {
        if (ok(a, l) && ok(b, r)) {
          if (abs(l - r) < ans || (abs(l - r) == ans && mp(l, r) < res)) {
            ans = abs(l - r);
            res = mp(l, r);
          }
        }
      }
    }
    for (int i = len - 1; i >= 0; i--)
      cout << res.f / pw[i] % 10;
    cout << ' ';
    for (int i = len - 1; i >= 0; i--)
      cout << res.s / pw[i] % 10;
    cout << endl;
  }
  return 0;
}