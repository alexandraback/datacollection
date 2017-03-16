#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

#define forab(i,a,b) for(int i = (a); i <= (int)(b); i++)
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
// need declare it for vc, vc can not use <typeof> keyword
#define foreach(it,c) for(it = c.begin(); it != c.end(); ++it)

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define zero(a) memset(a, 0, sizeof(a))

#define pb push_back
#define mp make_pair

int t;
#define N 1005
int s[N][N];
int f[N];
int m[N];
bool yes;

void dfs(int i, int n) {
  for (int j = 1; j <= n; j++) {
    if (s[j][i] == 1) {
      f[j]++;
      if (f[j] > 1) {
        yes = true;
        return;
      }
      dfs(j, n);
    }
  }
}

int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);

  //freopen("A-small-attempt0.in", "r", stdin);
  //freopen("A-small-attempt0.out", "w", stdout);

  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);

  cin >> t;

  for (int cc = 1; cc <= t; cc++) {
    int n;
    cin >> n;
    zero(s);
    zero(m);
    for (int i = 1; i <= n; i++) {
      cin >> m[i];
      for (int j = 1; j <= m[i]; j++) {
        int tmp;
        cin >> tmp;
        s[i][tmp] = 1;
      }
    }
    
    yes = false;
    zero(f);
    for (int i = 1; i <= n; i++) {
      if (m[i] == 0) {
        dfs(i, n);
      }
      zero(f);
    }
    if (yes)
      cout << "Case #" << cc << ": " << "Yes" << endl;
    else
      cout << "Case #" << cc << ": " << "No" << endl;
  }
  return 0;
}
