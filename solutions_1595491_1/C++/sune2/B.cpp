#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

int a[100];
int x[31][3];
int main() {
  REP(i, 31) {
    int a = i/3;
    int b = i-a*3;
    REP(j,3) {
      x[i][j] = a;
      if (b) x[i][j]++,b--;
    }
  }
  int T;
  cin >> T;
  REP(t,T) {
    int n,s,p;
    cin >>n>>s>>p;
    int ans = 0;
    REP(i, n) {
      cin >> a[i];
      if (x[a[i]][0] >= p) ans++;
      else {
        if (s > 0 && a[i] >= 2 && a[i] <= 28) {
          if (x[a[i]-1][0]+1 >= p) {
            ans++;
            s--;
          }
        }
      }
    }
    printf("Case #%d: %d\n", t+1, ans);
  }
}
