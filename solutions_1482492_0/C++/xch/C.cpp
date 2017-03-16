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

#define N 2005
#define A 255

int T;
int n;
int a;
double d;
double t[N];
double x[N];
double aa[A];
double answer[A];

#define POW(x) ((x)*(x))

int main() {
  freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);

  freopen("B-small-attempt1.in", "r", stdin);
  freopen("B-small-attempt1.out", "w", stdout);

  //freopen("C-large.in", "r", stdin);
  //freopen("C-large.out", "w", stdout);

  cin >> T;
  for (int cc = 1; cc <= T; cc++) {
    cin >> d;
    cin >> n >> a;
    zero(t);
    zero(x);
    zero(aa);
    zero(answer);
    for (int i = 0; i < n; i++) {
      cin >> t[i] >> x[i];
    }
    for (int i = 0; i < a; i++) {
      cin >> aa[i];
    }
    if (n == 1) {
      for (int i = 0; i < a; i++) {
        answer[i] = sqrtf(2.0 * d / aa[i]);
      }
    } else if (n == 2) {
      double y = (x[1] - x[0]) / t[1];
      for (int i = 0; i < a; i++) {
        double z = sqrtf(POW(y) + 2.0 * aa[i] * x[0]);
        double tmp = (y - z) / aa[i];
        if (tmp < 0)
          tmp = (y + z) / aa[i];
        double dd = 0.5 * aa[i] * POW(tmp);
        if (dd >= d) {
          answer[i] = sqrtf(2.0 * d / aa[i]);
        }
        else {
          double tmp2 = (x[1] - x[0]) / t[1];
          answer[i] = tmp + (d - dd) / tmp2;
        }
      }
    }
    cout << "Case #" << cc << ":" << endl;
    for (int i = 0; i < a; i++) {
      cout << answer[i] << endl;
    }
  }
  return 0;
}
