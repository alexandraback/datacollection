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

bool isvowels(char x) {
  if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
    return true;
  return false;
}

bool isconsecutive(string sub, int n) {
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < sub.size(); i++) {
    if (isvowels(sub[i])) {
      ans = cnt > ans ? cnt : ans;
      cnt = 0;
    } else {
      cnt++;
    }
  }
  ans = cnt > ans ? cnt : ans;
  return ans >= n;
}

LL solve(string name, int n) {
  LL ans = 0;
  for (int i = 0; i < name.size(); ++i) {
    for (int j = i + n; j <= name.size(); ++j) {
      if (isconsecutive(name.substr(i, j-i), n)) {
        //cout << i << " " << j << " " << name.substr(i, j-i) << endl;
       ans++;
      }
    }
  }
  //cout << endl;
  return ans;
}

int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);

  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);

  //freopen("X-large.in", "r", stdin);
  //freopen("X-large.out", "w", stdout);

  cin >> t;
  for (int cc = 1; cc <= t; cc++) {
    string name;
    int n;
    cin >> name >> n;
    cout << "Case #" << cc << ": " << solve(name, n) << endl;
  }
  return 0;
}
